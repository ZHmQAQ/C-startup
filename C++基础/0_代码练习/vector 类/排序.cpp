#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <random>
using namespace std;

template<typename T>
class myVecClass{
private:
	static int vecserielnum;
private:
	vector<T> vec;
	string vecname;
private:
	std::default_random_engine generator;
	T genRandom(){
	    std::uniform_real_distribution<T> distribution(0.0, 100.0);
	    T random_number = distribution(generator);
		return random_number;
	}
public:
	bool echo;
public:
	myVecClass(int VecSize = 5, const T& IniVal = T(),string vecname = "vec")
	: generator(std::random_device{}()) 
	{
		this->vec = vector<T>(VecSize,IniVal);
		this->vecname = vecname + to_string(vecserielnum);
		this->echo = 1;
		cout<<"Vec has been successfully created. Current Vec: "<<endl;
		this->printVec();
		vecserielnum++;
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
	void iniRand(int n){
		vec.clear();
		for(int i = 0; i < n; i++)
			vec.push_back(genRandom());
		printVec();
	}
	void vecSort(){
		sort(vec.begin(),vec.end());
	}
};
template<typename T>
int myVecClass<T>::vecserielnum = 0;

template<>
class myVecClass<vector<int>>{
private:
	static int vecserielnum;
	vector<vector<int>> vec;
	string vecname;
public:
	bool echo;
public:
	myVecClass(int VecSize = 0, const vector<int>& IniVal = vector<int>(0,0), string vecname = "vecvec"){
		this->vec = vector<vector<int>>(VecSize,IniVal);
		this->vecname = vecname + to_string(vecserielnum++);
		this->echo = true;
		cout<<"Vec has been successfully created. Current Vec: "<<endl;
		this->printVec();
	}
	myVecClass(vector<vector<int>> vecvec,string vecname = "vecvec") {
		this->vec = vecvec;
		this->vecname = vecname + to_string(vecserielnum++);
		this->echo = true;
		cout<<"Vec has been successfully created. Current Vec: "<<endl;
		this->printVec();
	}
	void printVec(){
		cout<<"【"<<vecname<<"】"<<" "<<endl;
		for(auto it = vec.begin();it!=vec.end();it++){
			for(auto val : *it){
				cout<<val<<" ";
			}
			cout<<endl;
		}		
	}
	vector<vector<int>> createPascalsTriangle(int n){
		vector<vector<int>> vecvec(n,vector<int>(n));
		if(n <= 0)
			return {{}};
		else if(n == 1)
			return {{1}};
		else if(n == 2)
			return {{1},{1,1}};
		else{
			vecvec[0] = {1};
			vecvec[1] = {1,1};
			for(int i = 2; i < n; i++){
				vecvec[i].resize(i+1);
				for(int j = 0; j < i+1; j++){
					if(j == 0 || j == i)
						vecvec[i][j] = 1;
					else
						vecvec[i][j] = vecvec[i-1][j-1] + vecvec[i-1][j];
				}
			}
		}
		return vecvec;
	}
};

int myVecClass<vector<int>>::vecserielnum = 0;

int main(){
	myVecClass<double> obj;
	obj.iniRand(10);
	obj.vecSort();
	obj.printVec();
}
