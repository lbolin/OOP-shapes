#pragma once
#include "Picture.h"
#include "RGBTriple.h"
#include "shape.h"
#include <string>

class Point : public shape
{
public:
	Point();
	virtual ~Point();

	virtual void initializeShape(string stbSyntax);
	virtual void draw(Picture& basePic);
	virtual void drawShadow(Picture& basePic);

private:

	//RGBTriple color;
	//coordinate startCordinate;
	//bool isFilled;
};


