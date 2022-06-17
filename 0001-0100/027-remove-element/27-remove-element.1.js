// 27. Remove Elemnt
// https://leetcode.com/problems/remove-element/description/

/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
  // oops, new array allocated.
  var arr = [];
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== val) {
      arr.push(nums[i]);
    }
  }

  for (let i = 0; i < arr.length; i++) {
    nums[i] = arr[i];
  }

  for (let i = nums.length; i > arr.length; i--) {
    nums.pop();
  }

  return nums.length;
};
