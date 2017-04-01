#include "support.h"
#include "LimbSegment.h"

#include <math.h>
#include <algorithm>
#include <fstream>
#include <ostream>

float dotProduct(Coord &left, Coord &right)
{
	return ((left.X() * right.X()) + (left.Y() * right.Y()));
}

float crossProduct(Coord & left, Coord & right)
{
	return ((left.X()-right.Y()) - (left.Y()-right.X()));
}

float magnitude(Coord &crd)
{
	return sqrtf(((crd.X())*crd.X()) + (crd.Y()*crd.Y()));
}

int angleBetweenLimbs(LimbSegment &left, LimbSegment &right)
{
	Coord u(left.end().X() - left.start().X(), left.end().Y() - left.start().Y());
	Coord v(right.end().X() - right.start().X(), right.end().Y() - right.start().Y());

	float magU = magnitude(u);
	float magV = magnitude(v);
	float dotProd = dotProduct(u, v);
	int angle = (180 / 3.14159265) * acosf(dotProd / (magU * magV));
	return angle;
}

int adjustedAngle(int angle, std::pair<int, int> bounds)
{
	if (angle < bounds.first)
		return bounds.first;
	else if (angle > bounds.second)
		return bounds.second;
	else
		return angle;
}

void writeToFile(std::string msg)
{
	std::ofstream myfile("rsrdTest.txt", std::fstream::app);
	if (myfile.is_open())
	{
		myfile << msg << std::endl;
		myfile.close();
	}
}
