/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  function minLevelPos(level, pos) {
    if (level === 0) return triangle[0][0];

    if (pos === 0) {
      return minLevelPos(level - 1, 0) + triangle[level][0];
    } else if (pos === level) {
      return minLevelPos(level - 1, level - 1) + triangle[level][pos];
    }  else {
      return Math.min(minLevelPos(level-1, pos-1) + triangle[level][pos],
                      minLevelPos(level-1, pos) + triangle[level][pos]);
    }
  }

  const n = triangle.length;
  let min = Number.MAX_VALUE;
  for (let i = 0; i < n; i++) {
    const sum = minLevelPos(n-1, i);
    if (min > sum) min = sum;
  }
  return min;
};

const triangle = [
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
];

console.info(minimumTotal(triangle));
