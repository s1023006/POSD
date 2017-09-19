#include"include/Shapes.h"
#include<iostream>
int main()
{
    Circle *c=new Circle(0,10,10);
    std::cout << c->toString() << '\n';
    delete c;
    return 0;
}
