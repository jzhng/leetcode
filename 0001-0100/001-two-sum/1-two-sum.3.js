/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  const map = {};
  for (let j = 0; j < nums.length; j++) {
    let i = map[target - nums[j]];
    if (typeof i === 'number') {
      return [i, j];
    }
    map[nums[j]] = j;
  }
  throw new Error('no solution!');
};

const nums = [ 2, 7, 11, 15 ], target = 9;
console.info(twoSum(nums, target));
