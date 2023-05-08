#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

int crct_ans = 0;
int user_ans = 0;
int new_record = 0;

int Get_Random_Number() //获取一个0~100的随机数
{
	srand(time(NULL));
	//用系统时间为rand函数设置随机数种子，这个操作是必须的。
	return (int)rand()%100+1;
	//rand函数返回值是0~32767，此处使用取余数的方法控制被猜数字的大小范围
}

int is_Number(char ch[]) //判断输入的字符串是不是一个合法数字
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


void Get_Started()//开始
{	
	printf("Game started, please enter a number between 1 and 100.\n");
	Guess();	
}

int Guess()//输入并判断是否合法，如果合法，进入比较
{
	char ch[20] = { 0 };
	printf("New guess:\n");
	scanf("%s", ch);
	if (is_Number(ch) == 0)//如果输入不合法，则重新开始
		Guess();
	user_ans = atoi(ch);//将ch字符串转化为int
	return(Cmp_Ans(crct_ans, user_ans));
}

int Cmp_Ans(int crct_ans, int user_ans)//比较用户输入结果和正确结果，如果正确就输出总尝试次数，如果错误则提示猜大了或者猜小了
{
	new_record++;//记录尝试次数的变量
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


int record() //文件操作，保存记录，如果打破最佳纪录，则更新最佳纪录。输出最佳纪录
{
	FILE* fp;
	int top_record = 0;
	fp = fopen("record.txt", "a+");
	if (fp == NULL) {
		printf("文件打开失败。\n");
		return 1;
	}	
	fprintf(fp, "%d\n", new_record);//在末尾打印此次记录
	fseek(fp, 0, SEEK_SET);
	fscanf(fp, "%d\n", &top_record);//文件的第一行是最高纪录，读取该值
	if (top_record > new_record)//比较此次记录和最高纪录，如果此次记录更小（更好），就将其保存在文件开头。
	{
		fprintf(fp, "%d\n", new_record);
		top_record = new_record;
	}
	fclose(fp);
	printf("Best record:%d\n", top_record);
	return 0;
}

int main() //为了方便重新游戏，主函数中是一个do while循环。
{	
	do {
		system("cls");
		new_record = 0;//初始化次数记录变量，否则会无限累加。
		printf("**********WELCOME TO NUMBER GUESS**********\n");
		crct_ans = Get_Random_Number();//初始化这一轮要猜的数字
		Get_Started();
		record();	
		printf("Press any key to restart;Enter '0' to exit.\n");
		//system("pause");
		
	} while (_getch()!= 48);//48是0的ascii码值
	//循环输入，这样可以重复进行游戏，而不是每次都要重新打开
	return 0;
}
