class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() == 0) return 0;

    int i = 0;  // slow pointer
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];  // place the unique element
        }
    }

    return i + 1;  // number of unique elements
    }
        
};