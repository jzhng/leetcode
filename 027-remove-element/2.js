/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
  let k = 0;
  let len = nums.length;

  for (let i = 0; i < len; i++) {
    if (nums[i] === val) {
      // found k items equal to val, try to swap to some
      // value that not equals to it.
      let j = len - 1;
      while (j > i && nums[j] === val) {
        j--;
      }

      if (j > i) {
        let _t = nums[i];
        nums[i] = nums[j];
        nums[j] = _t;
      } else {
        k++;  // only increase k if can't swap
      }
    }
  }
  nums.splice(len - k , k);
  return nums.length;
};
