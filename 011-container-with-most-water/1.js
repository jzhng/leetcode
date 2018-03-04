// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/description/

/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
  const n = height.length;
  let max = 0;
  for (let i = 0; i < n; i++ ) {
    for (let j = i + 1; j < n ; j++) {
      let area = Math.min(height[i], height[j]) * (j - i);
      if (area > max) {
        max = area;
      }
    }
  }
  return max;
};

const h1 = [1, 1, 2];
const h2 = [2, 3, 4, 1, 9, 11, 8, 2];

console.info(maxArea(h1));
console.info(maxArea(h2));
