#include "point.h"
#include "shape.h"
#include "Picture.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Point::Point()
{
}
Point::~Point()
{
}

void Point::initializeShape(string lineText) {

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

}

void Point::draw(Picture& basePic)
{
	if (hasShadow)
	{
		drawShadow(basePic);
	}

	basePic.SetPixelColor(startCordinate.x, startCordinate.y, color);
}

void Point::drawShadow(Picture& basePic)
{
	
	//basePic.SetPixelColor(startCordinate.x + 3, startCordinate.y + 3, color);
}
