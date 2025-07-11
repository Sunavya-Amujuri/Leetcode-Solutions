class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;
    for(int i=0; i<nums.size(); i++) {
        if (freq == 0) {
            ans = nums[i];
        }
        if (ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
    }
    freq = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == ans) {
            freq++;
        }
    }

    if (freq > nums.size() / 2) {
        return ans;
    } else {
        return -1;
    }
};