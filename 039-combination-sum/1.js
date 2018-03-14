// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/description/

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {

  function findCombination(pos, c, target) {
    if (target === 0) {
      res.push([...c])
    } else {
      for (let i = pos; i < candidates.length; i++) {
        const candidate = candidates[i];
        const last = c[c.length - 1] || 0;
        if (candidate < last) continue;
        if (target >= candidate) {
          c.push(candidate);
          findCombination(pos, c, target - candidate);
          c.pop(candidates);
        }
      }
    }
  }

  const res = [];
  candidates.sort((a, b) => (a - b));
  findCombination(0, [], target);
  return res;
};

// console.info(combinationSum([2,3,6,7], 7));
console.info(combinationSum([1, 2], 4));
