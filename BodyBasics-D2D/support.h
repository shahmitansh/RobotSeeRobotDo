#ifndef SUPPORT_H
#define SUPPORT_H

class LimbSegment;

/*
Args: Two LimbSegment classes, each class has an orientation originating from the torso
(tail at torso, head away from torso)
Returns the angle between the two segments where the vectors are both oriented with
the heads pointing away from the torso.
*/
float angleBetweenLimbs(LimbSegment& pLimb, LimbSegment& cLimb);

#endif