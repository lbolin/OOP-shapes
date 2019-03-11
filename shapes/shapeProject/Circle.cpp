#include "Circle.h"
#include "shape.h"
#include "Picture.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Circle::Circle() {}

Circle::~Circle() {}

void Circle::initializeShape(string lineText) {
	
	istringstream sin(lineText);
	string junk;
	int red, green, blue;
	sin >> junk;
	sin >> red;
	color.Red = red;
	sin >> green;
	color.Green = green;
	sin >> blue;
	color.Blue = blue;
	sin >> startCordinate.x;
	sin >> startCordinate.y;
	sin >> radius;


}

void Circle::draw(Picture& basePic)
{
	//Algorithm found at https://en.wikipedia.org/wiki/Midpoint_circle_algorithm

	if (hasShadow)
	{
		drawShadow(basePic);
	}

	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	basePic.SetPixelColor(startCordinate.x, startCordinate.y, color);
	while (x >= y)
	{
		basePic.SetPixelColor(startCordinate.x + x, startCordinate.y + y, color);
		basePic.SetPixelColor(startCordinate.x + y, startCordinate.y + x, color);
		basePic.SetPixelColor(startCordinate.x - y, startCordinate.y + x, color);
		basePic.SetPixelColor(startCordinate.x - x, startCordinate.y + y, color);
		basePic.SetPixelColor(startCordinate.x - x, startCordinate.y - y, color);
		basePic.SetPixelColor(startCordinate.x - y, startCordinate.y - x, color);
		basePic.SetPixelColor(startCordinate.x + y, startCordinate.y - x, color);
		basePic.SetPixelColor(startCordinate.x + x, startCordinate.y - y, color);

		if (err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}

		if (err > 0)
		{
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
}


void Circle::drawShadow(Picture& basePic)
{
	RGBTriple ShadowColor(100, 100, 100);


	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	basePic.SetPixelColor(startCordinate.x, startCordinate.y, color);
	while (x >= y)
	{
		basePic.SetPixelColor((startCordinate.x + x) - xOffset, (startCordinate.y + y) - yOffset, ShadowColor);
		basePic.SetPixelColor((startCordinate.x + y) - xOffset, (startCordinate.y + x) - yOffset, ShadowColor);
		basePic.SetPixelColor((startCordinate.x - y) - xOffset, (startCordinate.y + x) - yOffset, ShadowColor);
		basePic.SetPixelColor((startCordinate.x - x) - xOffset, (startCordinate.y + y) - yOffset, ShadowColor);
		basePic.SetPixelColor((startCordinate.x - x) - xOffset, (startCordinate.y - y) - yOffset, ShadowColor);
		basePic.SetPixelColor((startCordinate.x - y) - xOffset, (startCordinate.y - x) - yOffset, ShadowColor);
		basePic.SetPixelColor((startCordinate.x + y) - xOffset, (startCordinate.y - x) - yOffset, ShadowColor);
		basePic.SetPixelColor((startCordinate.x + x) - xOffset, (startCordinate.y - y) - yOffset, ShadowColor);

		if (err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}

		if (err > 0)
		{
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
}
