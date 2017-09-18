#include <list>
#include "Shapes.h"

class Sort {

  public :static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList);//周長升冪排序

  public :static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList);//周長降冪排序

  public :static void sortByIncreasingArea(std::list<Shape *> * shapeList);//面積升冪排序

  public :static void sortByDecreasingArea(std::list<Shape *> * shapeList);
  //面積降冪排序
  public :static void sortByIncreasingCompactness(std::list<Shape *> * shapeList);//緊密度升冪排序(緊密度公式:周長^2/4*面積*圓周率)
  
};
