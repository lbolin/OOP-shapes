#include "Rectangle.h"
#include "shape.h"
#include "Picture.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Rectangle::Rectangle() {}

Rectangle::~Rectangle() {}

void Rectangle::initializeShape(string lineText) {

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
	sin >> width;
	sin >> height;
}

void Rectangle::draw(Picture& basePic)
{
	if (hasShadow)
	{
		drawShadow(basePic);
	}

	basePic.AddLine(startCordinate.x, startCordinate.y, startCordinate.x + width, startCordinate.y, color);
	basePic.AddLine(startCordinate.x + width, startCordinate.y, startCordinate.x + width, startCordinate.y-height, color);
	basePic.AddLine(startCordinate.x + width, startCordinate.y - height, startCordinate.x, startCordinate.y-height, color);
	basePic.AddLine(startCordinate.x, startCordinate.y - height, startCordinate.x, startCordinate.y, color);

}

void Rectangle::drawShadow(Picture& basePic)
{
	RGBTriple ShadowColor(100, 100, 100);
	basePic.AddLine(startCordinate.x - xOffset, startCordinate.y - yOffset, (startCordinate.x + width) - xOffset, startCordinate.y - yOffset, ShadowColor);
	basePic.AddLine((startCordinate.x + width) - xOffset, startCordinate.y - yOffset, (startCordinate.x + width) - xOffset, (startCordinate.y - height) - yOffset, ShadowColor);
	basePic.AddLine((startCordinate.x + width) -xOffset, (startCordinate.y - height) - yOffset, startCordinate.x - xOffset, (startCordinate.y - height) - yOffset, ShadowColor);
	basePic.AddLine(startCordinate.x - xOffset, (startCordinate.y - height) - yOffset, startCordinate.x - xOffset, startCordinate.y - yOffset, ShadowColor);

}
	
