// 15. 3Sum
// https://leetcode.com/problems/3sum/description/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
  const pairs = new Map(), res = [];

  nums = nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length; i++) {
    let indexes = {};
    for (let j = 0; j < nums.length; j++) {
      if (j === i) continue;

      let complement = -nums[i] - nums[j];
      let idx = indexes[complement];
      if (typeof idx === 'number') {
        let arr = [nums[i], nums[j], complement].sort((a, b) => a - b);
        let key = arr.reduce((a, b) => a + b, '');
        if (!pairs.has(key)) {
          pairs.set(key, arr);
        }
      }
      indexes[nums[j]] = j;
    }
  }

  for (let v of pairs.values()) {
    res.push(v);
  }
  return res;
};

const nums1 = [ -1, 0, 1, 2, -1, -4];
const nums2 = [-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1];
console.info(threeSum(nums1));
console.info(threeSum(nums2)); // got WA as answer not sorted, but should pass.
