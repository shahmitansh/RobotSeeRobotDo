#ifndef LIMBSEGMENT_H
#define LIMBSEGMENT_H

class Joint;

class LimbSegment
{
public:

	LimbSegment(Joint* tail, Joint* head)
		: m_tail(tail), m_head(head)
	{
	
	}

	Joint* getJointTail()
	{
		return m_tail;
	}

	Joint* getJointHead()
	{
		return m_head;
	}

private:
	Joint* m_tail;
	Joint* m_head;
};

#endif