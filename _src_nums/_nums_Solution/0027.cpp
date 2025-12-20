class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int fri = 0, las = len - 1;
        int count = 0;
        while (fri <= las) {
            while (nums[fri] != val && fri < las) fri++;
            while (nums[las] == val && fri < las) {
                nums[las] = -1;
                las--;
                count++;
            }
            if (las == fri && nums[fri] == val)nums[fri] = -1, count++;
            else if (las != fri) {
                count++;
                swap(nums[fri], nums[las]);
                nums[las] = -1;
            }
            fri++, las--;
        }
        return len - count;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int tmp : nums) {
            if (tmp != val)nums[i++] = tmp;
        }
        return i;
    }
};