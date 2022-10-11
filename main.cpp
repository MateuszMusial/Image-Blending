#include <iostream>
#include "ImageDataProviderFactory.h"

int main()
{
    ImageDataProviderFactory fabryka;
    Image wczytany = fabryka.load_image("C:\\Users\\KCRQ48\\source\\repos\\Image Blending\\CodeCool.ppm");
    wczytany.print();
    Image obrazek(20, 20);
    obrazek(0, 0).r = 1;
    obrazek(2, 3).g = 0.5;
    obrazek(2, 3).b = 1;

    fabryka.save_image("C:\\Users\\KCRQ48\\source\\repos\\Image Blending\\CodeCool-zap.ppm",obrazek);
  
}
