#include <iostream>
#include <vector>


using namespace std;

int minMoves2(vector<int>& nums) {
        int move = 0;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;

        while(left <= right){
            long long n;
            if(nums[mid] > nums[left]){
                n = nums[mid] - nums[left];
                move += n;
            }else{
                n = nums[left] - nums[mid];
                move += n;
            }  
            left++;         
        }
        return move;
    }

int main(){

	vector<int> test1 = {1, 2, 3};
	vector<int> test2 = {1, 10, 2, 9};

    	int result1 = minMoves2(test1);
	int result2 = minMoves2(test2);

	cout << result1 << endl;
	cout << result2 << endl;


}
