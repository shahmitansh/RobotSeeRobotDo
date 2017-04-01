#include "LimbCollection.h"
#include "LimbSegment.h"
#include "support.h"
#include <Kinect.h>

std::pair<int, int> jointMobility_Elbow(30, 145);

std::pair<int, int> jointMobility_Shoulder(35, 150);

LimbCollection::LimbCollection(Joint * joints[])
{
	m_myLimbs = new LimbSegment*[NUM_BODYPARTS];

	Coord l_ShoulderCoord(joints[JointPart::L_SHOULDER_JOINT]->Position.X, joints[JointPart::L_SHOULDER_JOINT]->Position.Y);
	Coord l_ElbowCoord(joints[JointPart::L_ELBOW_JOINT]->Position.X, joints[JointPart::L_ELBOW_JOINT]->Position.Y);
	Coord l_WristCoord(joints[JointPart::L_WRIST_JOINT]->Position.X, joints[JointPart::L_WRIST_JOINT]->Position.Y);

	Coord r_ShoulderCoord(joints[JointPart::R_SHOULDER_JOINT]->Position.X, joints[JointPart::R_SHOULDER_JOINT]->Position.Y);
	Coord r_ElbowCoord(joints[JointPart::R_ELBOW_JOINT]->Position.X, joints[JointPart::R_ELBOW_JOINT]->Position.Y);
	Coord r_WristCoord(joints[JointPart::R_WRIST_JOINT]->Position.X, joints[JointPart::R_WRIST_JOINT]->Position.Y);

	Coord spineMid(joints[JointPart::SPINE_MID]->Position.X, joints[JointPart::SPINE_MID]->Position.Y);
	Coord spineShoulder(joints[JointPart::SPINE_SHOULDER]->Position.X, joints[JointPart::SPINE_SHOULDER]->Position.Y);

	m_myLimbs[BodyPart::L_UPPER_ARM] = new LimbSegment(BodyPart::L_UPPER_ARM, l_ShoulderCoord, l_ElbowCoord);
	m_myLimbs[BodyPart::L_LOWER_ARM] = new LimbSegment(BodyPart::L_LOWER_ARM, l_ElbowCoord, l_WristCoord);

	m_myLimbs[BodyPart::R_UPPER_ARM] = new LimbSegment(BodyPart::R_UPPER_ARM, r_ShoulderCoord, r_ElbowCoord);
	m_myLimbs[BodyPart::R_LOWER_ARM] = new LimbSegment(BodyPart::R_LOWER_ARM, r_ElbowCoord, r_WristCoord);

	m_myLimbs[BodyPart::TORSO] = new LimbSegment(BodyPart::TORSO, spineShoulder, spineMid);
}

LimbCollection::~LimbCollection()
{
	// deallocate values inside the array
	for (int i = 0; i < BodyPart::NUM_BODYPARTS; i++)
	{
		delete m_myLimbs[i];
	}

	// deallocate actual array
	delete[] m_myLimbs;
}

int LimbCollection::angleOf(JointPart myJoint)
{
	switch (myJoint)
	{
	case L_ELBOW_JOINT:
		return adjustedAngle(angleBetweenLimbs(*m_myLimbs[BodyPart::L_UPPER_ARM], *m_myLimbs[BodyPart::L_LOWER_ARM]), jointMobility_Elbow);
		break;
	case R_ELBOW_JOINT:
		return adjustedAngle(angleBetweenLimbs(*m_myLimbs[BodyPart::R_UPPER_ARM], *m_myLimbs[BodyPart::R_LOWER_ARM]), jointMobility_Elbow);
		break;
	case L_SHOULDER_JOINT:
		return adjustedAngle(angleBetweenLimbs(*m_myLimbs[BodyPart::TORSO], *m_myLimbs[BodyPart::L_UPPER_ARM]), jointMobility_Shoulder);
		break;
	case R_SHOULDER_JOINT:
		return adjustedAngle(angleBetweenLimbs(*m_myLimbs[BodyPart::TORSO], *m_myLimbs[BodyPart::R_UPPER_ARM]), jointMobility_Shoulder);
		break;
	case L_WRIST_JOINT:
	case R_WRIST_JOINT:
	case NUM_JOINTS:
	default:
		return -1;
		break;
	}
}

std::string LimbCollection::anglesToString()
{
	std::string myAngles; // LS,LE,RS,RE
	
	myAngles += std::to_string(this->angleOf(L_SHOULDER_JOINT)) + ","
			+ std::to_string(this->angleOf(L_ELBOW_JOINT)) + ","
			+ std::to_string(this->angleOf(R_SHOULDER_JOINT)) + ","
			+ std::to_string(this->angleOf(L_ELBOW_JOINT));

	return myAngles;
}

void LimbCollection::saveAngles(JointPart jnt)
{
	switch (jnt)
	{
	case L_ELBOW_JOINT:
		writeToFile("Angle of left elbow is: " + std::to_string(angleOf(jnt)));
		break;
	case R_ELBOW_JOINT:
		writeToFile("Angle of right elbow is: " + std::to_string(angleOf(jnt)));
		break;
	case L_SHOULDER_JOINT:
		writeToFile("Angle of left shoulder is: " + std::to_string(angleOf(jnt)));
		break;
	case R_SHOULDER_JOINT:
		writeToFile("Angle of right shoulder is: " + std::to_string(angleOf(jnt)));
		break;
	case L_WRIST_JOINT:
	case R_WRIST_JOINT:
	case NUM_JOINTS:
	default:
		break;
	}
}
