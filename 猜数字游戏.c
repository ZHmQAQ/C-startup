#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

int crct_ans = 0;
int user_ans = 0;
int new_record = 0;

int Get_Random_Number() //��ȡһ��0~100�������
{
	srand(time(NULL));
	//��ϵͳʱ��Ϊrand����������������ӣ���������Ǳ���ġ�
	return (int)rand()%5+1;
	//rand��������ֵ��0~32767���˴�ʹ��ȡ�����ķ������Ʊ������ֵĴ�С��Χ
}

int is_Number(char ch[]) //�ж�������ַ����ǲ���һ���Ϸ�����
{
	for (int i = 0; i < strlen(ch); i++)
	{
		if (ch[i] < '0' || ch[i]>'9')
		{
			printf("Invalid input, please enter a number.\n");
			return 0;
		}
	}
	return 1;
}


void Get_Started()//��ʼ
{	
	printf("Game started, please enter a number between 1 and 100.\n");
	Guess();	
}

int Guess()//���벢�ж��Ƿ�Ϸ�������Ϸ�������Ƚ�
{
	char ch[20] = { 0 };
	printf("New guess:\n");
	scanf("%s", ch);
	if (is_Number(ch) == 0)//������벻�Ϸ��������¿�ʼ
		Guess();
	user_ans = atoi(ch);//��ch�ַ���ת��Ϊint
	return(Cmp_Ans(crct_ans, user_ans));
}

int Cmp_Ans(int crct_ans, int user_ans)//�Ƚ��û�����������ȷ����������ȷ������ܳ��Դ����������������ʾ�´��˻��߲�С��
{
	new_record++;//��¼���Դ����ı���
	if (crct_ans == user_ans)
	{
		printf("Your answer is correct!You have guessed %d times! \n",new_record);
		return 0;
	}
	if (crct_ans < user_ans)
	{
		printf("Your answer is too big.\n");
		Guess();
	}
	if (crct_ans > user_ans)
	{ 
		printf("Your answer is too small.\n");
		Guess();
	}
}


int record() //�ļ������������¼�����������Ѽ�¼���������Ѽ�¼�������Ѽ�¼
{
	FILE* fp;
	int top_record = 0;
	fp = fopen("record.txt", "a+");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܡ�\n");
		return 1;
	}	
	fprintf(fp, "%d\n", new_record);//��ĩβ��ӡ�˴μ�¼
	fseek(fp, 0, SEEK_SET);
	fscanf(fp, "%d\n", &top_record);//�ļ��ĵ�һ������߼�¼����ȡ��ֵ
	if (top_record > new_record)//�Ƚϴ˴μ�¼����߼�¼������˴μ�¼��С�����ã����ͽ��䱣�����ļ���ͷ��
	{
		fprintf(fp, "%d\n", new_record);
		top_record = new_record;
	}
	fclose(fp);
	printf("Best record:%d\n", top_record);
	return 0;
}

int main() //Ϊ�˷���������Ϸ������������һ��do whileѭ����
{	
	do {
		system("cls");
		new_record = 0;//��ʼ��������¼����������������ۼӡ�
		printf("**********WELCOME TO NUMBER GUESS**********\n");
		crct_ans = Get_Random_Number();//��ʼ����һ��Ҫ�µ�����
		Get_Started();
		record();	
		printf("Press any key to restart;Enter '0' to exit.\n");
		
	} while (_getch()!= 48);//48��0��ascii��ֵ
	//ѭ�����룬���������ظ�������Ϸ��������ÿ�ζ�Ҫ���´�
	return 0;
}
