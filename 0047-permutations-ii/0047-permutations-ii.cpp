class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int start) {
        if(start == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> seen; // to avoid duplicates at this recursion level

        for(int i = start; i < nums.size(); i++) {
            if(seen.count(nums[i])) continue; // skip duplicate numbers
            seen.insert(nums[i]);

            swap(nums[start], nums[i]);  // choose nums[i] for position "start"
            backtrack(nums, start + 1);  // recurse
            swap(nums[start], nums[i]);  // undo (backtrack)
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sorting helps with duplicates
        backtrack(nums, 0);
        return result;
    }
};

