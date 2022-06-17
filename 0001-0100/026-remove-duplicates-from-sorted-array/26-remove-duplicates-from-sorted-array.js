// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  let i = 0;
  let j = 0;

  while (i < nums.length) {
    if (nums[i] !== nums[i + 1]) {
      nums[j++] = nums[i];
    }
    i++;
  }

  return j;
};

const nums = [1,1,2];
console.info(removeDuplicates(nums));
console.info(nums);
