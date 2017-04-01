#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>

class LimbSegment;

class Coord
{
public:

	Coord(float x, float y)
		: m_x(x), m_y(y)
	{ }

	float X()
	{
		return m_x;
	}

	float Y()
	{
		return m_y;
	}

private:
	float m_x;
	float m_y;
	//	float m_z;
};

float dotProduct(Coord &left, Coord &right);

float magnitude(Coord &crd);

/*
Args: Two LimbSegment classes, each class has an orientation originating from the torso
(tail at torso, head away from torso)
Returns the angle between the two segments where the vectors are both oriented with
the heads pointing away from the torso.
*/
int angleBetweenLimbs(LimbSegment &left, LimbSegment &right);

/*
Writes msg to a debug.txt in debugging
*/
void writeToFile(std::string msg);

#endif