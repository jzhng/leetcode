// 18. 4Sum
// https://leetcode.com/problems/4sum/description/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
  const res = [];
  nums = nums.sort((a, b) => a - b);

  for (let i = 0; i < nums.length - 3; i++) {
    if (i === 0 || nums[i] !== nums[i - 1] ) {
      for (let j = i + 1; j < nums.length - 2; j++) {
        if (j === i + 1 || nums[j] !== nums[j - 1]) {
          let complement = target - nums[i] - nums[j];
          let l = j + 1, r = nums.length - 1;
          while (l < r) {
            let sum = nums[l] + nums[r];
            if (sum === complement) {
              let quadruplet = [nums[i], nums[j], nums[l], nums[r]];
              res.push(quadruplet);
              while (l < r && nums[l] === quadruplet[2]) l++;
              while (l < r && nums[r] === quadruplet[3]) r--;
            } else if (sum < complement) {
              l++;
            } else {
              r--;
            }
          } 
        }
      }
    }
  }
  return res;
};

const nums1 = [ 1, 0, -1, 0, -2, 2], target1 = 0;
const nums2 = [-3, -2, -1, 0, 0, 1, 2, 3], target2 = 0;
console.info(fourSum(nums1, target1));
console.info(fourSum(nums2, target2));
