#include <stdio.h>

int funName(char*);
int strLen(char*);
int arrayLen(int*);
void printArrayElements(int*, int);

int funName(char* numString) {
	int i = 0;

	while(numString[i] != '\0') {
		printf("%c\n", numString[i]);
		i += 1;
	}

	printf("i = %d\n", i);

	printf("%d\n", (int) (sizeof(numString[0])));

	return 1;
}

int strLen(char* charPointer) {
	int len = 0;

	while(charPointer[len] != '\0') {
		len += 1;
	}

	return len;
}

void printArrayElements(int* arrPointer, int size) {
	int i = 0;

	while(i < size) {
		printf("%d %p\n", arrPointer[i], &arrPointer[i]);
		i += 1;
	}
	printf("\n");

}

int arrayLen(int* arr) {

	//int size = (int *)(&arr+1)-arr;

	printf("size %p\n", arr);

	return 1; 	
}

int main(int argc, char *argv[]) {
	printf("%zu\n", (unsigned long)sizeof(int));
	
	char arr[] = "arjun";

	printf("%c\n", arr[sizeof(arr) / sizeof(arr[0]) - 2]);	

	funName("1");	

	int array[] = {1, 2, 3, 4, 5};

	printArrayElements(array, sizeof(array) / sizeof(array[0]));


	printf("address of first element %p\n", &array + 1 );

	int s = *(&array + 1) - array;

	printf("size %d\n", s);
	
	printf("hello %p\n", &array);
	
	arrayLen(array);
	
	return 0;
}
