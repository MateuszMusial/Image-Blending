#pragma once
#include <vector>
#include <string>
#include <iostream>

class Image
{
public:
	struct Color {
		float r, g, b, a;
		std::string printVal(float f) {
			if (f > 0.75) return "#";
			if (f > 0.5) return ";";
			if (f > 0.25) return ".";
			return " ";
		}
		std::string print() {
			return printVal(r) + printVal(g) + printVal(b);
		};
	};
		std::vector<Color> data;
		int width, height;

			Image(int _width = 0, int _height = 0) :width(_width), height(_height) {
				data.resize(width * height);
			}

			Color& operator()(size_t x, size_t y) {
				return data[x + y * width];
			}

			Color operator()(size_t x, size_t y) const {
				return data[x + y * width];
			}

			const int getWidth() const { return width; }
			const int getHeigth() const { return height; }

			void print();
		};