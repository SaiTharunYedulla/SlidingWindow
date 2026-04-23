#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                int lastIndex = mp[s[i]];
                l = max(l, lastIndex + 1); //to keep the left pointer inside the window, we use this max here
            }

            mp[s[i]] = i;
            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl; // Output: 3
}