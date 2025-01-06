#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isStrictlyIncreasing(vector<int>& arr) {
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] <= arr[i-1]) return false;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                vector<int> remaining;
                
                for(int k = 0; k < i; k++) {
                    remaining.push_back(nums[k]);
                }
                
                for(int k = j + 1; k < n; k++) {
                    remaining.push_back(nums[k]);
                }
                
                if(isStrictlyIncreasing(remaining)) {
                    count++;
                }
            }
        }

        return count;
    }
};


int main(){
	
	Solution s;

	vector<int> test1 = {1,2,3,4};
	vector<int> test2 = {6,5,7,8};

	cout << s.incremovableSubarrayCount(test1) << endl;
	cout << s.incremovableSubarrayCount(test2) << endl;
}
