#include <iostream>

using namespace std;

class ClassName
{
public:
	ClassName();
	ClassName(int v);
	~ClassName();

	int name;
	const int val;
	static int n;

	void printdata()
	{
		cout << endl;
		cout << "========打印数据========" << endl;
		cout << "     int name = " << name << endl;
		cout << " static int n = " << n << endl;
		cout << "const int val = " << val << endl;
		cout << "========================" << endl;
	}

	void change_name(int v)
	{
		cout << endl << "我把" << name << "的 name 改成了" << v << "!" <<endl;
		name = v;
	}

	//const 改不了，只能在初始化的时候赋予初值
	//void change_val(int v)
	//{
	//	val = 1;
	//}

	void change_n(int v) const //这里不用 const 也可以正常修改 static 数据 n 的值，但是加上 const 更标准
	{
		cout << endl << name << "把静态数据成员 n 的值从" << n << "改成了" << v << "!" << endl;
		n = v;
	}

};

ClassName::ClassName() : name(0), val(0)
{}

ClassName::ClassName(int v) : name(v), val(v)
{}

ClassName::~ClassName()
{}

int ClassName::n = 100;

int main()
{
	ClassName obj1(1);
	ClassName obj2(2);
	obj1.printdata();
	obj2.printdata();
	obj1.change_name(5);
	obj1.change_n(10);
	obj1.printdata();
	obj2.printdata();
	obj2.change_n(1000);
	obj2.change_name(10086);
	obj2.change_n(100);
	obj2.printdata();
}