#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
class myclass{
public:
	void printVector(const vector<T>& nums){
		typename vector<T>::const_iterator it = nums.begin();
		for(; it != nums.end(); it++ )
			cout<<*it<<" ";
		cout<<endl;
	}
	vector<T> iniVector(int _n = 10){
		vector<T> vec(_n,0);
		typename vector<T>::iterator it = vec.begin();
		int i = 0;
		for(;it!=vec.end();it++)
			*it = 2*(i++);
		return vec;
	}
	void push_back(vector<T>& vec, T ele){
		vec.push_back(ele);
		printVector(vec);
	}
	void pop_back(vector<T>& vec){
		vec.pop_back();
		printVector(vec);
	}
	void insert(vector<T>& vec, int pos,T ele){
		vec.insert(vec.begin()+pos,ele);
		printVector(vec);
	}
 	void erase(vector<T>&vec, int pos){
 		vec.erase(vec.begin()+pos);
 		printVector(vec);
	}
};

/*
3. **插入和删除元素**：创建一个 `vector<string>`，并且添加一些你喜欢的名字。
然后，使用 `push_back` 函数添加一个名字，
使用 `pop_back` 函数删除一个名字，
使用 `insert` 函数在中间插入一个名字，
使用 `erase` 函数删除一个名字。
*/
int main(){
    vector<string>str = {"hello","world","!"};
    myclass<string> obj;
    obj.printVector(str);
	obj.push_back(str,"hello");
	obj.pop_back(str);
	obj.insert(str,1,"f**king");
	obj.erase(str,1);
    obj.printVector(str);
}
