class Solution {
public:
    int mirrorDistance(int n) {
        int res = 0, itm = n;
        while (itm != 0) {
            int tmp = itm % 10;
            itm /= 10;
            res = res * 10 + tmp;
        }
        return abs(res - n);
    }
};

class Solution{
public:
    long long minCost(string s, vector<int>&cost) {
        unordered_map<char, long long>map;
        int i = 0;
        long long Total_cost = accumulate(cost.begin(), cost.end(),0LL);
        for (char ls : s) {
            map[ls] += cost[i++];
        }
        auto itm = map.begin();
        long long Mincost = itm->second;
        while (itm != map.end()) {
            Mincost = max(Mincost, itm->second);
            itm++;
        }
        return Total_cost - Mincost;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        unordered_map<int, int>total;
        int len = nums.size();
        for (int& n : nums) total[n]++;
        unordered_map<int, int>map;
        int mx = 0, k = 0;
        for (int i = 0; i < len; i++) {
            int tmp = forbidden[i];
            if (++total[tmp] > len)return -1;
            if (tmp == nums[i]) {
                k++;
                mx = max(mx, ++map[tmp]);
            }
        }
        return max(mx, (k + 1) / 2);
    }
};