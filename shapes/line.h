#pragma once
#include "Picture.h"
#include "RGBTriple.h"
#include "shape.h"


class Line :public shape
{
public:
	Line();
	virtual ~Line();

	virtual void initializeShape(string stbSyntax);
	virtual void draw(Picture& picture);
	virtual void drawShadow(Picture& basePic);


private:
	/*RGBTriple color;
	coordinate startCordinate;*/
	coordinate endCordinate;
	
	//bool isFilled;;
};
