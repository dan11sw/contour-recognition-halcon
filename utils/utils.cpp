#include "utils.h"

ImageContourInfo CreateContours(
	const HString& filePath,
	const HRect& rect,
	const HString& name,
	const std::function<void(const HImage&, HTuple&)> createShapeModelFunc
) {
	try {
		// Загрузка изображения
		HImage img;
		ReadImage(&img, filePath);

		// Получаем чёрно-белое изображеине
		HImage imgGray;
		Rgb1ToGray(img, &imgGray);

		HRegion ROI;
		HImage imgReduced;

		GenRectangle1(&ROI, rect.row1, rect.column1, rect.row2, rect.column2);
		ReduceDomain(imgGray, ROI, &imgReduced);

		/*HImage robertsImage;
		Roberts(imgGray, &robertsImage, "gradient_sum");*/

		HImage robertsImage;
		Roberts(imgReduced, &robertsImage, "gradient_sum");
		
		HTuple modelId;
		HXLDCont contours;

		if (createShapeModelFunc) {
			createShapeModelFunc(imgReduced, modelId);
			GetShapeModelContours(&contours, modelId, 1);

			return ImageContourInfo{ imgReduced, modelId, contours, name };
		}

		return ImageContourInfo{ imgReduced };
	}
	catch (const std::exception& e) {
		std::cerr << "Ошибка (" << __FILE__ << " -> " << __LINE__ << "): " << e.what() << std::endl;
		system("PAUSE");
		exit(0);
	}
	catch (...) {
		std::cerr << "Ошибка (" << __FILE__ << " -> " << __LINE__ << "): необработанное исключение." << std::endl;
		system("PAUSE");
		exit(0);
	}

	return ImageContourInfo{};
}

void SelectionRectForImage(
	const HString& filePath,
	const HRect& rect,
	const std::function<void(const HImage&, HTuple&)> createShapeModelFunc
) {
	try {
		// Загрузка изображения
		HImage img;
		ReadImage(&img, filePath);

		HImage imgGray;
		Rgb1ToGray(img, &imgGray);

		// EdgesSubPix()
		// edges_sub_pix(ImageReduced, Edges, 'canny', 1, 10, 20)
		// sobel_amp (GrayImage, EdgeAmplitude, 'sum_abs', 3)
		// edges_image(EdgeAmplitude, ImaAmp, ImaDir, 'canny', 1, 'nms', 20, 40)

		/*HImage robertsImage;
		Roberts(imgGray, &robertsImage, "gradient_sum");*/

		ImageContourInfo data = CreateContours(filePath, rect, "", createShapeModelFunc);

		if (createShapeModelFunc) {
			HTuple row;
			HTuple column;
			HTuple angle;
			HTuple score;

			FindShapeModel(data.img, data.modelId, 0, 360, 0.1, 1, 0.9, "least_squares", 0, 0.5, &row, &column, &angle, &score);
			HTuple mat;
			HXLDCont contoursAffine;

			VectorAngleToRigid(0, 0, 0, row, column, angle, &mat);
			AffineTransContourXld(data.contour, &contoursAffine, mat);

			Hlong width, height;
			img.GetImageSize(&width, &height);

			HWindow w(0, 0, width, height);

			w.SetColor("yellow");

			w.DispImage(data.img);
			w.DispXld(contoursAffine);

			w.Click();
		}
		else {
			Hlong width, height;
			img.GetImageSize(&width, &height);

			HWindow w(0, 0, width, height);

			w.SetColor("yellow");

			w.DispImage(data.img);

			w.Click();
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Ошибка (" << __FILE__ << " -> " << __LINE__ << "): " << e.what() << std::endl;
		system("PAUSE");
		exit(0);
	}
	catch (...) {
		std::cerr << "Ошибка (" << __FILE__ << " -> " << __LINE__ << "): необработанное исключение." << std::endl;
		system("PAUSE");
		exit(0);
	}
}

void MakeScreenshot(const HString& filePath, const HTuple& device) {
	try {
		HTuple acqHandle;
		OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "gray", -1, "false", "default", device, 0, -1, &acqHandle);
		GrabImageStart(acqHandle, -1);

		HImage imgCamera;
		GrabImage(&imgCamera, acqHandle);

		CloseFramegrabber(acqHandle);

		WriteImage(imgCamera, "jpeg", 0, filePath);
	}
	catch (const std::exception& e) {
		std::cerr << "Ошибка (" << __FILE__ << " -> " << __LINE__ << "): " << e.what() << std::endl;
		system("PAUSE");
		exit(0);
	}
	catch (...) {
		std::cerr << "Ошибка (" << __FILE__ << " -> " << __LINE__ << "): необработанное исключение." << std::endl;
		system("PAUSE");
		exit(0);
	}
}