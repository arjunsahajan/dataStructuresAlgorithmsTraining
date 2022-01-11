#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <string.h>

using namespace std;

#define STRUCT_STR_ARR_LENGTH 2

typedef struct STRING_STRUCT
{
    char* buffer;
    int size;
} _STR_STRCT;

typedef struct HASH_STRUCT
{
    int* buffer;
    int size;
} _HASH_STRCT;

STRING_STRUCT STRUCT_STR_ARR[STRUCT_STR_ARR_LENGTH];

void find_words(_STR_STRCT*);
void change_case(_STR_STRCT*);
void reverse_string(void);
void get_string(_STR_STRCT*);
int check_palindrome(_STR_STRCT*);
void find_dups(_STR_STRCT*);
void find_dups_hash(_STR_STRCT*, _HASH_STRCT*);
int check_anagram(void);
void perm(char*);

void perm(char* word)
{
    for(int i = 0; i < strlen(word); i++)
    {
        for(int j = 0; j < strlen(word); j++)
        {
            for(int k = 0; k < strlen(word); k++)
            {
                if(i != j && j != k && i!= k)
                {
                    cout << word[i] << word[j] << word[k] << endl;
                }
            }
        }
    }
}

int check_anagram(void)
{
    int i = 0;
    int j;
    bool found = false;

    if(STRUCT_STR_ARR[0].size != STRUCT_STR_ARR[1].size)
    {
        return 0;
    }

    while(i < STRUCT_STR_ARR[0].size)
    {
        j = 0;
        found = false;
        while(j < STRUCT_STR_ARR[1].size)
        {
            if(STRUCT_STR_ARR[0].buffer[i] == STRUCT_STR_ARR[1].buffer[j])
            {
                found = true;
                STRUCT_STR_ARR[0].buffer[i] = '-';
                STRUCT_STR_ARR[1].buffer[j] = '-';
            }

            j += 1;
        }

        if(!found)
        {
            return 0;
        }

        i += 1; 
    }

    return 1;
}

void find_dups_hash(_STR_STRCT* string_ptr, _HASH_STRCT* array_ptr)
{
    int i = 0;
    int c;
    char ch;

    while(string_ptr -> buffer[i] != '\0')
    {
        c = (int) string_ptr -> buffer[i];
        array_ptr -> buffer[c - 97] += 1;

        i += 1;
    }

    for(int j = 0; j < array_ptr -> size; j++)
    {
        if(array_ptr-> buffer[j] > 1)
        {
            ch = (char) (j + 97);
            cout <<  ch << " -> " << array_ptr -> buffer[j] << endl;
        }
    }
}

void find_dups(_STR_STRCT* string_ptr)
{
    int i = 0;
    int count;
    int j;

    while(string_ptr -> buffer[i] != '\0')
    {
        j = i + 1;
        count = 1;

        while(string_ptr -> buffer[j] != '\0')
        {
            if(string_ptr -> buffer[i] == string_ptr -> buffer[j] && string_ptr -> buffer[j] != '-')
            {
                string_ptr -> buffer[j] = '-';
                count += 1;
            }

            j += 1;
        }

        if(count > 1)
        {
            cout << string_ptr -> buffer[i] << " -> " << count << endl;
        }

        i += 1;
    }
}

int check_palindrome(_STR_STRCT* string_ptr)
{
    int i = 0;

    while(i <= (string_ptr -> size) / 2)
    {
        if(string_ptr -> buffer[i] != string_ptr -> buffer[string_ptr -> size - i - 1])
        {
            return 0;
        }

        i += 1;
    }

    return 1;
}

void reverse_string(void)
{
    int i = 0;

    while(i < STRUCT_STR_ARR[0].size)
    {
        STRUCT_STR_ARR[1].buffer[i] = STRUCT_STR_ARR[0].buffer[STRUCT_STR_ARR[0].size - i - 1];
        STRUCT_STR_ARR[1].size += 1;
        i += 1;
    }

    STRUCT_STR_ARR[1].buffer[i] = '\0';
}

void find_words(_STR_STRCT* string_ptr)
{
    int i = 0;
    int no_of_words = 0;

    while(i <= string_ptr -> size)
    {
        if(string_ptr -> buffer[i] == ' ' || string_ptr -> buffer[i] == '\0')
        {
            no_of_words += 1;
            i += 1;
            cout << " -> word " << no_of_words << endl;
        }

        cout << string_ptr -> buffer[i];
        i += 1;
    }
}

void change_case(_STR_STRCT* string_ptr)
{
    int i = 0;
    int c;

    while(i < string_ptr -> size)
    {
        c = string_ptr -> buffer[i];
        if(c > 64 && c < 91)
        {
            string_ptr -> buffer[i] += 32;
        }
        else if(c > 89 && c < 123)
        {
            string_ptr -> buffer[i] -= 32;
        }

        i += 1;
    }
}

void get_string(_STR_STRCT* string_ptr)
{
    char c;
    int i = 0;

    while(c != '\n')
    {
        c = getc(stdin);
        
        string_ptr -> size += 1;
        string_ptr -> buffer = (char*) realloc(string_ptr -> buffer, string_ptr -> size * sizeof(char));
        string_ptr -> buffer[i] = c;

        i += 1;
    }
    
    string_ptr -> size -= 1;
    string_ptr -> buffer[string_ptr -> size] = '\0';
}

int main()
{
    _STR_STRCT string_struct_var;
    _HASH_STRCT hash_struct_var;
    char word[] = "abc";

    string_struct_var.buffer = (char*) malloc(sizeof(char));
    string_struct_var.size = 0;

    cout << "Enter you string: ";
    get_string(&string_struct_var);

    cout << "You Entered: " << string_struct_var.buffer << endl;
    cout << "String length: " << string_struct_var.size << endl; 

    // if(check_palindrome(&string_struct_var))
    // {
    //     cout << "Palindrome" << endl;
    // }
    // else 
    // {
    //     cout << "Not palindrome" << endl;
    // }

    // find_words(&string_struct_var);

    hash_struct_var.buffer = (int*) malloc(26 * sizeof(int));
    hash_struct_var.size = 26;

    for(int i = 0; i < hash_struct_var.size; i++)
    {
        hash_struct_var.buffer[i] = 0;
    }

    find_dups_hash(&string_struct_var, &hash_struct_var);
    // find_dups(&string_struct_var);

    // change_case(&string_struct_var);

    // cout << "Modified string: " << string_struct_var.buffer << endl;

    STRUCT_STR_ARR[0].buffer = (char*) malloc(sizeof(char));
    STRUCT_STR_ARR[0].size = 0;

    cout << "Enter string to be reversed: ";
    get_string(&STRUCT_STR_ARR[0]);

    STRUCT_STR_ARR[1].buffer = (char*) malloc(STRUCT_STR_ARR[0].size * sizeof(char));

    reverse_string();

    cout << STRUCT_STR_ARR[1].buffer << endl;

    cout << "ANAGRAMS" << endl;

    STRUCT_STR_ARR[0].buffer = (char*) malloc(sizeof(char));
    STRUCT_STR_ARR[0].size = 0;
    cout << "Enter string 1: ";
    get_string(&STRUCT_STR_ARR[0]);

    STRUCT_STR_ARR[1].buffer = (char*) malloc(sizeof(char));
    STRUCT_STR_ARR[1].size = 0;
    cout << "Enter string 2: ";
    get_string(&STRUCT_STR_ARR[1]); 

    if(check_anagram())
    {
        cout << "anangram" << endl;
    }
    else{
        cout << "not anagram" << endl;
    }

    perm(word);

    free(string_struct_var.buffer);

    return 0;
}
