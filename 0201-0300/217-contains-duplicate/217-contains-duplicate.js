// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/description/

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
  const rcd = new Set();
  for (let n of nums) {
    if (rcd.has(n)) {
      return true;
    } else {
      rcd.add(n);
    }
  }
  return false;
};
