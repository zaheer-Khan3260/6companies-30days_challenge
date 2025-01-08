#include<bits/stdc++.h>


using namespace std;


class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int>dq;
        int n = arr.size();

        for(int i = 0; i < n; i++){

            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }


            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};


int main(){
int t;
cin >> t;
cin.ignore();

while(t--){
vector<int> arr;

int k;

string inputLine;

getline(cin, inputline);
stringstream ss(inputLine);

int value;

while(ss >> value){
	arr.push_back(value);
}

cin >> k;
cin.ignore();

Solution obj;
vector<int> res = obj.maxOfSubarrays(arr, k);

for(int i = 0; i < res.size(); i++)
	cout << res[i] << " ";
cout << endl;

cout << "~" << "\n";

}

return 0; 

}
