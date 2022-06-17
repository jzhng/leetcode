/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  const set = new Set();
  for (let i = 0; i < nums.length; i++) {
    if (set.has(nums[i])) {
      set.delete(nums[i]);
    } else {
      set.add(nums[i]);
    }
  }
  return set.values().next().value;
};

console.info(singleNumber([1, 3, 2, 1, 2]));
