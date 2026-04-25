#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int ans = 0;
        int zeros = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0){
                zeros++;
            }

            while(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}