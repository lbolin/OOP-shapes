#pragma once
#include "Picture.h"
#include "RGBTriple.h"
#include "shape.h"
#include <string>


class Rectangle :public shape
{
public:
	Rectangle();
	virtual ~Rectangle();

	virtual void initializeShape(string stbSyntax);
	virtual void draw(Picture& picture);
	virtual void drawShadow(Picture& basePic);

private:
	/*RGBTriple color;
	coordinate startCordinate;*/
	//bool isFilled;
	coordinate endCordinate;
	int width;
	int height;
};

