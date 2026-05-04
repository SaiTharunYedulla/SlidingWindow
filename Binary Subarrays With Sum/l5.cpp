#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:

    int helper(vector<int> &nums, int goal){
        if(goal < 0){
            return 0;
        }
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
        
    }
};

int main(){
    Solution s;
    vector<int> v1 = {1,0,1,0,1};
    vector<int> v2 = {0,0,0,0,0};
    cout << s.numSubarraysWithSum(v1, 2) << endl; // 4
    cout << s.numSubarraysWithSum(v2, 0) << endl; // 15
    return 0;
}