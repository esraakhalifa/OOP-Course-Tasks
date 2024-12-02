#include <iostream>

using namespace std;

class complex{
private:
    double real;
    double img;
public:
    double getReal()
    {
        return real;
    }
    double getImg()
    {
        return img;
    }
    void setReal(double R)
    {
        real = R;
    }
    void setImg(double I)
    {
        img = I;
    }
    void print()
    {
w
        cout << endl;

    }
    };




    complex add(complex c1, complex c2)
    {
        complex result;
        double real = c1.getReal() + c2.getReal();
        result.setReal(real);
        double img = c1.getImg() + c2.getImg();
        result.setImg(img);
        return result;
    }
    complex subtract(complex c1, complex c2)
    {
        complex result;
        double real = c1.getReal() - c2.getReal();
        result.setReal(real);
        double img = c1.getImg() - c2.getImg();
        result.setImg(img);
        return result;
    }

int main()
{
    complex myComp1, myComp2, resultComp;
    double real1, img1, real2, img2;
    cout << "Enter the first complex number\n";
    cout <<"Enter the real part: ";
    cin >> real1;
    cout <<"Enter the imaginary part: ";
    cin >> img1;
    cout << "Enter the second complex number\n";
    cout <<"Enter the real part: ";
    cin >> real2;
    cout <<"Enter the imaginary part: ";
    cin >> img2;
    myComp1.setReal(real1);myComp1.setImg(img1);
    myComp2.setReal(real2);myComp2.setImg(img2);
    myComp1.print();
    myComp2.print();
    resultComp = add(myComp1, myComp2);
    resultComp.print();
    resultComp = subtract(myComp1, myComp2);
    resultComp.print();
    return 0;
}

