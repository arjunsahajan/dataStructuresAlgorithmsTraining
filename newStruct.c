#include <stdio.h>

typedef struct s1 {
	int a = 1;
	int b = 2;
} s1;

typedef struct s2 {
	int a;
	int b;
} s2;

typedef union {
	s1 s1var;
	s2 s2var;
} s;

void funStruct(s*, int);

void funStruct(s* sptr, int num) {
	if(num == 1) {
		//sptr -> s1var* pptr;
		printf("%d\n", sptr -> s1var.a);
		printf("%d\n", sptr -> s1var.b);
	} else {
		//sptr -> s2var* pptr;
	}


}

int main() {
	s svar;

	s1 data1;
	s2 data2;

	data1.a = 1;
	data1.b = 3;

	data2.a = 5;
	data2.b = 6;

	funStruct(&svar, 1);

	return 0;
}
