#include "LimbCollection.h"
#include "LimbSegment.h"
#include "support.h"
#include <string>
#include <Kinect.h>

std::pair<int, int> jointMobility_Elbow(-180, 180);

std::pair<int, int> jointMobility_Shoulder(-180, 180);

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
	std::string myAngles;
	
	int aLSJ = this->angleOf(L_SHOULDER_JOINT);
	int aLEJ = this->angleOf(L_ELBOW_JOINT);
	int aRSJ = this->angleOf(R_SHOULDER_JOINT);
	int aREJ = this->angleOf(R_ELBOW_JOINT);

	if (aLSJ < 0) myAngles += "-"; else myAngles += "+";
	if (abs(aLSJ) < 10) myAngles += "00" + std::to_string(abs(aLSJ));
	else if (abs(aLSJ) < 100) myAngles += "0" + std::to_string(abs(aLSJ));
	else myAngles += std::to_string(abs(aLSJ));

	if (aLEJ < 0) myAngles += "-"; else myAngles += "+";
	if (abs(aLEJ) < 10) myAngles += "00" + std::to_string(abs(aLEJ));
	else if (abs(aLEJ) < 100) myAngles += "0" + std::to_string(abs(aLEJ));
	else myAngles += std::to_string(abs(aLEJ));
	
	if (aRSJ < 0) myAngles += "-"; else myAngles += "+";
	if (abs(aRSJ) < 10) myAngles += "00" + std::to_string(abs(aRSJ));
	else if (abs(aRSJ) < 100) myAngles += "0" + std::to_string(abs(aRSJ));
	else myAngles += std::to_string(abs(aRSJ));
	
	if (aREJ < 0) myAngles += "-"; else myAngles += "+";
	if (abs(aREJ) < 10) myAngles += "00" + std::to_string(abs(aREJ));
	else if (abs(aREJ) < 100) myAngles += "0" + std::to_string(abs(aREJ));
	else myAngles += std::to_string(abs(aREJ));

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

bool LimbCollection::matches(std::string& configuration, int precision)
{
	std::string myAngles = this->anglesToString();
	int aLSJ_player = stoi(myAngles.substr(0, 4));
	int aLEJ_player = stoi(myAngles.substr(4, 4));
	int aRSJ_player = stoi(myAngles.substr(8, 4));
	int aREJ_player = stoi(myAngles.substr(12, 4));

	int aLSJ_robot = stoi(configuration.substr(0, 4));
	int aLEJ_robot = stoi(configuration.substr(4, 4));
	int aRSJ_robot = stoi(configuration.substr(8, 4));
	int aREJ_robot = stoi(configuration.substr(12, 4));

	return ((abs(aLSJ_robot - aLSJ_player) <= precision) &&
		(abs(aLEJ_robot - aLEJ_player) <= precision) &&
		(abs(aRSJ_robot - aRSJ_player) <= precision) &&
		(abs(aREJ_robot - aREJ_player) <= precision));
}

std::string LimbCollection::getRobotAngle(JointPart jnt)
{
	std::pair<int, int> JointRange(30, 150);
	
	int angle = 0;

	switch (jnt)
	{
		case L_ELBOW_JOINT:
			angle = adjustedAngle(((this->angleOf(L_ELBOW_JOINT) + 90 / 2) / 90) * 90, JointRange);
			writeToFile("LElbow is: " + std::to_string(this->angleOf(L_ELBOW_JOINT)));
			if (angle < 100)
				return (std::string("LE0") + std::to_string(angle));
			else
				return (std::string("LE") + std::to_string(angle));
			break;
		case R_ELBOW_JOINT:
			angle = adjustedAngle(((this->angleOf(R_ELBOW_JOINT) + 90 / 2) / 90) * 90, JointRange);
			writeToFile("RElbow is: " + std::to_string(this->angleOf(R_ELBOW_JOINT)));
			if (angle < 100)
				return (std::string("RE0") + std::to_string(angle));
			else
				return (std::string("RE") + std::to_string(angle));
			break;
		case L_SHOULDER_JOINT:
			angle = adjustedAngle(((this->angleOf(L_SHOULDER_JOINT) + 30 / 2) / 30) * 30, JointRange);
			if (angle < 100)
				return (std::string("LS0") + std::to_string(angle));
			else
				return (std::string("LS") + std::to_string(angle));
			break;
		case R_SHOULDER_JOINT:
			angle = adjustedAngle(((this->angleOf(R_SHOULDER_JOINT) + 30 / 2) / 30) * 30, JointRange);
			if (angle < 100)
				return std::string("RS0") + std::to_string(angle);
			else
				return std::string("RS") + std::to_string(angle);
			break;
		case L_WRIST_JOINT:
		case R_WRIST_JOINT:
		case NUM_JOINTS:
		default:
			return "None";
			break;
	}
	return "None";
}
