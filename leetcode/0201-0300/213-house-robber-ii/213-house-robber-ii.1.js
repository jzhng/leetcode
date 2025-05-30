// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  const n = nums.length;
  if (n === 0) return 0;
  if (n === 1) return nums[0];

  const withFirst = [ nums[0] ];
  for (let i = 1; i < n-1; i++) {
    withFirst[i] = Math.max(withFirst[i-1], (i >= 2 ? withFirst[i-2] : 0) + nums[i]);
  }
  const noFirst = [ 0, nums[1] ];
  for (let i = 2; i < n; i++) {
    noFirst[i] = Math.max(noFirst[i-1], noFirst[i-2] + nums[i]);
  }

  return Math.max(withFirst[n-2], noFirst[n-1]);
};

console.info(rob([2, 2, 4]));
