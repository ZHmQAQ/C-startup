#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class myclass{
public:
	void printVector(const vector<T>& nums){
		typename vector<T>::const_iterator it = nums.begin();
		for(; it != nums.end(); it++ )
			cout<<*it<<" ";
	}
	vector<T> iniVector(int _n = 10){
		vector<T> vec(_n,0);
		typename vector<T>::iterator it = vec.begin();
		int i = 0;
		for(;it!=vec.end();it++)
			*it = 2*(i++);
		return vec;
	}
};

int main(){
    vector<double>nums;
	myclass<double> obj;
	nums = obj.iniVector();
    obj.printVector(nums);
}
