class Solution {
private:
    // private helper function (not exposed outside the class)
    void helper(vector<vector<int>>& res, vector<int>& nums, int l, int h) {
        if (l == h) {
            res.push_back(nums);
            return;
        }
        for (int i = l; i <= h; i++) {
            swap(nums[l], nums[i]);          // choose
            helper(res, nums, l + 1, h);     // explore
            swap(nums[l], nums[i]);          // backtrack
        }
    }
public:
    // public function that user calls
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        helper(res, nums, 0, n - 1);   // call private helper
        return res;
    } 
};