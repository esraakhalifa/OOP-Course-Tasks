#include <iostream>
using namespace std;
class GeoShape
{
protected:
    float dimension1;
    float dimension2;
public:
    GeoShape() {dimension1 = dimension2 = 0;}
    GeoShape(float dimension)
    {
        dimension1 = dimension2 = dimension;
    }
    GeoShape(float dimension1, float dimension2)
    {
        this->dimension1 = dimension1;
        this->dimension2 = dimension2;
    }
    void setDimension1(float dimension)
    {
        dimension1 = dimension;
    }
    void setDimension2(float dimension)
    {
        dimension2 = dimension;
    }
    float getDimension1() {return dimension1;}
    float getDimension2() {return dimension2;}
    virtual float calculateArea() = 0;

};

class Triangle : public GeoShape
{
public:
    Triangle(float base, float height) : GeoShape(base,height)
    {

    }
    float calculateArea()
    {
        return 0.5 * dimension1 * dimension2;
    }
};

class Rect : public GeoShape
{
public:

    Rect(float x, float y) : GeoShape(x,y)
    {

    }
    float calculateArea()
    {
        return dimension1 * dimension2;
    }
};

class Circle : public GeoShape
{
public:
    Circle(float radius) : GeoShape(radius) {}
    void setRadius(float radius)
    {
        dimension1 = dimension2 = radius;
    }
    float getRadius() {return dimension1;}
    float calculateArea()
    {
        return 22.0/7 * dimension1 * dimension2;
    }
};

class Square : public Rect
{
public:

    Square(float x) : Rect(x, x) {}
    void setSquareDimension(float x)
    {
        dimension1 = dimension2 = x;
    }
    float getSquareDimension() {return dimension1;}
    float calculateArea()
    {
        return Rect::calculateArea();
    }
};
int main()
{
    cout << "Hello\n";
    Circle c1(5);
    // both methods accessible when the inheritance is public,
    // inaccessible when it's private though
    c1.setDimension1(5);
    c1.getDimension1();
    // accessible as it is a public member of the circle class
    c1.setRadius(5);
    // the exact same goes for the square class object
    Square s1(5);
    s1.setDimension1(5);
    s1.getDimension1();
    s1.setSquareDimension(5);
    return 0;
}
