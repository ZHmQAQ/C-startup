//#include <stdio.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//	char id[20];
//};//创建一个结构体类型
//
//
//int main()
//{
//	struct Stu p1 = { "Jack", 20, "20201101"};//用结构体类型创建一个结构体变量
//	printf("%d\n%s\n%s\n", p1.age, p1.name, p1.id);
//
//	//接下来创建一个指向该结构体的指针变量
//	struct Stu* ps1 = &p1;
//	printf("%s\n", (*ps1).id);//这里发现用 . 操作符有点麻烦，可以用指针 + 结构体专属的 -> 操作符
//	printf("%s\n", ps1->name);//不用打星号了！！
//	return 0;
//}
