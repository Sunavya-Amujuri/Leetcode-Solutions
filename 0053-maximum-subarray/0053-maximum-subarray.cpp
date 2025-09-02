class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending = 0;
        int max_so_far = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            max_ending += nums[i];
            max_so_far = max(max_ending, max_so_far);

            if(max_ending < 0){
                max_ending = 0;
            }
        }
        return max_so_far;
    }
};