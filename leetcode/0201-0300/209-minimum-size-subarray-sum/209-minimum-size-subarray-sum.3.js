/**
 * @param {number} s
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function(s, nums) {
  const n = nums.length;
  let l = 0, r = -1, sum = 0, len = n + 1;

  while (l < n) {
    if (sum < s && r + 1 < n) {
      sum += nums[++r];
    } else {
      sum -= nums[l++]
    }

    if (sum >= s) {
      len = Math.min(len, r - l + 1);
    }
  }
  return (len === n + 1 ? 0 : len);
};

const s1 = 7, nums1 = [2, 3, 1, 2, 4, 3];
const s2 = 4, nums2 = [1, 4, 4];
console.info(minSubArrayLen(s1, nums1));
console.info(minSubArrayLen(s2, nums2));
