class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), res = 100000000000;
        for (int i = 0; i < len - 2; i++) {
            int fri = i + 1, las = len - 1;
            while (fri < las) {
                int sum = nums[i] + nums[fri] + nums[las];
                if (abs(sum - target) < abs(res - target))res = sum;
                if (sum == target)return sum;
                if (sum < target) fri++;
                else las--;
            }
        }
        return res;
    }
};