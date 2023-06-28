#include <iostream>
#include <vector>
using namespace std;


template <typename T>
class solution{
public:
	T find_min_ele(vector<T>& arr){
		printvec(arr);
		if(arr.empty()){
			cout << "error" << endl;
			return -1;
		}
		auto ret = arr.begin();
		for(auto it = arr.begin(); it < arr.end(); it++)
			if(*it < *ret)
				ret = it;
		int rr = *ret;
		arr.erase(ret);
		if(arr.empty()){
			cout << "error";
			return -1;
		}
		arr.push_back(*(arr.end()-1));
		printvec(arr);
		return rr;
	}
private:
	void printvec(vector<T>& arr){
		cout<<"current:"<<endl;
		for(auto it = arr.begin(); it<arr.end(); it++)
			cout << *it << " ";
		cout<<endl;
	}
};

int main() {
    solution<int> arrayMin;

    std::vector<int> testArr1 = {5, 3, 7, 1, 9};
    std::cout << "The minimum element in testArr1 is " << arrayMin.find_min_ele(testArr1) << std::endl<<endl;

    std::vector<int> testArr2 = {11, 15, 7, 8, 10, 2};
    std::cout << "The minimum element in testArr2 is " << arrayMin.find_min_ele(testArr2) << std::endl<<endl;

    std::vector<int> testArr3 = {};
    std::cout << "The minimum element in testArr3 is " << arrayMin.find_min_ele(testArr3) << std::endl<<endl;

    return 0;
}
