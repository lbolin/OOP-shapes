#include "RightTriangle.h"
#include "shape.h"
#include "Picture.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "RGBTriple.h"


RightTriangle::RightTriangle() {}

RightTriangle::~RightTriangle() {}

void RightTriangle::initializeShape(string lineText) {
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

	//RGBTriple color(red,green,blue);

}

void RightTriangle::draw(Picture& basePic)
{
	if (hasShadow)
	{
		drawShadow(basePic);
	}

	//basePic.AddLine(startCordinate.x, startCordinate.y, startCordinate.x + width, startCordinate.y, color);
	basePic.AddLine(startCordinate.x, startCordinate.y, startCordinate.x, startCordinate.y - height, color);
	basePic.AddLine(startCordinate.x, startCordinate.y - height, startCordinate.x + width, startCordinate.y, color);
	basePic.AddLine(startCordinate.x + width, startCordinate.y, startCordinate.x, startCordinate.y, color);


}

void RightTriangle::drawShadow(Picture& basePic)
{
	RGBTriple ShadowColor(100,100,100);
	basePic.AddLine((startCordinate.x) - xOffset, (startCordinate.y) - yOffset, (startCordinate.x) - xOffset, (startCordinate.y - height) - yOffset, ShadowColor);
	basePic.AddLine((startCordinate.x) - xOffset, (startCordinate.y - height) - yOffset, (startCordinate.x + width) - xOffset, (startCordinate.y) -yOffset, ShadowColor);
	basePic.AddLine((startCordinate.x + width) - xOffset, (startCordinate.y) -yOffset, (startCordinate.x) -xOffset , (startCordinate.y) - yOffset, ShadowColor);
}
