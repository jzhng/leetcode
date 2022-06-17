// 46. Permutations
// https://leetcode.com/problems/permutations/description/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
  function generatePermutation(index) {
    if (index === nums.length) {
      res.push([...p]);
      return;
    }

    for (let i = 0; i < nums.length; i++) {
      if (!used[i]) {
        p.push(nums[i]);
        used[i] = true;
        generatePermutation(index + 1);
        used[i] = false;
        p.pop();
      }
    }
  }

  const res = [], p = [], used = new Array(nums.length).fill(false);
  generatePermutation(0);
  return res;
};

console.info(permute([1, 2, 3]));
