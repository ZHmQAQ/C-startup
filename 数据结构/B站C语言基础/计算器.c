#include <stdio.h>
#include <windows.h>
#include <conio.h>
void menu()
{
	system("cls");
	printf("计算器\n1:+\n2:-\n3:*\n4:/\n0:exit\n\n");	
}
func(int(*pf)(int,int)) //把pf函数指针当作参数传入func
{
    int a;
    int b;
    printf("enter 2 nums\n");
    scanf("%d%d",&a,&b);
    printf("ans: %d\n",(*pf)(a,b));
}
int plus(int a,int b){return a + b;}
int minus(int a,int b){return a - b;}
int times(int a,int b){return a * b;}
int divide(int a,int b){return a / b;}
int mainfunction()
{
    int input;
    int (*pf[])(int a,int b) = {0,plus, minus, times, divide};
    menu();
    scanf("%d",&input);
    if(input == 0)
        return 0;
    else if(input > 0 && input < 5)
    {
        func(*pf[input]);
        printf("按下任意键继续……\n");
		getch();
        return mainfunction();
    }
    else
    {
    	printf("无效输入\n按下任意键继续……\n");
    	getch();
		return mainfunction();
	}

}
int main()
{
    mainfunction();
}
