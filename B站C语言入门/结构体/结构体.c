//#include <stdio.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//	char id[20];
//};//����һ���ṹ������
//
//
//int main()
//{
//	struct Stu p1 = { "Jack", 20, "20201101"};//�ýṹ�����ʹ���һ���ṹ�����
//	printf("%d\n%s\n%s\n", p1.age, p1.name, p1.id);
//
//	//����������һ��ָ��ýṹ���ָ�����
//	struct Stu* ps1 = &p1;
//	printf("%s\n", (*ps1).id);//���﷢���� . �������е��鷳��������ָ�� + �ṹ��ר���� -> ������
//	printf("%s\n", ps1->name);//���ô��Ǻ��ˣ���
//	return 0;
//}
