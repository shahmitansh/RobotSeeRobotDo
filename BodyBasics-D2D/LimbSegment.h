#ifndef LIMBSEGMENT_H
#define LIMBSEGMENT_H

#include "support.h"

class LimbSegment
{
public:

	LimbSegment(BodyPart id, Coord start, Coord end)
		: m_id(id), m_start(start), m_end(end)
	{ }

	BodyPart id()
	{
		return m_id;
	}

	Coord start()
	{
		return m_start;
	}

	Coord end()
	{
		return m_end;
	}

private:
	BodyPart m_id;
	Coord m_start;
	Coord m_end;
};

#endif