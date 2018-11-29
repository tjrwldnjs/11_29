#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_whitespace(char c)
{
	if (c == ' ' ||
		c == '\t' ||
		c == '\n' ||
		c == '\r' ||
		c == '(' ||
		c == ')' 
		)
		return 1; //공백글자 
	
	return 0;	
}

int fgetc_word(FILE* fp , char* word)
{	
		char c;
		int cnt;
		 
		while((c=fgetc(fp)) != EOF)
		{
			if(is_whitespace(c) == 0) //1문자 받음 
			break; //유의미한 문자이면 나감 
		}
		if(c == EOF) //최초 읽은 문자가 마지막일떄 
		{
			return 0;	
		}
		
		//본격적으로 단어를 한글자씩 읽음 
		cnt = 0;
		word[cnt++] = c; //아까 읽은 첫글자 입력 
		word[cnt] = '\0'; //혹시 뒤에서 못읽을 수 있으므로 (한글자짜리 단어) 
		
		while ((word[cnt]=fgetc(fp)) != EOF) //1문자 받음 
		{
			if(is_whitespace(word[cnt]) == 1) //공백문자면 받은거 취소하고 나감 
			{
				word[cnt] = '\0';
				break;
			}
			cnt++; 
		} 
		
		return cnt;
}

int main(int argc, char *argv[]) {
	
	FILE* fp;
	char name[100];
	char word[100];
	
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
	
	//word reading
	while (fgetc_word(fp, word) != 0)
	{
		//word processing
		printf("%s\n", word); //test code
	}

	printf("%c\n", fgetc(fp));
	
	//fclose
	fclose(fp);
	return 0;
}
