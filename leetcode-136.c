//###########����##########
//��һ�����У�������һ������ֻ������һ�Σ��������־����������Ρ�
//�þ����ٵ�ʱ��Ϳռ䣬��ɲ�������

//�ҵĽ������
//�����ⲻ��������ƥ��ô
#include <stdio.h>
#define MAXSZ 4096
int findNum(int arr[], int n)
{
	//�ȳ��Ա�������
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = i + 1; j < n; j++)
			if (arr[i] == arr[j])
			{
				flag = 0;
			}
		if (flag == 1)
			return i;
	}			
}

int main()
{
	int arr[11] = { 0,0,5,5,1,4,6,7,7,6,4 };
	printf("%d\n", findNum(arr, 11));
	return 0;
}
