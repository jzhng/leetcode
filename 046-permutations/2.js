/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
  function generatePermutation(pos) {
    if (pos === nums.length) {
      res.push(nums.slice());
      return;
    }

    for (let i = pos; i < nums.length; i++) {
      swap(nums, pos, i);
      generatePermutation(pos + 1);
      swap(nums, pos, i);
    }
  }

  function swap(nums, i, j) {
    const _t = nums[i];
    nums[i] = nums[j];
    nums[j] = _t;
  }

  const res = [];
  generatePermutation(0);
  return res;
};

console.info(permute([1, 2, 3]));
