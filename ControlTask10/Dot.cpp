#include "dot.h"
#include <math.h>
Dot::Dot()
{
	x = 0; y = 0;
}
Dot::Dot(double x, double y)
{
	this->x = x;
	this->y = y;
}
double Dot::distanceTo(Dot point1)
{
	return sqrt(pow((point1.x - x), 2) + pow((point1.y - y), 2));
}