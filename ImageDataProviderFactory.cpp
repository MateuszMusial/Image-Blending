#include "ImageDataProviderFactory.h"

Image ImageDataProviderFactory::load_image(const std::string& path)const 
{
    std::ifstream plik(path);
    if (!plik) {
        std::cout << "Brak pliku:" << path << std::endl;
        return Image();
    }
    std::string temp;
    getline(plik, temp);
    getline(plik, temp);

    int width, height;

    plik >> width >> height;
    Image obrazek(width, height);

    int colorMaximum;
    plik >> colorMaximum;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int red, green, blue;
            plik >> red;
            obrazek(x, y).r = (float)red / colorMaximum;
            plik >> green;
            obrazek(x, y).r = (float)red / colorMaximum;
            plik >> blue;
            obrazek(x, y).r = (float)red / colorMaximum;
        }
    }
    return obrazek;
}

void ImageDataProviderFactory::save_image(const std::string& path, const Image& img) const
{
    std::ofstream zap(path);
    if (!zap.is_open()) {
        std::cout << "Cant open the file!" << path << std::endl;
        return;
    }
    zap << "P3" << std::endl;
    zap << "# Created by GIMP" << std::endl;

    zap << img.getWidth() <<' '<< img.getHeigth();
    const int maxColor = 255;
        
    zap << maxColor << std::endl;

    for (int y = 0; y < img.getHeigth(); y++) {
        for (int x = 0; x < img.getWidth(); x++) {
            zap << img(x, y).r * maxColor << std::endl;
            zap << img(x, y).g * maxColor << std::endl;
            zap << img(x, y).b * maxColor << std::endl;
        }
    }


}
