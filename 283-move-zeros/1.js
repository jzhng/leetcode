// 283. Move zeros
// https://leetcode.com/problems/move-zeroes/description/

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  let k = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i]) {
      nums[k++] = nums[i];
    }
  }

  for (let i = k; i < nums.length; i++) {
    nums[i] = 0;
  }
};
