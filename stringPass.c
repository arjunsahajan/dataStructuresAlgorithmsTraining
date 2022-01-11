#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strFun(int);
char* strReturn(int num);

char* strFun(int num) {
	char* strNum = NULL;
	int singleNum = 0;
	char singleCharNum;
	int i = 0;

	while(num != 0) {
		singleNum = num % 10;
		singleCharNum = singleNum + '0';
		strNum[i] = singleCharNum;
		i += 1;
		num = num / 10;
	}
	return strNum;
}

char* strReturn(int num) {
	static char arr[10];
	int i = 0;
	int remainder = 0;

	while(num != 0) {
		remainder = num % 10;
		arr[i] = remainder + '0';
		num = num / 10;
		i += 1;	
	}
	
	arr[i] = '\0';
	
	return arr;
}

int main() {
	//char* strNum = strFun(123);

	//printf("%c\n", strNum[0]);

	char arr[] = {'a', 'r', '\0'};

	char* p = NULL;


	p = strReturn(1000);
	printf("%s\n", p);

	//p = arr;

	p = strReturn(0001);
	printf("%s\n", p);

	p = strReturn(123);
	printf("%s\n", p);
	p = strReturn(12);
	printf("%s\n", p);

	//char ar[5];

	//itoa(123, ar, 10);

	//printf("%s\n", ar);
	
	int ap[10];

	ap[0] = 1;
	ap[1] = 2;
	//int i = sizeof(ap) / sizeof(ap[0]);

	int i = 0;
	while(i < (sizeof(ap) / sizeof(ap[0]))) {
		printf("%d", ap[i]);
		i += 1;
	}	

	printf("\n");

	char arj[10];

	sprintf(arj, "%d", 1);
	printf("%s\n", arj);	
	return 0;
}
