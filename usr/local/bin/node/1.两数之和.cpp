/* 
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
Category	Difficulty	Likes	Dislikes
algorithms	Easy (52.81%)	15782	-
Tags
array | hash-table

Companies
adobe | airbnb | amazon | apple | bloomberg | dropbox | facebook | linkedin | microsoft | uber | yahoo | yelp

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
 */

// 1. 无序map容器
// 找索引unordered_map.find()：没找到返回尾后迭代器、存入容器；找到已存的键值对，返回vector{键，本次循环的数组下标}
// 注意：不需要先遍历数组建立哈希表，再遍历数组在哈希表里找值。
// （两个元素x，y必然是一前一后出现的，如果存在符合条件的解：
// 在遍历到x时，哈希表里没有符合的y，此时把x加入到了哈希表里；
// 当遍历到y时，就可以在哈希表里找到对应的x了。
// 所以只需要遍历查找，不需要遍历建表。）

// @lc code=start
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++){
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }       
        return {}; 
    }
};
// @lc code=end


/* 
// 0. 暴力穷举
// 双循环穷举所有组合
using namespace std
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
https://leetcode.cn/problems/two-sum/solutions/434597/liang-shu-zhi-he-by-leetcode-solution/
 */