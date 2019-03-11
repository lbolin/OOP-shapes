#pragma once
#include "Picture.h"
#include "RGBTriple.h"
#include "shape.h"


class RightTriangle:public shape
{
public:
	RightTriangle();
	virtual ~RightTriangle();

	virtual void initializeShape(string stbSyntax);
	virtual void draw(Picture& picture);
	virtual void drawShadow(Picture& basePic);

private:
	
	int width;
	int height;
	//int red, green, blue;
};
