#include <iostream>

using namespace std;

void swapByValue(int x, int y)
{
    int temp;
    temp = x;
    x = y;

}
void swapByAddress(int *x, int *y)
{
    *x = *x - *y;
    *y = *y + *x;
    *x = *y - *x;
}
void swapByReference(int &x, int &y)
{
    x = x - y;
    y = y + x;
    x = y - x;
}
int main()
{

    int x = 5, y = 6;
    swapByValue(x,y);
    cout << x << " " << y <<"\n";
    swapByAddress(&x,&y);
    cout << x << " " << y <<"\n";
    swapByReference(x,y);
    cout << x << " " << y <<"\n";
    return 0;
}
