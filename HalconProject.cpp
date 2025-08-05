#include "HalconProject.h"
#include "HalconCpp.h"
#include <string>
#include <functional>
#include "types/htypes.h"
#include "utils/utils.h"
#include <unordered_map>

using namespace HalconCpp;
using namespace std;

void displayImgToWindow(const HWindow& window, const HImage& image) {
	if (image.IsInitialized()) {
		window.DispImage(image);
	}
}

void createShapeModelFunc1(const HImage& img, HTuple& modelId) {
	CreateShapeModel(img, "auto", 0, 360, "auto", "auto", "use_polarity", "auto_contrast_hyst", "auto", &modelId);
}

void createShapeModelFunc2(const HImage& img, HTuple& modelId) {
	CreateShapeModel(img, "auto", 0, 360, "auto", "auto", "use_polarity", "auto_contrast_hyst", "auto", &modelId);
}

void createShapeModelFunc3(const HImage& img, HTuple& modelId) {
	CreateShapeModel(img, "auto", 0, 360, "auto", "auto", "use_polarity", "auto_contrast_hyst", "auto", &modelId);
}

#define TEST_1 0
#define TEST_2 0
#define TEST_3 0

#define SCREENSHOT 0

struct Data {
	std::vector<ImageContourInfo> contours;
	HTuple modelIds;
	
	Data(const std::vector<ImageContourInfo>& items, const HTuple& ids):
		contours{items}, modelIds{ids} {}
};

