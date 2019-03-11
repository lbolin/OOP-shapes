#pragma once
#include "Picture.h"
#include "RGBTriple.h"
#include "shape.h"


class Circle :public shape
{
public:
	Circle();
	virtual ~Circle();

	virtual void initializeShape(string stbSyntax);
	virtual void draw(Picture& picture);
	virtual void drawShadow(Picture& basePic);

private:
	int radius;
	//bool isFilled;;
};