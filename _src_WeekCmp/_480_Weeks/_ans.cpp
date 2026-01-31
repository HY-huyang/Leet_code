class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mx_sum = 0, mi_sum = 0;
        int fr = 0, la = nums.size() - 1;
        while (k--) {
            mx_sum += nums[la--];
            mi_sum += nums[fr++];
        }
        return mx_sum - mi_sum;
    }
};
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return accumulate(nums.end() - k, nums.end(), 0) - accumulate(nums.begin(), nums.begin() + k, 0);
    }
};

class Solution {
public:
    string reverseWords(string s) {
        if (s.find(' ') == string::npos)return s;
        int count = 0;
        int i = 0;
        for (i; i < s.size(); i++) {
            char tmp = s[i];
            if (tmp == ' ')break;
            if (tmp == 'a' || tmp == 'o' || tmp == 'e' || tmp == 'i' || tmp == 'u')count++;
        }
        auto itm = s.begin() + i + 1;
        while (itm != s.end()) {
            int cur = 0;
            auto start = itm;
            while (itm != s.end() && *itm != ' ') {
                if (*itm == 'a' || *itm == 'o' || *itm == 'e' || *itm == 'i' || *itm == 'u')cur++;
                itm++;
            }
            if (cur == count)reverse(start++, itm);
            if (itm != s.end()) itm++;
        }
        return s;
    }
};

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        using ll = long long;
        int len = balance.size();
        ll pos_sum = 0, ans = 0;
        ll neg = INT_MIN;
        for (int i = 0; i < len; i++) {
            if (balance[i] < 0)neg = i;
            else pos_sum += balance[i];
        }
        if (neg == INT_MIN)return 0;
        if (pos_sum + balance[neg] < 0)return -1;
        ll neg_num = balance[neg];
        for (int i = 1; neg_num < 0 && i < INT_MAX; i++) {
            int pre = (neg - i + len) % len, las = (neg + i) % len;
            ll l = balance[las];
            ll p = balance[pre];
            if (neg_num < 0) {
                if (neg_num + l >= 0) {
                    ans += (-neg_num * i);
                    return ans;
                }
                ans += l * i;
                neg_num += l;
            }
            if (neg_num < 0) {
                if (neg_num + p >= 0) {
                    ans += (-neg_num * i);
                    return ans;
                }
                ans += p * i;
                neg_num += p;
            }
        }
        return ans;
    }
};