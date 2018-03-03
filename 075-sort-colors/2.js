/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
  let zero = -1;            // nums[0...zero] === 0;
  let two = nums.length;    // nums[two..n-1] === 2;

  // quick sort 3 way, partition
  for (let i = 0; i < two;) {
    if (nums[i] === 1) {
      i++;
    } else if (nums[i] === 2) {
      let _t = nums[i];
      nums[i] = nums[--two];
      nums[two] = _t;
    } else { // nums[i] === 0
      let _t = nums[i];
      nums[i] = nums[++zero];
      nums[zero] = _t;
      i++;
    }
  }
};
