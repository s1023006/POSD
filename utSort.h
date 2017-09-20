#ifndef EXP_H
#define EXP_H
#include<list>
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

Coordinate p0(0,0) ,t1p1(0,1) ,t1p2(1,0) ,t2p1(0,2) ,t2p2(2,0);

Rectangle r1(0,0,1,1), r2(0,0,2,2);

Circle c1(0,0,1), c2(0,0,2);

Triangle t1(p0 ,t1p1 ,t1p2), t2(p0 ,t2p1 ,t2p2);

std::list<Shape *>::iterator i,j;

std::list <Shape *> shapeList, ans;

void creatlist()
{
    shapeList.push_back(&r1);
    shapeList.push_back(&r2);
    shapeList.push_back(&c1);
    shapeList.push_back(&c2);
    shapeList.push_back(&t1);
    shapeList.push_back(&t2);
}

TEST (Sort, sortByIncreasingPerimeter) {
	creatlist();
	Sort::sortByIncreasingPerimeter(&shapeList);
	ans.push_back(&t1);
	ans.push_back(&r1);
	ans.push_back(&c1);
	ans.push_back(&t2);
	ans.push_back(&r2);
	ans.push_back(&c2);
	j=shapeList.begin();
	for(i=ans.begin();i!=ans.end();i++)
    {
        ASSERT_EQ(*i,*j);
        j++;
    }
	EXPECT_EQ(ans,shapeList);
	ans.clear();
	shapeList.clear();
}

TEST (Sort, sortByDecreasingPerimeter) {
    creatlist();
	Sort::sortByDecreasingPerimeter(&shapeList);
	ans.push_back(&c2);
	ans.push_back(&r2);
	ans.push_back(&t2);
	ans.push_back(&c1);
	ans.push_back(&r1);
	ans.push_back(&t1);
	j=shapeList.begin();
	for(i=ans.begin();i!=ans.end();i++)
    {
        ASSERT_EQ(*i,*j);
        j++;
    }
	ans.clear();
	shapeList.clear();
}

TEST (Sort, sortByIncreasingArea) {
    creatlist();
	Sort::sortByIncreasingArea(&shapeList);
	ans.push_back(&t1);
	ans.push_back(&r1);
	ans.push_back(&t2);
	ans.push_back(&c1);
	ans.push_back(&r2);
	ans.push_back(&c2);
	j=shapeList.begin();
	for(i=ans.begin();i!=ans.end();i++)
    {
        ASSERT_EQ(*i,*j);
        j++;
    }
	ans.clear();
	shapeList.clear();
}

TEST (Sort, sortByDecreasingArea) {
    creatlist();
	Sort::sortByDecreasingArea(&shapeList);
	ans.push_back(&c2);
	ans.push_back(&r2);
	ans.push_back(&c1);
	ans.push_back(&t2);
	ans.push_back(&r1);
	ans.push_back(&t1);
	j=shapeList.begin();
	for(i=ans.begin();i!=ans.end();i++)
    {
        ASSERT_EQ(*i,*j);
        j++;
    }
	ans.clear();
	shapeList.clear();
}

TEST (Sort, sortByIncreasingCompactness) {
    creatlist();
	Sort::sortByIncreasingCompactness(&shapeList);
	ans.push_back(&t1);
	ans.push_back(&r1);
	ans.push_back(&t2);
	ans.push_back(&r2);
	ans.push_back(&c1);
	ans.push_back(&c2);
	j=shapeList.begin();
	for(i=ans.begin();i!=ans.end();i++)
    {
        ASSERT_EQ(*i,*j);
        j++;
    }
	ans.clear();
	shapeList.clear();
}

#endif
