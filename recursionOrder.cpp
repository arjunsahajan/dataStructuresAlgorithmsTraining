#include <iostream>

using namespace std;

void funDef(int);

void funDef(int num)
{
    if(num > 0)
    {
        funDef(num - 1);      //order changed  
        cout << num << endl;  
    }
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;
    funDef(num);

    return 0;
}