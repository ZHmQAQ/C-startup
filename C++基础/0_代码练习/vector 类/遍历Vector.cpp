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
	void traverse1(){
		//用迭代器遍历 
		cout<<"迭代器遍历"<<endl; 
		for(auto it = vec.begin();it!=vec.end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	void traverse2(){
		//用下标遍历 
		cout<<"用下标遍历"<<endl;
		int size = vec.size();
		for(int i = 0; i < size; i++){
			cout<<vec[i]<<" ";
		}
		cout<<endl; 
	}
	void traverse3(){
		//用范围循环遍历 
		cout<<"范围循环遍历"<<endl;
		for(const T &ele: vec){
			cout<<ele<<" ";
		}
		cout<<endl;
	}
};
template<typename T>
int myVecClass<T>::vecserielnum = 0;
int main(){
	myVecClass<int> objx(300);
	objx.show_capacity();
	objx.echo = 0;
	objx.traverse1();
	objx.traverse2();
	objx.traverse3();
}
