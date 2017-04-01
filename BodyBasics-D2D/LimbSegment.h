#ifndef LIMBSEGMENT_H
#define LIMBSEGMENT_H

class LimbJoint;

class LimbSegment
{
public:

	LimbSegment(LimbJoint* tail, LimbJoint* head)
		: m_tail(tail), m_head(head)
	{
	
	}

	LimbJoint* getJointTail()
	{
		return m_tail;
	}

	LimbJoint* getJointHead()
	{
		return m_head;
	}

private:
	LimbJoint* m_tail;
	LimbJoint* m_head;
};

#endif