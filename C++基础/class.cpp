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
		cout << "========��ӡ����========" << endl;
		cout << "     int name = " << name << endl;
		cout << " static int n = " << n << endl;
		cout << "const int val = " << val << endl;
		cout << "========================" << endl;
	}

	void change_name(int v)
	{
		cout << endl << "�Ұ�" << name << "�� name �ĳ���" << v << "!" <<endl;
		name = v;
	}

	//const �Ĳ��ˣ�ֻ���ڳ�ʼ����ʱ�����ֵ
	//void change_val(int v)
	//{
	//	val = 1;
	//}

	void change_n(int v) const //���ﲻ�� const Ҳ���������޸� static ���� n ��ֵ�����Ǽ��� const ����׼
	{
		cout << endl << name << "�Ѿ�̬���ݳ�Ա n ��ֵ��" << n << "�ĳ���" << v << "!" << endl;
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