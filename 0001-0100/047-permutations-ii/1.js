// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/description/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
  function generatePermuatation() {
    if (p.length === nums.length) {
      res.push([...p]);
    } else {
      for (let i = 0; i < nums.length; i++) {
        if (!used[i]) {
          if (i > 0 && nums[i-1] === nums[i] && !used[i-1]) {
            continue;
          }
          used[i] = true;
          p.push(nums[i]);
          generatePermuatation();
          p.pop();
          used[i] = false;
        }
      }
    }
  }

  function swap(nums, i, j) {
    const _t = nums[i];
    nums[i] = nums[j];
    nums[j] = _t;
  }

  const res = [], p = [], used = new Array(nums.length).fill(false);
  nums.sort((a, b) => (a - b));
  generatePermuatation(0);
  return res;
};

// console.info(permuteUnique([1,1,2]));
// console.info(permuteUnique([0,1,0,0,9]));
console.info(permuteUnique([-1,2,0,-1,1,0,1]));
