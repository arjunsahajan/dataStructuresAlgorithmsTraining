#include <iostream>

using namespace std;

int funDef(int);

int funDef(int num)
{
    if(num > 0)
    {
        return funDef(num - 1) + num;
    }

    return 0;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;
    cout << funDef(num) << endl;

    return 0;
}