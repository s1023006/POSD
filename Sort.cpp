#include "include/Sort.h"
#include "include/Shapes.h"

bool compare_Increasing_Perimeter (Shape *s1,Shape *s2)
{
	return s1 -> perimeter() < s2 -> perimeter();
}

bool compare_Decreasing_Perimeter (Shape *s1,Shape *s2)
{
	return s1 -> perimeter() > s2 -> perimeter();
}

bool compare_Increasing_Area (Shape *s1,Shape *s2)
{
	return s1 -> area() < s2 -> area();
}

bool compare_Decreasing_Area (Shape *s1,Shape *s2)
{
	return s1 -> area() > s2 -> area();
}

bool compare_Increasing_Compactness (Shape *s1,Shape *s2)
{
	double c1, c2;
	c1 = s1 -> area()/s1 -> perimeter();
	c2 = s2 -> area()/s2 -> perimeter();
	return c1 < c2;
} 