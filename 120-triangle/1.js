// 120. Triangle
// https://leetcode.com/problems/triangle/description/

/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  function findPath(index, pos, sum) {
    if (index === n) {
      if (min > sum) min = sum;
    } else {
      for (let i = pos; i < pos + 2; i++) {
        findPath(index + 1, i, sum + triangle[index][pos]);
      }
    }
  }

  const n = triangle.length;
  let min = Number.MAX_VALUE;

  findPath(0, 0, 0);
  return min;
};

const triangle = [
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
];

console.info(minimumTotal(triangle));
