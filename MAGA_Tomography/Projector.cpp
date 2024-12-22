#include "pch.h"
#include "Projector.h"

Projector::Projector()
{
	GdiplusStartupInput si;
	GdiplusStartup(&token, &si, NULL);
}

Projector::~Projector()
{
	GdiplusShutdown(token);
}

void Projector::SetData(vector<vector<double>>& val)
{
	source = val;
}

vector<vector<double>> Projector::GetProjection()
{
	return projection;
}

void Projector::SetStep(double val)
{
	step = val;
}

void Projector::SetRange(double left, double right)
{
	Min = left;
	Max = right;
}

void Projector::MakeProjections()
{
	Bitmap bmp(source[0].size(), source.size());
	Bitmap bmp2(source[0].size(), source.size());
	double color = 0;
	for (int i = 0; i < source.size(); i++)
	{
		for (int j = 0; j < source[i].size(); j++)
		{
			color = source[i][j];
			bmp.SetPixel(j, i, Color(color, color, color));
			bmp2.SetPixel(j, i, Color(color, color, color));
		}
	}
	projection.clear();
	Graphics gr(&bmp2);
	vector<double> proj(source.size(), 0);
	double projval = 0;
	Color px = 0;
	Matrix m;
	

	for (double angle = Min; angle < Max; angle += step)
	{
		for (int i = 0; i < source.size(); i++)
		{
			projval = 0;
			for (int j = 0; j < source[i].size(); j++)
			{
				bmp2.GetPixel(j, i, &px);
				projval += px.GetRed();
			}
			proj[i] = projval;
		}
		projection.push_back(proj);
		gr.ResetTransform();
		m.Reset();
		m.RotateAt(angle, PointF(bmp.GetWidth() / 2., bmp.GetHeight() / 2.));
		gr.SetTransform(&m);
		gr.DrawImage(&bmp, 0, 0);
	}
}
