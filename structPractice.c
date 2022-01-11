#include <stdio.h>

int main(int argc, char *argv[]) {
	char buffer[] = "arjun";
	int i = 0;
	
	while(buffer[i] != '\0') {
		printf("%c\n", buffer[i]);
		i++;
	}

	printf("%c\n", buffer[4]);
	printf("%c\n", buffer[5]);

	char a = 's';	

	if(a < 'z') {
		printf("oh\n");
	} 
	
	return 0;	
}
