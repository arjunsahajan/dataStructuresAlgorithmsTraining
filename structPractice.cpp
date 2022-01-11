#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct _RECTANGLE
{
    int length;
    int breadth;
    char x;
} _RECT_OBJ;

_RECT_OBJ rect_struct_obj;

int main()
{
    rect_struct_obj.length = 1;
    rect_struct_obj.breadth = 2;

    cout << "length = " << rect_struct_obj.length << endl;
    cout << "breadth = " << rect_struct_obj.breadth << endl;
    cout << "struct size = " << sizeof(rect_struct_obj) << endl;
    return 0;
}