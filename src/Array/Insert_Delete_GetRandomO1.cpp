// https://leetcode.com/problems/insert-delete-getrandom-o1/
#include "common.h"

class RandomizedSet {
public:
    // 存储元素的值
    vector<int> nums;
    // 记录每个元素对应在nums中的索引
    unordered_map<int, int> valToIndex;

    RandomizedSet() {
        
    }

    bool insert(int val) {
        if (valToIndex.count(val)) {
            return false;
        }

        // 将val插入到nums尾部，并记录val对应的索引值
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!valToIndex.count(val)) {
            return false;
        }

        int index = valToIndex[val];

        // 将最后一个元素对应的索引修改为index
        valToIndex[nums.back()] = index;
        // 交换val和最后一个元素
        swap(nums[index], nums.back());
        // 在数组中删除元素val
        nums.pop_back();
        // 删除元素val对应的索引
        valToIndex.erase(val);

        return true;
    }

    int getRandom() {
        // 随机获取nums中的一个元素
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(void)
{
    RandomizedSet* obj = new RandomizedSet();

    cout << "Insert Delete GetRandom. " << endl;

    cout << "insert 1 : " << obj->insert(1) << endl;

    cout << "remove 2 : " << obj->remove(2) << endl;

    cout << "insert 2 : " << obj->insert(2) << endl;

    cout << "getRandom: " << obj->getRandom() << endl;

    cout << "remove 1 : " << obj->remove(1) << endl;

    cout << "insert 2 : " << obj->insert(2) << endl;

    cout << "getRandom: " << obj->getRandom() << endl;

    return 1;
}