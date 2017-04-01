#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>

enum BodyPart { L_LOWER_ARM, R_LOWER_ARM, L_UPPER_ARM, R_UPPER_ARM, TORSO, NUM_BODYPARTS };

enum JointPart { L_SHOULDER_JOINT, L_ELBOW_JOINT, L_WRIST_JOINT, R_SHOULDER_JOINT, R_ELBOW_JOINT, R_WRIST_JOINT, SPINE_MID, SPINE_SHOULDER, NUM_JOINTS };

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

float crossProduct(Coord &left, Coord &right);

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