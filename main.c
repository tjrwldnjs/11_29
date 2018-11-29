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
		return 1; //������� 
	
	return 0;	
}

int fgetc_word(FILE* fp , char* word)
{	
		char c;
		int cnt;
		 
		while((c=fgetc(fp)) != EOF)
		{
			if(is_whitespace(c) == 0) //1���� ���� 
			break; //���ǹ��� �����̸� ���� 
		}
		if(c == EOF) //���� ���� ���ڰ� �������ϋ� 
		{
			return 0;	
		}
		
		//���������� �ܾ �ѱ��ھ� ���� 
		cnt = 0;
		word[cnt++] = c; //�Ʊ� ���� ù���� �Է� 
		word[cnt] = '\0'; //Ȥ�� �ڿ��� ������ �� �����Ƿ� (�ѱ���¥�� �ܾ�) 
		
		while ((word[cnt]=fgetc(fp)) != EOF) //1���� ���� 
		{
			if(is_whitespace(word[cnt]) == 1) //���鹮�ڸ� ������ ����ϰ� ���� 
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
