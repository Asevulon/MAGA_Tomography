#pragma once
#include"ImageConverter.h"
#include"RangeStretcher.h"
#include"Projector.h"
using namespace std;

class MainJob
{
private:
	vector<vector<double>>pic;
	vector<vector<double>>projection;
	CString path;

	double Min = 0;
	double Max = 0;
	double Step = 0;

protected:
	void Load();
	void Proj();
public:
	void SetPath(CString& val);
	void SetMin(double val);
	void SetMax(double val);
	void SetStep(double val);
	vector<vector<double>>GetSource();
	vector<vector<double>>GetProj();

	void main();
};

