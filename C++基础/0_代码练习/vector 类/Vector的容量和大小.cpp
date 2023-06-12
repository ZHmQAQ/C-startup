//输出结果可以查看 output.txt


#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
class myVecClass{
private:
	static int vecserielnum;
private:
	vector<T> vec;
	string vecname;
public:
	bool echo;
public:
	myVecClass(int VecSize = 5, const T& IniVal = T(),string vecname = "vec"){
		this->vec = vector<T>(VecSize,IniVal);
		this->vecname = vecname + to_string(vecserielnum);
		this->echo = 1;
		cout<<"Vec has been successfully created. Current Vec: "<<endl;
		this->printVec();
		this->vecserielnum++;
	}
	void printVec(){	
		cout<<"【"<<vecname<<"】"<<" ";
		typename vector<T>::iterator it = vec.begin();
		for(;it!=vec.end();it++)
		cout<<*it<<" ";
		cout<<endl;		
	
	}
	void pop_back(){
		vec.pop_back();
		if(echo){
			cout<<"pop: ";
			printVec();
		}
	}
	void push_back(T ele = T()){
		vec.push_back(ele);
		if(echo){
			cout<<"push: ";
			printVec();
		}
	}
	void insert(int i,T ele = T()){
		typename vector<T>::iterator it = vec.begin()+i;
		vec.insert(it,ele);
		if(echo){
			cout<<"insert: ";
			printVec();
		}
	}
	void show_capacity(){
		cout<<"capacity: "<<vec.capacity()<<flush<<endl;
	}
	void show_elementnum(){
		cout<<"elementnum: "<<vec.size()<<flush<<endl;
	}
};
template<typename T>
int myVecClass<T>::vecserielnum = 0;
int main(){
	//freopen("output.txt", "w", stdout);
	/*
	myVecClass<string> obj1(10,"hell");
	myVecClass<int> obj2;
	obj2.printVec();
	obj2.pop_back();
	obj2.push_back(6);
	obj1.push_back("nonono");
	obj2.insert(2,9);
	*/
	myVecClass<int> objx(3,1,"test");
	objx.show_capacity();
	objx.echo = 0;
	for(int i = 0; i < 100; i++){
		objx.push_back(i);
		objx.show_elementnum();		
		objx.show_capacity();
		cout<<endl;
	}
}
