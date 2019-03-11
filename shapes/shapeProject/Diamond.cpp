#include "Diamond.h"
#include "shape.h"
#include "Picture.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Diamond::Diamond() {}

Diamond::~Diamond() {}

void Diamond::initializeShape(string lineText) {
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
	sin >> size;
	

}

void Diamond::draw(Picture& basePic)
{
	if (hasShadow)
	{
		drawShadow(basePic);
	}

	basePic.AddLine((startCordinate.x), (startCordinate.y), (startCordinate.x + (2 * size)), (startCordinate.y + (6 * size)), color);
	basePic.AddLine((startCordinate.x + (2 * size)), (startCordinate.y + (6 * size)), (startCordinate.x + (4 * size)), (startCordinate.y), color);
	basePic.AddLine((startCordinate.x), (startCordinate.y), (startCordinate.x + (2 * size)), (startCordinate.y - (6 * size)), color);
	basePic.AddLine((startCordinate.x + (2 * size)), (startCordinate.y - (6 * size)), (startCordinate.x + (4 * size)), (startCordinate.y), color);

}
void Diamond::drawShadow(Picture& basePic)
{
	RGBTriple ShadowColor(100, 100, 100);
	basePic.AddLine((startCordinate.x) - xOffset, (startCordinate.y) - yOffset, (startCordinate.x + (2 * size)) - xOffset, (startCordinate.y + (6 * size))- yOffset, ShadowColor);
	basePic.AddLine((startCordinate.x + (2 * size)) - xOffset, (startCordinate.y + (6 * size)) - yOffset, (startCordinate.x + (4 * size)) - xOffset, (startCordinate.y) - yOffset, ShadowColor);
	basePic.AddLine((startCordinate.x) - xOffset, (startCordinate.y) - yOffset, (startCordinate.x + (2 * size)) - xOffset, (startCordinate.y - (6 * size)) - yOffset, ShadowColor);
	basePic.AddLine((startCordinate.x + (2 * size)) - xOffset, (startCordinate.y - (6 * size)) - yOffset, (startCordinate.x + (4 * size)) - xOffset, (startCordinate.y) - yOffset, ShadowColor);

}
