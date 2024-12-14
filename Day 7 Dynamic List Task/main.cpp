#include <iostream>


using namespace std;
class Base {
public:
    virtual void print() const = 0;
    virtual ~Base() = default;
};

class IntWrapper : public Base {
    int value;
public:
    IntWrapper(int v) : value(v) {}
    void print() const  { cout << value << "\n"; }
};

class FloatWrapper : public Base {
    float value;
public:
    FloatWrapper(float v) : value(v) {}
    void print() const  { cout << value << "\n"; }
};

class StringWrapper : public Base {
    string value;
public:
    void print() const  { cout << value << "\n"; }
};

int main() {


    return 0;
}
