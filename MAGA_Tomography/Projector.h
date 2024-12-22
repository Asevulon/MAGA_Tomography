#pragma once
#include<vector>
#include"gdiplus.h"
using namespace std;
using namespace Gdiplus;

class Projector
{
private:
	ULONG_PTR token;
	vector<vector<double>>source;
	vector<vector<double>>projection;
	
	double step = 0;
	double Min = 0;
	double Max = 0;
protected:
public:
	Projector();
	~Projector();
	void SetData(vector<vector<double>>& val);
	vector<vector<double>>GetProjection();
	void SetStep(double val);
	void SetRange(double left, double right);
	void MakeProjections();
};

