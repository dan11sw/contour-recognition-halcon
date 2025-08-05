#pragma once

#include "HalconCpp.h"

using namespace HalconCpp;

struct HRect {
	HTuple row1;	// ������ ������
	HTuple column1; // ������ �����
	HTuple row2;	// ������ �����
	HTuple column2; // ������ ������

	HRect(const HTuple& r1, const HTuple& c1, const HTuple& r2, const HTuple& c2) :
		row1{ r1 }, column1{ c1 }, row2{ r2 }, column2{ c2 } {}
};

struct ImageContourInfo {
	HImage img;
	HTuple modelId;
	HXLDCont contour;
	HString name;

	ImageContourInfo() {}
	ImageContourInfo(const HImage& i) : img{ i } {}
	ImageContourInfo(const HImage& i, const HTuple& m, const HXLDCont& c, const HString& n) :
		img{ i }, modelId{ m }, contour{ c }, name{ n } {}
};
