#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < fruits.size(); r++) {
            mp[fruits[r]]++;

            // shrink window if more than 2 types
            while (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            // update max window size
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> fruits = {1,1,1,1,2,2,2,3,3,4,4,2,1,3,4,5,3};
    cout << sol.totalFruit(fruits) << endl;
    return 0;
}