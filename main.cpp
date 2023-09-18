#include <iostream>
#include <algorithm>
#include "point.h"
using std::cout, std::endl;


class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
	Circle(const Point& acenter, float aradius)
	{
		mCenter = acenter;
		mRadius = aradius;
		//cout << aradius << " " << mCenter;
	}
	Circle()
    {
        cout << "Default Construtor" << endl;
        mRadius = 1;
		Point();
		//cout << this->mCenter << " " << this->mRadius;

    }
	Circle (const Circle& circle)
	{
		mCenter = circle.mCenter;
		mRadius = circle.mRadius;
		//cout << "copy constructor" << mCenter << " " << mRadius;
	}

	float getRadius() const 
    {
        cout << "Radius = ";
		return mRadius;
    }
	Point getCenter() const
	{
		cout << "Center = ";
		return mCenter;
	}
	void setRadius(float Radius) 
    {
        mRadius = std::clamp(Radius, 0.0f, Radius);
    }
	void setCenter(float ax, float ay) 
    {
        this->mCenter.setX(ax);
		this->mCenter.setY(ay);
		cout << "Center has changed on " << mCenter;
    }

	float getArea() const
	{
		float aradius = this->mRadius;
		float Area = 4 * 3.14 * aradius * aradius;
		return Area;
	}

	float getDistance(const Point& p)
	{
		if (mCenter.distance(p) - mRadius < 0)
		{
			cout << "точка внутри окружности, ";
			return -(mCenter.distance(p) - mRadius);
		}
		cout << "точка вне окружности, ";
		return (mCenter.distance(p) - mRadius);
	}
	
	bool isColliding(const Circle& c)
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
	void move(const Point& p)
	{
		this->setCenter(p.getX(), p.getY());
	}
};

int main()
{
	// Point p = {7, -1};
	// Point q = {-4, 2};
	// cout << "Point p = " << p << endl;
	// cout << "Point q = " << q << endl;
	// cout << "p + q = " << p + q << endl;
	// Circle();
	Circle a {{4, 1}, 3};
	Circle c {{8, 5}, 2};
	//Circle b (a);
	Circle b ({1, 2}, 6);
	//Circle b (c);
	//b.getRadius();
	b.setRadius(9);
	cout << b.getRadius() << " " << b.getCenter();
	//b.setCenter(78, 98);
	cout << "Center b = " << b.getCenter() << " Area = " << b.getArea();
	Point point1 (4, 1);
	cout << "distance = " << a.getDistance(point1);
	cout << b.isColliding(a);
	b.move(point1);
	cout << "Center = " << b.getCenter();


	

	
/*
	Circle a {{4, 1}, 3};
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.getArea() << endl;
	cout << "Distance from point p to circle a = " << a.getDistance(p) << endl;



	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;



	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;
*/


}