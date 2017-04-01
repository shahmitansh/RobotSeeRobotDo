#include "support.h"
#include "LimbSegment.h"

#include <math.h>
#include <fstream>
#include <ostream>

float angleBetweenLimbs(LimbSegment & pLimb, LimbSegment & cLimb)
{
	return 0; // STUB
}

void writeToFile(std::string msg)
{
	std::ofstream myfile("debug.txt", std::fstream::app);
	if (myfile.is_open())
	{
		myfile << msg << std::endl;
		myfile.close();
	}
}
