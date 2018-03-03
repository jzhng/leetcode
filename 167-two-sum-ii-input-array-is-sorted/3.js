/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  let l = 0, r = numbers.length - 1;
  while (l < r) {
    const v = numbers[l] + numbers[r];
    if (v === target) {
      return [l+1, r+1];
    } else if (v < target) {
      l++;
    } else {
      r--;
    }
  }
};

const numbers = [ 2, 7, 11, 15];
const target = 9;
console.info(twoSum(numbers, target));
