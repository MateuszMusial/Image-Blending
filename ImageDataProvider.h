#pragma once
#include "Image.h"
#include <string>

class ImageDataProvider
{
public:
	virtual Image load_image(const std::string& path) const = 0;
	virtual void save_image(const std::string& path, const Image& img) const = 0;

};

