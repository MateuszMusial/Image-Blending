#pragma once
#include "ImageDataProvider.h"
#include <fstream>
#include <iostream>

class ImageDataProviderFactory :
    public ImageDataProvider
{
public:
    Image load_image(const std::string& path) const override;
    void save_image(const std::string& path, const Image& img) const override;

};