class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> result(s.begin(), s.end());

        int n = result.size();
        int curr_sum = result[0];
        int max_sum = result[0];

        for(int i=1; i<n; i++){
            curr_sum = max(result[i], curr_sum + result[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};