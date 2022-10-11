#include "Image.h"

void Image::print()
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << this->operator()(x, y).print();
        }
        std::cout << std::endl;
    }
}
