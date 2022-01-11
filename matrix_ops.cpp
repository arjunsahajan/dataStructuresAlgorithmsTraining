#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct _MATRIX
{
    int *buffer;
    int col;
    int row;
    int size;
} _MAT_STRUCT;

void display_mat(_MAT_STRUCT*);
void input_mat(_MAT_STRUCT*);
int check_diagonal(_MAT_STRUCT*);
int check_lower_triangular(_MAT_STRUCT*);
int check_upper_triangular(_MAT_STRUCT*);
int get_using_row_major(_MAT_STRUCT*, int, int);
int set_using_row_major(_MAT_STRUCT*, int, int, int);
int check_symmetric(_MAT_STRUCT*);
int check_tri_diagonal(_MAT_STRUCT*);
int check_toeplitz(_MAT_STRUCT*);

int check_toeplitz(_MAT_STRUCT* mat_ptr)
{
    int k = 0;
    int q = 0;

    if(mat_ptr -> row != mat_ptr -> col)
    {
        return 0;
    }

    for(int i = 0; i < mat_ptr -> row; i++)
    {
        for(int j = 0; j < mat_ptr -> col; j++)
        {
            k = i;
            q = j;

            while(k < mat_ptr -> row && q < mat_ptr -> col)
            {
                if(mat_ptr -> buffer[i * mat_ptr -> col + j] != mat_ptr -> buffer[k * mat_ptr -> col + q])
                {
                    return 0;
                }

                k += 1;
                q += 1;
            }
        }
    }

    return 1;
}

int check_tri_diagonal(_MAT_STRUCT* mat_ptr)
{
    if(mat_ptr -> row != mat_ptr -> col)
    {
        return 0;
    }
    
	for(int i = 0; i < mat_ptr -> row; i++)
	{
		for(int j = 0; j < mat_ptr -> col; j++)
		{
			if(i == j && mat_ptr -> buffer[i * mat_ptr -> col + j] == 0)
			{	
				return 0;	
			}
			else if((i - j == 1 || j - i == 1) && mat_ptr -> buffer[i * mat_ptr -> col + j] == 0)
			{
				return 0;
			}
			else if((i - j > 1 || j - i > 1) && mat_ptr -> buffer[i * mat_ptr -> col + j] != 0)
			{
				return 0;
			}
		}
	}

	return 1;
}

int check_symmetric(_MAT_STRUCT* mat_ptr)
{
    if(mat_ptr -> row != mat_ptr -> col)
    {
        return 0;
    }

    for(int i = 0; i < mat_ptr -> row; i++)
    {
        for(int j = 0; j < mat_ptr -> col; j++)
        {
            if(mat_ptr -> buffer[i * mat_ptr -> col + j] != mat_ptr -> buffer[j * mat_ptr -> col + i])
            {
                return 0;
            }
        }
   }

    return 1;
}

int set_using_row_major(_MAT_STRUCT* mat_ptr, int i, int j, int val)
{
    mat_ptr -> buffer[i * mat_ptr -> col + j] = val;
}

int get_using_row_major(_MAT_STRUCT* mat_ptr, int i, int j)
{
    return mat_ptr -> buffer[i * mat_ptr -> col + j];
}

