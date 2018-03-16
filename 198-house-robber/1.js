// 198. House Robber
// https://leetcode.com/problems/house-robber/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  const n = nums.length;
  if (n === 0) return 0;

  const money = [ nums[0] ];
  for (let i = 1; i < n; i++) {
    money[i] = Math.max(money[i-1], (i >= 2 ? money[i-2] : 0) + nums[i]);
  }
  return money[n-1];
};

console.info(rob([1, 2, 3, 7, 6, 2, 8, 11, 2, 4]));
