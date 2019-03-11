#pragma once
#include "Picture.h"
//#include "RGBTriple.h"

struct coordinate
{
	int x;
	int y;
};

class shape
{
public:
	shape();
	virtual ~shape();

	virtual void initializeShape(string stbSyntax) = 0;
	virtual void draw(Picture& picture) = 0 ;
	virtual void drawShadow(Picture& picture) = 0;
	static bool hasShadow;
	static int xOffset;
	static int yOffset;

protected:
	RGBTriple color;
	coordinate startCordinate;
	
	
	//bool isFilled;
};

