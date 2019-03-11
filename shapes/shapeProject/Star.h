#pragma once
#include "Picture.h"
#include "RGBTriple.h"
#include "shape.h"


class Star :public shape
{
public:
	Star();
	virtual ~Star();

	virtual void initializeShape(string stbSyntax);
	virtual void draw(Picture& picture);
	virtual void drawShadow(Picture& basePic);

private:
	int size;
	//int Red, Green, Blue;
	
	//bool isFilled;
};
