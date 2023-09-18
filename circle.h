#include "point.h"
#pragma once


class Circle
{
private:
	Point mCenter;
	float mRadius;

public:

    Circle(const Point& acenter, float aradius);
    Circle();
    Circle (const Circle& circle);

    float getRadius() const ;
    Point getCenter() const;
    void setRadius(float Radius);
    void setCenter(float ax, float ay);
    float getArea() const;
    float getDistance(const Point& p);
    bool isColliding(const Circle& c);
    void move(const Point& p);
};