int main()
{
	setlocale(LC_ALL, "ru");

	{
#if (SCREENSHOT == 1)
		MakeScreenshot("C:\\Projects\\HalconTest\\33.jpeg", "[1]");
		return 0;
#endif // SCREENSHOT
	}

	HString pathImg1{ "C:\\Projects\\HalconTest\\1.jpeg" };
	HString pathImg11{ "C:\\Projects\\HalconTest\\11.jpeg" };
	HString pathImg12{ "C:\\Projects\\HalconTest\\12.jpeg" };
	HString pathImg13{ "C:\\Projects\\HalconTest\\13.jpeg" };

	HString pathImg2{ "C:\\Projects\\HalconTest\\2.jpeg" };
	HString pathImg21{ "C:\\Projects\\HalconTest\\21.jpeg" };
	HString pathImg22{ "C:\\Projects\\HalconTest\\22.jpeg" };
	HString pathImg23{ "C:\\Projects\\HalconTest\\23.jpeg" };

	HString pathImg3{ "C:\\Projects\\HalconTest\\3.jpeg" };
	HString pathImg31{ "C:\\Projects\\HalconTest\\31.jpeg" };
	HString pathImg32{ "C:\\Projects\\HalconTest\\32.jpeg" };
	HString pathImg33{ "C:\\Projects\\HalconTest\\33.jpeg" };

	/*SelectionRectForImage(pathImg2, HRect{150, 650, 750, 1200}, createShapeModelFunc2);
	return 0;*/

	/*SelectionRectForImage(pathImg4, HRect{270, 350, 482, 400});
	return 0;*/

	{
#if (TEST_1 == 1)
		SelectionRectForImage(pathImg1, HRect{ 120, 280, 270, 340 }, createShapeModelFunc1);
		return 0;
#endif // TEST_1

#if (TEST_2 == 1)
		SelectionRectForImage(pathImg2, HRect{ 120, 280, 270, 340 }, createShapeModelFunc2);
		return 0;
#endif // TEST_1

#if (TEST_3 == 1)
		SelectionRectForImage(pathImg3, HRect{ 170, 290, 210, 330 }, createShapeModelFunc3);
		return 0;
#endif // TEST_1
	}

	ImageContourInfo contourImg3 = CreateContours(
		pathImg3,
		HRect{ 80, 600, 800, 1300 },
		L"Деталь #3",
		createShapeModelFunc1
	);
	ImageContourInfo contourImg31 = CreateContours(
		pathImg31,
		HRect{ 80, 600, 800, 1400 },
		L"Деталь #3",
		createShapeModelFunc1
	);
	ImageContourInfo contourImg32 = CreateContours(
		pathImg32,
		HRect{ 80, 600, 800, 1350 },
		L"Деталь #3",
		createShapeModelFunc1
	);
	ImageContourInfo contourImg33 = CreateContours(
		pathImg33,
		HRect{ 80, 600, 800, 1350 },
		L"Деталь #3",
		createShapeModelFunc1
	);


	ImageContourInfo contourImg2 = CreateContours(
		pathImg2,
		HRect{ 150, 650, 750, 1200 },
		L"Деталь #2",
		createShapeModelFunc2
	);
	ImageContourInfo contourImg21 = CreateContours(
		pathImg11,
		HRect{ 200, 650, 700, 1100 },
		L"Деталь #2",
		createShapeModelFunc2
	);
	ImageContourInfo contourImg22 = CreateContours(
		pathImg22,
		HRect{ 200, 650, 750, 1200 },
		L"Деталь #2",
		createShapeModelFunc2
	);
	ImageContourInfo contourImg23 = CreateContours(
		pathImg23,
		HRect{ 150, 650, 750, 1200 },
		L"Деталь #2",
		createShapeModelFunc2
	);


	ImageContourInfo contourImg1 = CreateContours(
		pathImg1,
		HRect{ 200, 750, 700, 1000 },
		L"Деталь #1",
		createShapeModelFunc3
	);
	ImageContourInfo contourImg11 = CreateContours(
		pathImg11,
		HRect{ 200, 650, 700, 1100 },
		L"Деталь #1",
		createShapeModelFunc3
	);
	ImageContourInfo contourImg12 = CreateContours(
		pathImg12,
		HRect{ 200, 650, 700, 1200 },
		L"Деталь #1",
		createShapeModelFunc3
	);
	ImageContourInfo contourImg13 = CreateContours(
		pathImg12,
		HRect{ 200, 650, 750, 1200 },
		L"Деталь #1",
		createShapeModelFunc3
	);

	std::vector<ImageContourInfo> contours1{
		contourImg1,
		contourImg11,
		contourImg12,
		contourImg13,
	};

	HTuple modelIds1;

	for (const auto& item : contours1) {
		modelIds1.Append(item.modelId);
	}

	std::vector<ImageContourInfo> contours2{
		contourImg2,
		contourImg21,
		contourImg22,
		contourImg23,
	};

	HTuple modelIds2;

	for (const auto& item : contours2) {
		modelIds2.Append(item.modelId);
	}

	std::vector<ImageContourInfo> contours3{
		contourImg3,
		contourImg31,
		contourImg32,
		contourImg33,
	};

	HTuple modelIds3;

	for (const auto& item : contours3) {
		modelIds3.Append(item.modelId);
	}

	std::vector<Data> items{
		Data{contours1, modelIds1},
		Data{contours2, modelIds2},
		Data{contours3, modelIds3},
	};

	std::vector<ImageContourInfo> contours{
		contourImg1,
		contourImg12,
		contourImg13,
		contourImg2,
		contourImg22,
		contourImg23,
		contourImg3,
		contourImg32,
		contourImg33,
	};

	HImage img;
	ReadImage(&img, pathImg3);

	Hlong width, height;
	img.GetImageSize(&width, &height);

	HWindow w(0, 0, width, height);
	HTuple acqHandle;

	OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "gray", -1, "false", "default", "[1]", 0, -1, &acqHandle);
	GrabImageStart(acqHandle, -1);

	HImage imgCamera;
	while (true) {
		w.ClearWindow();

		GrabImageAsync(&imgCamera, acqHandle, -1);

		// roberts (GrayImage, ImageRoberts, 'gradient_sum')
		HImage robertsImage;
		Roberts(imgCamera, &robertsImage, "gradient_sum");

		w.DispImage(imgCamera);

		/*for (const auto& item : items) {
			HTuple rows;
			HTuple columns;
			HTuple angles;
			HTuple scores;
			HTuple models;

			FindShapeModels(robertsImage, item.modelIds, 0, 360, 0.8, 2, 0.9, "least_squares", 0, 0.1, &rows, &columns, &angles, &scores, &models);

			if (models.Length() > 0) {
				for (Hlong i = 0; i < models.Length(); i++) {
					HTuple mat;
					HXLDCont contoursAffine;

					VectorAngleToRigid(0, 0, 0, rows[i], columns[i], angles[i], &mat);
					AffineTransContourXld(item.contours[i].contour, &contoursAffine, mat);

					w.DispXld(contoursAffine);

					double percent = 0.0;

					std::wstringstream ss(to_number_precision(scores[i].D(), 2));
					ss >> percent;
					ss.clear();

					w.SetTposition(rows[i].D(), columns[i].D());
					w.WriteString((std::wstring(item.contours[i].name.TextW()) + L" (" + ss.str() + L"%)").c_str());
				}
			}
		}*/

		for (std::int32_t i = 0; i < contours.size(); i++) {
			ImageContourInfo& item = contours.at(i);
			HTuple row;
			HTuple column;
			HTuple angle;
			HTuple score;

			FindShapeModel(imgCamera, item.modelId, 0, 360, 0.25, 1, 0.5, "least_squares", 0, 0.9, &row, &column, &angle, &score);

			if (row.Length() == column.Length() &&
				column.Length() == angle.Length() &&
				angle.Length() == score.Length() &&
				score.Length() > 0
				) {
				HTuple mat;
				HXLDCont contoursAffine;

				VectorAngleToRigid(0, 0, 0, row, column, angle, &mat);
				AffineTransContourXld(item.contour, &contoursAffine, mat);

				w.DispXld(contoursAffine);

				double percent = 0.0;

				std::wstringstream ss(to_number_precision(score.D(), 2));
				ss >> percent;
				ss.clear();

				w.SetTposition(row.D(), column.D());
				w.WriteString((std::wstring(item.name.TextW()) + L" (" + ss.str() + L"%)").c_str());
			}
		}

		WaitSeconds(0.03);
	}
	
	CloseFramegrabber(acqHandle);

	w.Click();

	return 0;
}
