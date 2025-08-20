class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 4) return ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                long long rem = (long long)target - nums[i] - nums[j];
                int left = j+1, right = n-1;
                while(left < right){
                    long long sum = nums[left] + nums[right];

                    if(sum == rem){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left-1])left++;
                        while(left < right && nums[right] == nums[right+1])right--;
                    } else if (sum < rem){
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};