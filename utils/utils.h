#pragma once

#include <iostream>
#include <sstream>
#include <functional>
#include <iomanip>
#include "HalconCpp.h"
#include "../types/htypes.h"

using namespace HalconCpp;

/* Функция для создания контуров */
ImageContourInfo CreateContours(
	const HString& filePath,
	const HRect& rect,
	const HString& name,
	const std::function<void(const HImage&, HTuple&)> createShapeModelFunc
);

/* Функция для подбора четырёхугольника обрезающего деталь */
void SelectionRectForImage(
	const HString& filePath,
	const HRect& rect,
	const std::function<void(const HImage&, HTuple&)> createShapeModelFunc = {}
);

/* Функция для создания скриншота изображения с камеры */
void MakeScreenshot(
	const HString& filePath,
	const HTuple& device = "[0]"
);

template<typename T,
	typename = std::enable_if_t<std::is_arithmetic_v<T>>>
std::wstring to_number_precision(T number, std::streamsize precision) {
	if (std::is_floating_point<T>::value) {
		double empty;
		if (std::modf((double)number, &empty) == 0) {
			return std::to_wstring((long)number);
		}

		std::wstringstream stream;
		stream << std::fixed << std::setprecision(precision) << number;

		return stream.str();
	}

	return std::to_wstring(number);
}