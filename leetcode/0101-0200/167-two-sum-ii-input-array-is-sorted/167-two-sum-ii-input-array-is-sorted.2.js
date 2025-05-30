/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  const n = numbers.length;
  for (let i = 0; i < n; i ++) {
    let k = target - numbers[i];
    let l = i + 1, r = n -1;
    while (l <= r) {
      const m = l + Math.floor((r - l)/2);
      if (k === numbers[m]) {
        return [i+1, m+1];
      } else if ( k < numbers[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
  }
  return [0, 0];
};

const numbers = [ 2, 7, 11, 15];
const target = 9;
console.info(twoSum(numbers, target));
