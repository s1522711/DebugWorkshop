#ifndef __SHAPE_H__
#define __SHAPE_H__

class Shape 
{
private:
	float _area;
	float _perimeter;

public:
	Shape();
	virtual float get_area(bool has_depth = false) const; // didnt use the same signature in the previous example

};

#endif	// __SHAPE_H__