int check_upper_triangular(_MAT_STRUCT* mat_ptr)
{
    if(mat_ptr -> row != mat_ptr -> col)
    {
        return 0;
    }

    for(int i = 0; i < mat_ptr -> row; i++)
    {
        for(int j = 0; j < mat_ptr -> col; j++)
        {
            if(j < i)
            {
                if(mat_ptr -> buffer[i * mat_ptr -> col + j] != 0)
                {
                    return 0;
                }
            }
            else 
            {
                if(mat_ptr -> buffer[i * mat_ptr -> col + j] == 0)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int check_lower_triangular(_MAT_STRUCT* mat_ptr)
{
    if(mat_ptr -> row != mat_ptr -> col)
    {
        return 0;
    }

    for(int i = 0; i < mat_ptr -> row; i++)
    {
        for(int j = 0; j < mat_ptr -> col; j++)
        {
            if(j > i)
            {
                if(mat_ptr -> buffer[i * mat_ptr -> col + j] != 0)
                {
                    return 0;
                }
            }
            else 
            {
                if(mat_ptr -> buffer[i * mat_ptr -> col + j] == 0)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int check_diagonal(_MAT_STRUCT* mat_ptr)
{
    if(mat_ptr -> row != mat_ptr -> col)
    {
        return 0;
    }

    for(int j = 0; j < mat_ptr -> row; j++)
    {
        for(int k = 0; k< mat_ptr -> col; k++)
        {
            if(j != k && mat_ptr -> buffer[j * mat_ptr -> col + k] != 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

void input_mat(_MAT_STRUCT* mat_ptr)
{
    int row = 0;
    int col = 0;

    for(int i = 0; i < mat_ptr -> size; i++)
    {
        if(i == mat_ptr -> col * (row + 1))
        {
            row += 1;
            col = 0;
            cout << endl;
        }

        cout << "Enter element [" << row << ", " << col <<"]: "; 
        cin >> mat_ptr -> buffer[i];
        col += 1;
    }

    cout << endl;
}

void display_mat(_MAT_STRUCT* mat_ptr)
{
    for(int j = 0; j < mat_ptr -> row; j++)
    {
        for(int k = 0; k< mat_ptr -> col; k++)
        {
            cout << mat_ptr -> buffer[j * mat_ptr -> col + k] << " ";
        }

        cout << endl;
    }
    
    cout << endl;
}

int main()
{
    _MAT_STRUCT mat_struct_var;
    int i, j;

    cout << "Enter number of rows: ";
    cin >> mat_struct_var.row;

    cout << "Enter number of cols: ";
    cin >> mat_struct_var.col;

    cout << endl;

    mat_struct_var.size = mat_struct_var.row * mat_struct_var.col;

    mat_struct_var.buffer = (int*) malloc(mat_struct_var.size * sizeof(int));

    input_mat(&mat_struct_var);

    display_mat(&mat_struct_var);

    // if(check_diagonal(&mat_struct_var))
    // {
    //     cout << "Diagonal" << endl;
    // }
    // else 
    // {
    //     cout << "Not diagonal" << endl;
    // }

    if(check_lower_triangular(&mat_struct_var))
    {
        cout << "Lower triangular matrix" << endl;
        cout << "Number of non-zero elements (n(n + 1)) / 2: " << (mat_struct_var.row * (mat_struct_var.row + 1)) / 2 << endl;
        cout << "Number of zero elements (n ^ 2) - (n(n + 1)) / 2: " << (mat_struct_var.row * mat_struct_var.row) - ((mat_struct_var.row * (mat_struct_var.row + 1)) / 2) << endl;
    }
    else
    {
        cout << "Not lower triangular matrix" << endl;
    }

    if(check_upper_triangular(&mat_struct_var))
    {
        cout << "Upper triangular matrix" << endl;
        cout << "Number of non-zero elements (n(n + 1)) / 2: " << (mat_struct_var.row * (mat_struct_var.row + 1)) / 2 << endl;
        cout << "Number of zero elements (n ^ 2) - (n(n + 1)) / 2: " << (mat_struct_var.row * mat_struct_var.row) - ((mat_struct_var.row * (mat_struct_var.row + 1)) / 2) << endl;
    }
    else
    {
        cout << "Not upper triangular matrix" << endl;
    }

    if(check_symmetric(&mat_struct_var))
    {
        cout << "Symmetric matrix" << endl;
    }
    else
    {
        cout << "Not Symmetric matrix" << endl;
    }
	
    if(check_tri_diagonal(&mat_struct_var))
    {
	cout << "Tri diagonal" << endl;
    }
    else
    {
	cout << "Not tri diagonal" << endl;	
    }

    if(check_toeplitz(&mat_struct_var))
    {
        cout << "Toeplitz" << endl;
    }
    else 
    {
        cout << "Not toeplitz" << endl;
    }

    free(mat_struct_var.buffer);

    return 0;
}
