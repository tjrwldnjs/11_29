#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	FILE* fp;
	char name[100];
	
	//pirntf, scanf
	printf("Input a file name : ");
	scanf("%s", name);
	
	//fopen
	fp = fopen(name, "r");
	
	//error handing
	if (fp==NULL)
	{
		printf("ERROR! check th file name : %s\n", name);
		return -1;
	}

	printf("%c\n", fgetc(fp));
	
	//fclose
	fclose(fp);
	return 0;
}
