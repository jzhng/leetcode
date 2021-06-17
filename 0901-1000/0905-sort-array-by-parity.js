/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function(nums) {
  let l = 0;
  let r = nums.length - 1;

  while (l < r) {
    while (nums[l] % 2 === 0 && l < nums.length) l++;
    while (nums[r] % 2 && r >= 0) r--;
    if (l < r) {
      let tmp = nums[l];
      nums[l] = nums[r];
      nums[r] = tmp;
    }
  }
  return nums;
};
