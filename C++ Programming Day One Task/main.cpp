#include <iostream>

using namespace std;

class complex{
private:
    double real;
    double img;
public:
    complex()
    {
        this->real = 0;
        this->img = 0;
    }
    complex(double real, double img)
    {
        this->real = real;
        this->img = img;
    }
    double getReal()
    {
        return real;
    }
    void setImg(double img)
    {
        this->img = img;
    }
     void setReal(double real)
    {
         this->real = real;
    }
    double getImg()
    {
        return img;
    }
    /*void setComplex(double real, double img)
    {
        this->real = real;
        this->img = img;
    }*/
    void print()
    {
        if (real != 0) cout << real;
        if (img > 0) cout << "+" << img << "i";
        else if (img < 0)  cout << img << "i";
        else if (img == 0 && real == 0) cout << "No Data!";
        cout << endl;
    }
        complex subtract(complex c1)
    {
        //complex result;
        this->real -= c1.real;
        //result.setReal(real);
        this->img -= c1.img;
        //result.setImg(img);
        //return result;
        return *this;
    }
        complex add(complex c1)
    {
        //complex result;
        this->real += c1.real;
        //result.setReal(real);
        this->img += c1.img;
        //result.setImg(img);
        //return result;
        return *this;
    }
    ~complex()
    {
        cout << "Goodbye..\n";
    }

    };




  /*  complex add(complex c1, complex c2)
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
    }*/

int main()
{
    //complex myComp1, myComp2, resultComp;
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
    complex myComp1(real1,img1), myComp2(real2,img2), resultComp;
    myComp1.print();
    myComp2.print();
    resultComp.add(myComp1);
    resultComp.add(myComp2);
    resultComp.print();
    resultComp.subtract(myComp2);
    resultComp.print();
    resultComp.print();
    return 0;
}
