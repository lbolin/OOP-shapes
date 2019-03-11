#include "line.h"
#include "shape.h"
#include "Picture.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


Line::Line(){}

Line::~Line(){}

void Line::initializeShape(string lineText) {
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
	sin >> endCordinate.x;
	sin >> endCordinate.y;

}

void Line::draw(Picture& basePic)
{
	if (hasShadow)
	{
		drawShadow(basePic);
	}

	
	basePic.AddLine(startCordinate.x, startCordinate.y, endCordinate.x, endCordinate.y, color);
}

void Line::drawShadow(Picture& basePic)
{
	RGBTriple ShadowColor(100, 100, 100);
	basePic.AddLine(startCordinate.x - xOffset, startCordinate.y - yOffset, endCordinate.x -xOffset, endCordinate.y - yOffset, ShadowColor);
}


