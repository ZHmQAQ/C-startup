#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Solution{
public:
void reverse(vector<T>& arr){
	//逆序一个顺序表，原地算法 
	int begin = 0;
	int end = arr.size() - 1;
	if(end < 0)
		print("current vec is empty.");
	while(begin<=end) {
		T temp = arr[begin];
		arr[begin] = arr[end];
		arr[end] = temp;
		begin++;
		end--;
	}
}
void print(string str){
	cout<<str<<endl;
	exit(-1);
	}
void print(vector<T> arr){
	for(auto it : arr)
		cout<<it<<" ";
	cout<<endl<<endl;
}	

}; 

int main() {
    Solution<int> solution;

    std::vector<int> testArr1 = {1, 2, 3, 4, 5};
    std::cout << "Original array: ";
    solution.print(testArr1);
    solution.reverse(testArr1);
    std::cout << "After reverse: ";
    solution.print(testArr1);

    std::vector<int> testArr2 = {6, 7, 8, 9, 10, 11};
    std::cout << "Original array: ";
    solution.print(testArr2);
    solution.reverse(testArr2);
    std::cout << "After reverse: ";
    solution.print(testArr2);

    return 0;
}


