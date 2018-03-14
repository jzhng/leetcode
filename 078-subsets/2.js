/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function (nums) {
  function generateSubset(pos, subset) {
    res.push([...subset]);
    for (let i = pos; i < nums.length; i++) {
      subset.push(nums[i]);
      generateSubset(i+1, subset);
      subset.pop();
    }
  }

  const res = [];
  generateSubset(0, []);
  return res;
};

console.info(subsets([1, 2, 4, 3]));
