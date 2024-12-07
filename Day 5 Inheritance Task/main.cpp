#include <iostream>

using namespace std;

class Base
{
private:
    int a;
    int b;
public:
    Base() {a = b = 0;}
    Base(int n){a=b=n;}
    Base(int x, int y){a = x; b = y;}
    void setA(int x) { a = x;}
    void setB(int y) { b = y;}
    int getA() {return a;}
    int getB() {return b;}
    int productAB() {return a * b;}
};

class Derived : public Base
{
private:
    int c;
public:
    Derived() : Base() { c = 0;}
    Derived(int n) : Base(n) { c = n;}
    Derived(int x, int y, int z) : Base(x, y) { c = z;}
    void setC(int z) { c = z;}
    int getC() {return c;}
    int productABC() {return this->productAB() * c;}
};
class SecondDerived : public Derived
{
private:
    int d;
public:
    SecondDerived() : Derived() { d = 0;}
    SecondDerived(int n) : Derived(n) {d = n;}
    SecondDerived(int x, int y, int m, int z) : Derived(x, y, m)
    {
        d = z;
    }
    void setD(int z) { d = z;}
    int getD() {return d;}
    int product()
    {
        return productABC() * d;
    }
};


int main()
{
    Derived derivedObj(3,7,2);
    Base baseObj(5, 4);
    SecondDerived secondDerivedObj(5,6,7,8);
    cout << "baseObj: " << baseObj.productAB() << endl; // 5 * 4 = 20
    cout << "derivedObj: " << derivedObj.productAB() << endl; // 3 * 7 = 21
    cout << "derivedObj: " << derivedObj.productABC() << endl; // 3 * 7 * 2 = 42
    cout << "secondDerivedObj: " << secondDerivedObj.productAB() << endl; // 5 * 6 = 30
    cout << "secondDerivedObj: " << secondDerivedObj.productABC() << endl; // 5 * 6 * 7 = 210
    cout << "secondDerivedObj: " << secondDerivedObj.product() << endl; // 5 * 6 * 7 * 8 = 1680

    return 0;
}
