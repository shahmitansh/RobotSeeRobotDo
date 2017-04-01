#ifndef LIMB_COLLECTION_H
#define LIMB_COLLECTION_H

#include "support.h"
#include <Kinect.h>

class LimbSegment;

class LimbCollection
{
public:
	// takes in array of joints
	LimbCollection(Joint * joints[]);

	~LimbCollection();

	int angleOf(JointPart myJoint);

	void saveAngles(JointPart jnt);

private:
	// array of pointers to limbs as there is no default constructor
	LimbSegment **m_myLimbs;
};

#endif // !LIMB_COLLECTION_H
