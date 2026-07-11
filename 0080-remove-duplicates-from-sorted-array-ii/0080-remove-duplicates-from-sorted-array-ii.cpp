class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if(n<2) return n;

        int i = 2;
        for(int j = 2; j < nums.size(); j++){
            if(nums[j] != nums[i-2]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};