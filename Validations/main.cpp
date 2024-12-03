#include <iostream>

using namespace std;
//validating input is integer ==>

int isInt(char arr[],int length)
{

    if (arr[0] == '-' && length == 1) return 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        int intArr = (int)arr[i];
        if ( (intArr == 45 && i != 0) || (intArr < 48 || intArr > 57) )
        {
            return 0;

        }
    }
    return 1;

}

//converting string input to integer ==>

int strtoI(char arr[])
{
    int digitNum = 0;int sign = 1;
    if (arr[0] == '-') sign = -1;
    for (int i = (sign == -1 ? 1 : 0); arr[i] != '\0'; i++)
    {
        digitNum = digitNum * 10 + (arr[i] - 48);
    }
    digitNum *= sign;
    return digitNum;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
