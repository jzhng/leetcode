// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/description/

/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
var combinationSum3 = function(k, n) {
  function generateCombination(count, pos, c, n) {
    if (count === k) {
      if (n === 0) res.push([...c]);
    } else {
      for (let i = pos; i < 10; i++) {
        c.push(i);
        generateCombination(count+1, i+1, c, n - i);
        c.pop(i);
      }
    }
  }

  const res = [];
  generateCombination(0, 1, [], n);
  return res;
};

console.info(combinationSum3(3, 7));
console.info(combinationSum3(3, 9));
