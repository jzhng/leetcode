// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  const n = numbers.length;
  for (let i = 0; i < n; i ++) {
    for (let j = i + 1; j < n; j++) {
      if (numbers[i] + numbers[j] === target) {
        return [i+1, j+1];
      }
    }
  }
  return [0, 0];
};

const numbers = [ 2, 7, 11, 15];
const target = 9;
console.info(twoSum(numbers, target));
