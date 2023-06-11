#include <iostream>
#include <vector>
using namespace std;

class myclass{
public:
	void printVector(vector<int> nums){
		vector<int>::iterator it = nums.begin();
		for(it; it != nums.end(); it++ )
			cout<<*it<<" ";
	}
};

int main(){
    vector<int>nums = {1,2,3,4,5};\
	myclass obj;
    obj.printVector(nums);
}