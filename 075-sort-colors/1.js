// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/description/

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
  let count = [0, 0, 0];
  for (let n of nums) {
    count[n]++;
  }

  let index = 0;
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < count[i]; j++) {
      nums[index++] = i;
    }
  }
};
