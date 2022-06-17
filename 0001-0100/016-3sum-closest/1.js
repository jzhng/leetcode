// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/description/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
  nums = nums.sort((a, b) => a - b);
  let min, closest = 0;

  for (let i = 0; i < nums.length - 2; i++) {
    let l = i + 1, r = nums.length - 1;
    while (l < r) {
      let sum = nums[i] + nums[l] + nums[r];
      let diff = Math.abs(sum - target);
      if (diff === 0) {
        return target;
      } else if (!min || diff < min) {
        min = diff;
        closest = sum;
      }      
      (sum < target) ? l++ : r--;
    }
  }
  return closest;
};

const nums1 = [-1, 2, -1, 4], target1 = 1;
const nums2 = [0, 1, 2], target2 = 3;
console.info(threeSumClosest(nums1, target1));
console.info(threeSumClosest(nums2, target2));
