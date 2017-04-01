#include "support.h"
#include "LimbSegment.h"

#include <math.h>
#include <fstream>
#include <ostream>

float dotProduct(Coord &left, Coord &right)
{
	return ((left.X() * right.X()) + (left.Y() * right.Y()));
}

float magnitude(Coord &crd)
{
	return sqrtf(((crd.X())*crd.X()) + (crd.Y()*crd.Y()));
}

int angleBetweenLimbs(LimbSegment &left, LimbSegment &right)
{
	Coord u(left.end().X() - left.start().X(), left.end().Y() - left.start().Y());
	Coord v(right.end().X() - right.start().X(), right.end().Y() - right.start().Y());
	float numerator = dotProduct(u, v);
	float denominator = magnitude(u) * magnitude(v);
	int angle = (180 / 3.14159265) * acosf(numerator / denominator);
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
