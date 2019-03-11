#pragma once
#include "Picture.h"
#include "RGBTriple.h"
#include "shape.h"


class Diamond:public shape
{
public:
	Diamond();
	virtual ~Diamond();

	virtual void initializeShape(string stbSyntax);
	virtual void draw(Picture& picture);
	virtual void drawShadow(Picture& basePic);

private:

	//int width;
	//int height;
	int size;
	//bool isFilled;;
};
