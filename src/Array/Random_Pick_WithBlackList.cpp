// https://leetcode.com/problems/random-pick-with-blacklist/
#include "common.h"

class Solution {
public:
    vector<int> bl;
    int num;
    int size;
    unordered_map<int, int> valToIndex;

    Solution(int n, vector<int>& blacklist) {
        num = n;
        bl = blacklist;
        size = n - blacklist.size();
        // 先将所有黑名单数字加入map
        for (auto b : blacklist) {
            // 这里赋值多少都可以，目的仅仅是把键存进哈希表，方便快速判断数字是否在黑名单内
            valToIndex[b] = 777;
        }

        int last = n - 1;
        for (auto b : blacklist) {
            // 如果b已经在区间[size, num)中可以直接忽略
            if (b >= size) {
                continue;
            }
            // 跳过所有黑名单中的数字
            while (valToIndex.count(last)) {
                last--;
            }
            // 将黑名单中的索引值映射到合法数字
            valToIndex[b] = last;
            last--;
        }
    }

    int pick() {
        int index = rand() % size;
        // 这个索引命中了黑名单，需要被映射到其他位置
        if (valToIndex.count(index)) {
            return valToIndex[index];
        }

        // 若没命中黑名单，则直接返回
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
int main(void)
{
    vector<int> blackList = {2, 3, 5};
    Solution* res = new Solution(7, blackList);

    cout << "Random Pick With Blacklist. " << endl;

    cout << "Num: 7, blackList:";
    printNums(blackList); 

    cout << "pick : " << res->pick() << endl;

    cout << "pick : " << res->pick() << endl;

    cout << "pick : " << res->pick() << endl;

    cout << "pick : " << res->pick() << endl;

    cout << "pick : " << res->pick() << endl;

    cout << "pick : " << res->pick() << endl;

    cout << "pick : " << res->pick() << endl;

    return 1;
}