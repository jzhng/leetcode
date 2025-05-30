/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
  const arr = new Array(nums.length).fill(0);
  const res = [];
  for (let i = 0; i < nums.length; i++) {
    arr[nums[i] - 1]++;
  }
  for (let i = 0; i < nums.length; i++) {
    if (!arr[i]) res.push(i + 1);
  }
  return res;
};
