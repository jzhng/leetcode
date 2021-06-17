/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
  nums.sort((a, b) => b - a);
  
  let k = 1;
  for (let i = 1; i < nums.length; i++) {
      if (nums[i-1] !== nums[i]) {
          k++;
      }
      if (k === 3) return nums[i];
  }
  return nums[0];
};

// const nums = [3, 2, 1];
const nums = [1, 2];
console.info(thirdMax(nums));
