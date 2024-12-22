#include "pch.h"
#include "MainJob.h"

void MainJob::Load()
{
	ImageConverter ic;
	ic.SetImagePath(path);
	ic.ConvertResized();
	RangeStretcher rs;
	rs.ConvertRange(ic.GetData(), true);
	pic = rs.GetStretched();
}

void MainJob::Proj()
{
	Projector proj;
	proj.SetData(pic);
	proj.SetRange(Min, Max);
	proj.SetStep(Step);
	proj.MakeProjections();
	projection = proj.GetProjection();
}

void MainJob::SetPath(CString& val)
{
	path = val;
}

void MainJob::SetMin(double val)
{
	Min = val;
}

void MainJob::SetMax(double val)
{
	Max = val;
}

void MainJob::SetStep(double val)
{
	Step = val;
}

vector<vector<double>> MainJob::GetSource()
{
	return pic;
}

vector<vector<double>> MainJob::GetProj()
{
	return projection;
}

void MainJob::main()
{
	if (path.IsEmpty())return;
	Load();
	Proj();
}
