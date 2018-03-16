// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/description/

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
  function tryPartition(nums, index, sum) {
    if (sum === 0) return true;
    if (sum < 0 || index < 0) return false;

    return (tryPartition(nums, index - 1, sum) ||
            tryPartition(nums, index - 1, sum - nums[index]));
  }

  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
  }
  if (sum % 2 !== 0) {
    return false;
  }
  return tryPartition(nums, nums.length - 1, sum / 2);
};

console.info(canPartition([1, 5, 11, 5]));
