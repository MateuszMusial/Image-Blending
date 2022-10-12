#include <iostream>
#include <functional>
#include <vector>
#include <thread>
#include "Image.h"
#include "ImageDataProviderFactory.h"

void blendRegion(Image& output, const Image& imgA, const Image& imgB,
    std::function <Image::Color(Image::Color, Image::Color)> func
    ,int minX, int minY, int maxX, int maxY) {
    
    for (auto y = minY; y < maxY; y++) {
        for (auto x = minX; x < maxX; x++) {
            auto colorA = imgA(x, y);
            auto colorB = imgB(x, y);
            output(x, y) = func(colorA, colorB);
        }
    }
}

Image blendImages(const Image& imgA, const Image& imgB, int numThreads,
    std::function<Image::Color(Image::Color, Image::Color)> func) {

    auto outWidth = imgA.getWidth();
    auto outHeight = imgA.getHeigth();

    //TODO:  znalezienie obszaru wynikowego

    Image outImg(outWidth, outHeight);

    std::vector<std::thread> jobs;

    for (int i = 0; i < numThreads; i++) {
        jobs.push_back(std::thread(
            blendRegion,
            std::ref(outImg),
            std::ref(imgA),
            std::ref(imgB),
            func,
            0, 0, outWidth, outHeight));  //TODO: poprawic uzaleznic od watkow
    }

    for (int i = 0; i < numThreads; i++) {
        jobs[i].join();
    }

    return outImg;
}


Image::Color blendMultiply(Image::Color a, Image::Color b) {
    Image::Color res;

    res.r = a.r * b.r;
    res.g = a.g * b.g;
    res.b = a.b * b.b;
    return res;
}

int main()
{
    ImageDataProviderFactory fabryka;
  /*  Image wczytany = fabryka.load_image("C:\\Users\\KCRQ48\\source\\repos\\Image Blending\\CodeCool.ppm");
    wczytany.print();
    Image obrazek(20, 20);
    obrazek(0, 0).r = 1;
    obrazek(2, 3).g = 0.5;
    obrazek(2, 3).b = 1;

    fabryka.save_image("C:\\Users\\KCRQ48\\source\\repos\\Image Blending\\CodeCool-zap.ppm",obrazek);*/

    Image wczytany1 = fabryka.load_image("C:\\Users\\KCRQ48\\source\\repos\\Image Blending\\ziemia obraz.ppm");
    Image wczytany2 = fabryka.load_image("C:\\Users\\KCRQ48\\source\\repos\\Image Blending\\smok obraz.ppm");


    Image res = blendImages(wczytany1, wczytany2, 1,blendMultiply);
    fabryka.save_image("C:\\Users\\KCRQ48\\source\\repos\\Image Blending\\ziemiaSmok-zap.ppm", res);
    std::cout << "Done!";
  
}
