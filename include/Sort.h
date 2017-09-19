#include <list>
#include "Shapes.h"

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
	bool c1, c2;
	c1 = s1 -> area()/s1 -> perimeter();
	c2 = s2 -> area()/s2 -> perimeter();
	return c1 < s1;
} 

class Sort {

  public :static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList);//周長升冪排序
  {
	  Sort(shapeList,shapeList.size(),compare_Increasing_Perimeter);
	  return;
  }

  public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList);//周長降冪排序
  {
	  Sort(shapeList,shapeList.size(),compare_Decreasing_Perimeter);
	  return;
  }

  public :static void sortByIncreasingArea(std::list<Shape *> * shapeList);//面積升冪排序
  {
	  Sort(shapeList,shapeList.size(),compare_Increasing_Area);
	  return;
  }

  public :static void sortByDecreasingArea(std::list<Shape *> * shapeList);
  //面積降冪排序
  {
	  Sort(shapeList,shapeList.size(),compare_Decreasing_Area);
	  return;
  }
  
  public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeList);//緊密度升冪排序(緊密度公式:面積/周長)
  {
	  Sort(shapeList,shapeList.size(),compare_Increasing_Compactness);
	  return;
  }
  
};
