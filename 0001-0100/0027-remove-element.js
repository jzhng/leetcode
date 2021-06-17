/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
  let i = 0;
  let j = 0;

  while (i < nums.length) {
    if (nums[i] !== val) {
      nums[j++] = nums[i];
    }
    i++;
  }

  return j;

};

// const nums = [2, 2, 3, 3];
// const val = 2;

// const nums = [3, 2, 2, 3];
// const val = 3;

const nums = [0,1,2,2,3,0,4,2];
const val = 2;

console.info(removeElement(nums, val));
console.info(nums);
