// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  function doRob(nums, l, r) {
    let pre = 0, curr = 0;
    for (let i = l; i <= r; i++) {
      let _t = Math.max(pre + nums[i], curr);
      pre = curr;
      curr = _t;
    }
    return curr;
  }

  const n = nums.length;
  if (n === 0) return 0;
  if (n === 1) return nums[0];

  return Math.max(doRob(nums, 0, n - 2), doRob(nums, 1, n - 1));
};

console.info(rob([2, 2, 4]));
