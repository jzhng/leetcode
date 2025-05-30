// 78. Subsets
// https://leetcode.com/problems/subsets/description/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function (nums) {
  function generateSubset(pos, subset) {
    if (pos === nums.length) {
      res.push([...subset]);
    } else {
      generateSubset(pos + 1, subset);
      subset.push(nums[pos]);
      generateSubset(pos + 1, subset);
      subset.pop();
    }
  }

  const res = [];
  generateSubset(0, []);
  return res;
};

console.info(subsets([1, 2, 4, 3]));
