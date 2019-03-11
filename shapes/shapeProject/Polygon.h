#pragma once
#include "Picture.h"
#include "RGBTriple.h"
#include "shape.h"
#include <string>


class Polygon :public shape
{
public:
	Polygon();
	virtual ~Polygon();

	virtual void initializeShape(string stbSyntax);
	virtual void draw(Picture& picture);
	virtual void drawShadow(Picture& basePic);

private:
	int size;
	//bool isFilled;;
};