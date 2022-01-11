#include <stdio.h>

void fun(int*);
int sizeOfArr(int []);
void printString(char []);

int sizeOfArr(int arr[]) {
	return *(&arr + 1) - arr;
}

void printString(char arr[]) {
	int i = 0;
	while(arr[i] != '\0') {
		printf("%c", arr[i]);
		i += 1;
	}

	printf("\n");
}

void fun(int* ptr) {
	ptr[0] = 10;
}

int main() {
	int arr[10] = {1, 2, 3, 4, 5};

	fun(arr);

	int i = 0;

	while(i < sizeof(arr) / sizeof(arr[0])) {
		printf("%d ", arr[i]);
		i += 1;
	}

	printf("\n");

	int size = sizeOfArr(arr);

	printf("%d\n", *(&arr + 1) - arr);
	
	char c = 'T';
	int uc;

	uc = (int) c;

	printf("%d\n", uc);

	char* name = "arjun";

	printString(name);
	
	return 0;
}
