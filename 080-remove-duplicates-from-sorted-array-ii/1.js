// 80. Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

/*
* @param {number[]} nums
* @return {number}
*/
var removeDuplicates = function(nums) {
  let i = 1;
  let n = nums.length;
  for (let j = 1; j < n; j++) {
    if (nums[i - 1] !== nums[j] || nums[i - 2] !== nums[j]) {
      nums[i++] = nums[j];
    }
  }
  return i;
};

let nums = [1, 1, 1, 1, 2, 3, 3];
console.info(removeDuplicates(nums));
