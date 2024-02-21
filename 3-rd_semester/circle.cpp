#include <iostream>
#include <cmath>
#include <algorithm>
using std::cout, std::endl;

#include "circle.h"
#include "point.h"

Circle::Circle(const Point& acenter, float aradius)
{
    mCenter = acenter;
    mRadius = aradius;
    
}
Circle::Circle()
{
    cout << "Default Construtor" << endl;
    mRadius = 1;
    Point();
    

}
Circle::Circle (const Circle& circle)
{
    mCenter = circle.mCenter;
    mRadius = circle.mRadius;
}

float Circle::getRadius() const 
{
    cout << "Radius = ";
    return mRadius;
}
Point Circle::getCenter() const
{
    cout << "Center = ";
    return mCenter;
}
void Circle::setRadius(float Radius) 
{
    mRadius = std::clamp(Radius, 0.0f, Radius);
}
void Circle::setCenter(float ax, float ay) 
{
    this->mCenter.setX(ax);
    this->mCenter.setY(ay);
    cout << "Center has changed on " << mCenter;
}

float Circle::getArea() const
{
    float aradius = this->mRadius;
    float Area = 4 * 3.14 * aradius * aradius;
    return Area;
}

float Circle::getDistance(const Point& p)
{
    if (mCenter.distance(p) - mRadius < 0)
    {
        cout << "точка внутри окружности, ";
        return -(mCenter.distance(p) - mRadius);
    }
    cout << "точка вне окружности, ";
    return (mCenter.distance(p) - mRadius);
}

bool Circle::isColliding(const Circle& c)
{
    if (((this->mRadius < c.mRadius) and (mCenter.distance(c.mCenter) - mRadius < 0)) or ((this->mRadius < c.mRadius) and (mCenter.distance(c.mCenter) - mRadius < 0)))
    { // проверяем, может быть центр одной из окружностей внутри другой и её радиус меньше
        return 1;
    }
    else if (this->getDistance(c.mCenter) <= this->mRadius + c.mRadius) //проверка: если расстояние между радиусами меньше суммы радиусов
    {
        return 1;
    }
    return 0;		
}
void Circle::move(const Point& p)
{
    this->setCenter(p.getX(), p.getY());
}

int main()
{
	Circle a {{4, 1}, 3};
	Circle c {{8, 5}, 2};
	
	Circle b ({1, 2}, 6);
	
	b.setRadius(9);
	cout << b.getRadius() << " " << b.getCenter();
	
	cout << "Center b = " << b.getCenter() << " Area = " << b.getArea();
	Point point1 (4, 1);
	cout << "distance = " << a.getDistance(point1);
	cout << b.isColliding(a);
	b.move(point1);
	cout << "Center = " << b.getCenter();
}