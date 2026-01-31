class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        using ll = long long;
        int len = nums.size();
        vector<int>suf_nums(len);
        suf_nums[len - 1] = nums[len - 1];
        for (int i = len - 2; i > 0; i--) {
            suf_nums[i] = min(suf_nums[i + 1], nums[i]);
        }
        ll ans = LLONG_MIN;
        ll sum = 0;
        for (int i = 0; i < len - 1; i++) {
            sum += nums[i];
            ans = max(ans, sum - suf_nums[i + 1]);
        }
        return ans;
    }
};

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;                  // 各买各的
        if (need1 > need2) {
            swap(need1, need2);
            cost2 = cost1;
        }
        long long res2 = 1LL * costBoth * need2;                                  // 我包了
        long long res3 = 1LL * costBoth * need1 + 1LL * cost2 * (need2 - need1); // 混合策略
        return min({ res1, res2, res3 });
    }
};

class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k == 1)return 1;
        if (k % 2 == 0 || k % 5 == 0)return -1;
        int i = 1;
        int count = 1;
        while (i++) {
            count = (count * 10 + 1) % k;
            if (count == 0)break;
        }
        return i;
    }
};