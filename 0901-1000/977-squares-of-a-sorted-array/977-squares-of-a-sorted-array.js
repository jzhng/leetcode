/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
  const res = [];
  let r = 0;
  for (let num of nums) {
    if (num <= 0) {
      r++;
    }
  }

  let l = r - 1;
  const length = nums.length;
  while (l >= 0 || r < length) {
    if (l < 0) {
      for (; r < length; r++) {
        res.push(nums[r] * nums[r]);
      }
    } else if (r > length - 1) {
      for (; l >= 0; l--) {
        res.push(nums[l] * nums[l]);
      }
    } else {
      if (-nums[l] > nums[r]) {
        res.push(nums[r] * nums[r]);
        r++;
      } else {
        res.push(nums[l] * nums[l]);
        l--;
      }
    }
  }
  return res;
};

console.info(sortedSquares([-4, -1, 0, 3, 10]));
console.info(sortedSquares([1]));
console.info(sortedSquares([2, 2]));
