/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
  let res = 0;
  let cur = 0;
  for (const i of nums) {
    if (i === 1) {
      cur++;
    } else {
      res = Math.max(res, cur);
      cur = 0;
    }
  }
  res = Math.max(res, cur);
  return res;
};

console.info(findMaxConsecutiveOnes([1,1,0,1,1,1]));

