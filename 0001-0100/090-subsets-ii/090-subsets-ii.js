// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/description/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function (nums) {
  function generateSubset(pos, subset) {
    res.push([...subset]);

    for (let i = pos; i < nums.length; i++) {
      if (i !== pos && nums[i] === nums[i - 1]) continue;
      subset.push(nums[i]);
      generateSubset(i + 1, subset);
      subset.pop();
    }
  }

  const res = [];
  nums.sort((a, b) => (a - b));
  generateSubset(0, []);
  return res;
};

console.info(subsetsWithDup([1, 2, 2]));
