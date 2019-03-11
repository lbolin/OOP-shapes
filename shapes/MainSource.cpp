#include <iostream>
#include "Picture.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "shape.h"
#include "line.h"
#include "Rectangle.h"
#include "RightTriangle.h"
#include "Diamond.h"
#include "Star.h"
#include "Polygon.h"
#include "Circle.h"
#include "point.h"



using namespace std;


int main(int argc,char* argv[])
{
	if (argc == 2)
	{
		string fileName = argv[1];
		ifstream fin(fileName);

		if (fin)
		{
			string backText;
			getline(fin, backText);
			int red, green, blue;
			istringstream sin(backText);
			string junk;
			sin >> junk;
			sin >> red;
			sin >> green;
			sin >> blue;

			

			RGBTriple backColor(red, green, blue);
			Picture picture(800, 800, backColor);
			string Shadowline;

			getline(fin, Shadowline);

			if (Shadowline.find("Shadow") == 0)
			{
				shape::hasShadow = true;
				istringstream sin(Shadowline);
				string junk;
				sin >> junk;
				sin >> shape::xOffset;
				sin >> shape::yOffset;
			}

			vector<shape*> shapes;

			while (!fin.fail() && !fin.eof())
			{

				shape* p = nullptr;
				string lineText;
				getline(fin, lineText);

				if (lineText.find("line") == 0)
				{
					p = new Line();
					shapes.push_back(p);
				}
				else if (lineText.find("point") == 0)
				{
					p = new Point();
					shapes.push_back(p);
				}
				else if (lineText.find("rectangle") == 0)
				{
					p = new Rectangle();
					shapes.push_back(p);
				}
				else if (lineText.find("rightTriangle") == 0)
				{
					p = new RightTriangle();
					shapes.push_back(p);
				}
				else if (lineText.find("diamond") == 0)
				{
					p = new Diamond();
					shapes.push_back(p);
				}
				else if (lineText.find("star") == 0)
				{
					p = new Star();
					shapes.push_back(p);
				}
				else if (lineText.find("polygon") == 0)
				{
					p = new Polygon();
					shapes.push_back(p);
				}
				else if (lineText.find("circle" == 0))
				{
					p = new Circle();
						shapes.push_back(p);
				}
				else;
			
				p->initializeShape(lineText);

				for (shape* shape : shapes)
				{
					shape->draw(picture);
				}

				fileName = fileName.substr(0, fileName.length() - 3) + "bmp";
				picture.WriteToFile(fileName.c_str());
			}
		}
		else
		{
			cout << "Please Input File Name";
		}
		
	}

}