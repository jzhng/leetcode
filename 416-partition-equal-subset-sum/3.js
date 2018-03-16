/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
  const n = nums.length;
  let sum = 0;
  for (let i = 0; i < n; i++) {
    sum += nums[i];
  }
  if (sum % 2) {
    return false;
  }

  const size = sum / 2;
  const memo = new Array(size + 1).fill(false);
  for (let i = 0; i <= size; i++) {
    memo[i] = (nums[0] === i);
  }

  for (let i = 1; i < n; i++) {
    for (let j = size; j >= nums[i]; j--) {
      memo[j] = memo[j] || memo[j - nums[i]];
    }
  }
  return memo[size];
};

console.info(canPartition([1, 5, 11, 5]));
