/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
  function tryPartition(nums, index, sum) {
    if (sum === 0) return true;
    if (sum < 0 || index < 0) return false;

    if (memo[index][sum] !== -1) {
      return memo[index][sum] === 1;
    }

    memo[index][sum] = (tryPartition(nums, index - 1, sum) ||
            tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;
    return memo[index][sum] === 1;
  }

  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
  }
  if (sum % 2) {
    return false;
  }

  const memo = [], size = sum / 2 + 1;
  for (let i = 0; i < nums.length; i++) {
    memo.push(new Array(size).fill(-1));
  }
  return tryPartition(nums, nums.length - 1, sum / 2);
};

console.info(canPartition([1, 5, 11, 5]));
