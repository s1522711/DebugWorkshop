#include "Point.h"
#include <iostream>

Point::Point()
{
	_coord = new int[2];
	_coord[0] = _coord[1] = 0;
}

Point::Point(int x, int y)
{
	_coord = new int[2];
	_coord[0] = x;
	_coord[1] = y;
}

Point::Point(const Point& other)
{
	// do hard copy using = operator
	*this = other;
}

Point::~Point()
{
	delete _coord;
}

Point& Point::operator=(const Point& other)
{
	if (this == &other) // self assignment - do nothing
		return *this;
	delete _coord;
	_coord = new int[2];
	memcpy(_coord, other._coord, 8); // 2 * sizeof(int) = 8 - they forgot to set it correctrly
	return *this;
}

int Point::getX() const 
{ 
	return _coord[0]; 
}

int Point::getY() const
{ 
	return _coord[1]; 
}


std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p._coord[0] << "," << p._coord[1] << ")";
	return os;
}
