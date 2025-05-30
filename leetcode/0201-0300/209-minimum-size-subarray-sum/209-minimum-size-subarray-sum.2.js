/**
 * @param {number} s
 * @param {number[]} nums
 * @return {number}
 * optimize brute force solution to O(n2)
 */
var minSubArrayLen = function(s, nums) {
  const n = nums.length;
  let len = n + 1;

  for (let i = 1; i < n; i++) {
    sums[i] = sums[i - 1] + nums[i];
  }

  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      let sum = sums[j] - sums[i] + nums[i];
      if (sum >= s) {
        len = Math.min(len, j - i + 1);
      }
    }
  }
  return (len === n + 1 ? 0 : len);
};

const s1 = 7, nums1 = [2, 3, 1, 2, 4, 3];
const s2 = 4, nums2 = [1, 4, 4];
console.info(minSubArrayLen(s1, nums1));
console.info(minSubArrayLen(s2, nums2));
