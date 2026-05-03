#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int l = 0;
        int r = 0;
        int ans = 0;
        int maxcnt = 0;
        while(r < s.size()){
            v[s[r] - 'A']++;
            maxcnt = max(maxcnt, v[s[r] - 'A']);    //count chages only when we add a new character, so we can just compare with the current character count
            while((r - l + 1 - maxcnt) > k){  //if the current window size - maxcnt > k, we need to shrink the window until it is valid again
                v[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);  //update the answer after we make sure the current window is valid
            r++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.characterReplacement("ABAB", 2) << endl; // 4
    cout << s.characterReplacement("AABABBA", 1) << endl; // 4
    return 0;
}