// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
  // asume quick sort, O(nlogn);
  nums.sort((a, b) => (b - a));
  return nums[k - 1];
};

let nums = [3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6];
console.info(findKthLargest(nums, 2));
