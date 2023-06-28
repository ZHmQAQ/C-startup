#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Solution{
public:
	void del_all_x(vector<T>& arr, T s, T t){
		if (s>=t || arr.empty()){
			cout<<"error"<<endl;
			return;
		}
		for(auto it = arr.begin(); it<arr.end();)
			if(*it >= s && *it <= t)
				it = arr.erase(it);
			else
				it++;
		print(arr);
	}
	void print(vector<T> arr){
		for(auto it : arr)
			cout<<it<<" ";
		cout<<endl<<endl;
	}	
}; 

int main() {
    Solution<int> solution;

    std::vector<int> testArr1 = {5, 3, 7, 1, 5, 9};
    std::cout << "Original array: ";
    solution.print(testArr1);
    solution.del_all_x(testArr1, 1, 5);
    std::cout << "After deletion: ";
    solution.print(testArr1);

    std::vector<int> testArr2 = {11, 15, 7, 8, 11, 10, 2};
    std::cout << "Original array: ";
    solution.print(testArr2);
    solution.del_all_x(testArr2, 7, 15);
    std::cout << "After deletion: ";
    solution.print(testArr2);

    return 0;
}

