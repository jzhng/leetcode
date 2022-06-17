// 136. Single Number
// https://leetcode.com/problems/single-number/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  const set = new Set();
  nums.forEach(num => {
    if (set.has(num)) {
      set.delete(num);
    } else {
      set.add(num);
    }
  });

  return set.values().next().value;
};

console.info(singleNumber([1, 3, 2, 1, 2]));
