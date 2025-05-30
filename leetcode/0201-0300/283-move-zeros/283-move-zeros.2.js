//  Operation optimal

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  let k = 0;
  for (let i = 0; i < nums.length; i++) {
    // may test if i equals k, but not that neccessary.
    if (nums[i]) {
      let _t = nums[k];
      nums[k++] = nums[i];
      nums[i] = _t;
    }
  }
};
