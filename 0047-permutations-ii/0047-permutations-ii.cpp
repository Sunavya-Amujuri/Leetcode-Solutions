class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool>& used) {
        if(curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            // Skip if already used
            if(used[i]) continue;

            // Skip duplicates: if nums[i] == nums[i-1] and nums[i-1] not used yet
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            curr.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, curr, used);

            // Backtrack
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort for duplicate check
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        backtrack(nums, curr, used);
        return result;
    }
};
