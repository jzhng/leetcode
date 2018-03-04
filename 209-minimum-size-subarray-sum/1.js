// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/description/

/**
 * @param {number} s
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(s, nums) {
  const n = nums.length;
  let len = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      let sum = 0;
      for (let k = i; k <= j; k++) {
        sum += nums[k];
      }

      if (sum >= s) {
        len = (len === 0 ? j - i + 1: Math.min(len, j - i + 1));
      }
    }
  }
  return len;
};

const s1 = 7, nums1 = [2, 3, 1, 2, 4, 3];
const s2 = 4, nums2 = [1, 4, 4];
console.info(minSubArrayLen(s1, nums1));
console.info(minSubArrayLen(s2, nums2));
