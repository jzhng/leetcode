// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/description/

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
  function generateCombination(pos, c, target) {
    if (target === 0) {
      res.push([...c]);
    } else {
      for (let i = pos; i < candidates.length; i++) {
        const candidate = candidates[i];
        if (i !== pos && candidate === candidates[i - 1]) {
          continue;
        }
        if (target >= candidate) {
          c.push(candidate);
          generateCombination(i + 1, c, target - candidate);
          c.pop();
        }
      }
    }
  }

  const res = [];
  candidates.sort((a, b) => (a - b));
  generateCombination(0, [], target);
  return res;
};

console.info(combinationSum2([10, 1, 2, 7, 6, 1, 5], 8));
console.info(combinationSum2([3, 1, 3, 5, 1, 1], 8));
