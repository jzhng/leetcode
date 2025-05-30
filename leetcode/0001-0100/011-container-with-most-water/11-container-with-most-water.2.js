/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
  let l = 0, r = height.length - 1, max = 0;
  while (l < r) {
    // max = Math.max(max, Math.min(height[l], height[r]) * (r - l));
    let area = Math.min(height[l], height[r]) * (r - l);
    if (area > max) {
      max = area;
    }
    if (height[l] < height[r]) {
      l++;
    } else {
      r--;
    }
  }
  return max;
};

const h1 = [1, 1, 2];
const h2 = [2, 3, 4, 1, 9, 11, 8, 2];

console.info(maxArea(h1));
console.info(maxArea(h2));
