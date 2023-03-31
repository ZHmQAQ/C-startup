#include <stdio.h>

//##########��ӡÿһλ##########
void num_Print(unsigned int n)
{
	//˼·��%10��/10,�������
	if (n >= 10)
		num_Print(n / 10);
	printf("%d ", n%10);
}

//##########�ַ�������##########
int get_str_Len(char* ch)
{
	//char* ch��ʾ������ַ�����ָ�룬��ͷ��βɨһ�飬�������\0����ֹ
	if (*ch == '\0')
		return 0;
	return 1 + get_str_Len(ch+1);//ch+1����ָ�������ƶ�һ��
	//����ָ�룬�һ��ǲ����˽⡭��
	//���鴫�Σ�����ȥ�Ĳ����������飬������Ԫ�صĵ�ַ
}

//##########��n�Ľ׳�##########
int factorial(int n)
{
	if (n == 0)
		return 1;
	return factorial(n - 1) * n;
}

//##########��쳲��������е�n��##########
int fibonacci(int n)
{
	//쳲��������У�1,1,2,3,5,8,13����
	//��n>=3��a(n) = a(n-1)+a(n-2)
	if (n == 1 || n == 2)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
	//����ʱ�临�Ӷ�O(2^n)��Ч�ʷǳ�����
	//��Ȼ���뾫���߼��򵥣�������������»��ǲ�Ӧ���õݹ�
}

int fibonacchi_opt1(int n)
{
	//��쳲��������Ż���
	//opt����˼��optimized���Ż���
	//��Ϊ�ݹ������ƣ�ѭ�������ƣ��ҿ��Դ������ݣ�����ʹ��ѭ���ķ���
	long n1 = 1;
	long n2 = 1;
	long n3 = 0;
	for (int i = 2; i < n; i++)
	{
		n3 = n2 + n1;
		n1 = n2;
		n2 = n3;
	}
	return n3;
}

//##########��ŵ������##########
int global_tot = 0;//��������
int Hanoi_Tower(int n,char X, char Z,char Y)
{
	//n�ǳ�ʼ���ϵ�Ԫ�ظ�����X�ǳ�ʼ����Z��Ŀ������Y�Ǹ�������
	//��ʵ����ABC���ӣ�����Ϊ�˷�ֹ����,�����л���һ����ν
	if (n == 0)
		return 0;
	Hanoi_Tower(n - 1, X, Y, Z);
	global_tot++;
	printf("%6d %c -> %c\n",global_tot,X, Z);
	Hanoi_Tower(n - 1, Y, Z, X);
}

int main()
{
	////##########��ӡÿһλ##########
	//unsigned int n;
	//n = 1145141919;
	//num_Print(n);

	////##########�ַ�������##########
	//char ch[20] = {1,2,4,5,5,0};
	//printf("%d\n", get_str_Len(ch));

	////##########��n�Ľ׳�##########
	//printf("%d\n", factorial(3));

	////##########��쳲��������е�n��##########
	////printf("%d\n", fibonacci(50));//�ǳ�������ʱ�临�Ӷ�̫���ˡ�
	//printf("%d\n",fibonacchi_opt1(40));//�ܿ��

	////##########��ŵ������##########
	//char A = 'A';
	//char B = 'B';
	//char C = 'C';
	//int n = 4;
	//Hanoi_Tower(n, A, C, B);

}