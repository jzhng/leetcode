// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

// https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/description/

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        for (int i = 0; i < documents.size(); ++i) {
            while (documents[i] != i) {
                int &doc = documents[i];
                if (doc == documents[doc]) {
                    return doc;
                }
                swap(doc, documents[doc]);
            }
        }
        return -1;
    }
};

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

// https://leetcode.cn/problems/find-the-duplicate-number/description/

// 二分