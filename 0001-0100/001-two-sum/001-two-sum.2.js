/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  const map = new Map();
  for (let i = 0; i < nums.length; i++) {
    let complement = target - nums[i];
    if (map.has(complement)) {
      return [map.get(complement) , i];
    }
    map.set(nums[i], i)
  }
  throw new Error('no solution!');
};

const nums = [ 2, 7, 11, 15 ], target = 9;
console.info(twoSum(nums, target));
