#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {//vector nums contain a list of numbers
        int i, n;
        n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int res = 0;
        for (i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == 0) res = i + 1;

            if (mp.find(sum) != mp.end()) {
                res = max(res, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return res;//it returns the longest subarray(or sublist) with sum=0
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
