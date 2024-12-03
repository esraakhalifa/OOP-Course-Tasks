/*#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X= x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
typedef struct Employee
{
    char ID[5];
    char Age[10];
    char salary[10];
    char Name[20];
}Employee;
template <typename T> class Stack{

private:
    int size;
    int top;
    T * items;
public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        items = new T [size];
    }
    int push(T data)
    {
        if(top == size - 1)
        {

            throw runtime_error("Stack is full.");
        }
        top++;
        items[top] = data;
        return 1;
    }
    T pop()
    {
        if (top == -1)
        {
            //return 0;
            throw runtime_error("Stack is already empty.");
        }
        T data = items[top];
        top--;
        return data;

    }
    void display()
    {
        int numItems = top + 1;
        for (int i = 0; i < numItems; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;

    }
    ~Stack()
    {
        delete [] items;

    }

};
/*int moveArrows(char click, int row, int col)
{
            if (click == 72) // up
            {
                if(row == 4) row =28;
                else row -=8;

            }
            else if ( click == 80) // down
            {
                if(row == 28) row =4;
                else row += 8;
            }
            setTextColor(stdout, TC_WHITE);
            if (row == 4){


                gotoxy(col, 0);
                puts("Line: 1");
                gotoxy(col,12);
                puts("Display");
                gotoxy(col,20);
                puts("Modify");
                gotoxy(col, 28);
                puts("Exit");
                gotoxy(col,row);
                setTextColor(stdout, TC_BLUE);
                puts("New");
            }
            else if ( row == 12){


                gotoxy(col, 0);
                puts("Line: 2");
                gotoxy(col,4 );
                puts("New");
                gotoxy(col,20);
                puts("Modify");
                gotoxy(col, 28);
                puts("Exit");
                gotoxy(col,row);
                setTextColor(stdout, TC_BLUE);
                puts("Display");
            }
            else if (row == 20){


                    gotoxy(col, 0);
                    puts("Line: 3");
                    gotoxy(col, 4);
                    puts("New");
                    gotoxy(col, 12);
                    puts("Display");
                    gotoxy(col, 28);
                    puts("Exit");
                    gotoxy(col,row);
                    setTextColor(stdout, TC_BLUE);
                    puts("Modify");

                }
            else {

                    setTextColor(stdout, TC_WHITE);
                    gotoxy(col, 0);
                    puts("Line: 4");
                    gotoxy(col, 4);
                    puts("New");
                    gotoxy(col, 12);
                    puts("Display");
                    gotoxy(col, 20);
                    puts("Modify");
                    gotoxy(col,row);
                    setTextColor(stdout, TC_BLUE);
                    puts("Exit");

                }
                return row;
}*/
/*
void renderMenu()
{
    system("cls");
    cout << "\033[32m" << "Push\n" << "\033[0m" << endl;
    cout << "Pop\n" << endl;
    cout << "PrintStack\n" << endl;

}
void moveArrows(char click)
{
    if (click == 72)
    {
        click = getch();
        if ()
    }

}

int main()
{
    int inputSize;
    cout << "Enter stack size:";
    cin >> inputSize;
    Stack<Employee> employeeStack(inputSize);
    renderMenu();
    char click;
    click = getch();
    if (click == -32)
    {
        moveArrows();
    }


    return 0;
}*/
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct Employee
{
    char ID[5];
    char Age[10];
    char salary[10];
    char Name[20];
} Employee;

template <typename T>
class Stack
{
private:
    int size;
    int top;
    T *items;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        items = new T[size];
    }

    int push(T data)
    {
        if (top == size - 1)
        {
            throw runtime_error("Stack is full.");
        }
        top++;
        items[top] = data;
        return 1;
    }

    T pop()
    {
        if (top == -1)
        {
            throw runtime_error("Stack is already empty.");
        }
        T data = items[top];
        top--;
        return data;
    }

    void display()
    {
        int numItems = top + 1;
        for (int i = 0; i < numItems; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] items;
    }
};


void renderMenu(int *selectedOption)
{
    system("cls");

    char *options[] = {"Push", "Pop", "PrintStack"};


    for (int i = 0; i < 3; i++)
    {
        if (i == *selectedOption)
        {
            cout << "\033[32m" << options[i] << "\033[0m" << endl;
        }
        else
        {
            cout << options[i] << endl;
        }
    }
}


void moveArrows(int selectedOption)
{
    char click = _getch();
    if (click == -32)
    {
        click = _getch();
        if (click == 72)
        {
            selectedOption--;
            if (*selectedOption < 0) selectedOption = 2;
        }
        else if (click == 80)
        {
            selectedOption++;
            if (selectedOption > 2) selectedOption = 0;
        }
    }
    //return selectedOption;
}

int main()
{
    int inputSize;
    cout << "Enter stack size: ";
    cin >> inputSize;
    Stack<Employee> employeeStack(inputSize);

    int selectedOption = NULL;
    selectedOption = 0;
    renderMenu(selectedOption);

    while (true)
    {
        moveArrows(selectedOption);
        renderMenu(selectedOption);

        if (_kbhit())
        {
            char key = _getch();
            if (key == 13)
            {
                system("cls");
                if (selectedOption == 0)
                {

                    cout << "You selected 'Push'!" << endl;
                }
                else if (selectedOption == 1)
                {

                    cout << "You selected 'Pop'!" << endl;
                }
                else if (selectedOption == 2)
                {

                    cout << "You selected 'PrintStack'!" << endl;
                }

            }
        }
    }

    return 0;
}

