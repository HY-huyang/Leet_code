// 0001 两数之和
int main() {
    vector<int>num = { 2,7,11,15 };
    int k = 9;
    vector<int>res = Solution().twoSum(num, k);
    cout << res;
}

// 0016 最接近的三数之和
int main() {
    vector<int>num = { -1,2,1,-4 };
    int k = 1;
    cout << Solution().threeSumClosest(num, k);
}

// 0027 移除元素
int main() {
    vector<int>num = { 0,1,2,2,3,0,4,2 };
    int k = 2;
    cout << Solution().removeElement(num, k);
}