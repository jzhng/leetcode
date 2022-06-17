// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/description/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
  const res = [], bucket =[], freq = new Map();
  for (let i = 0; i < nums.length; i++) {
    let num = nums[i];
    freq.set(num, (freq.get(num) || 0) + 1);
  }

  for (let [key, value] of freq.entries()) {
    bucket[value] = bucket[value] || [];
    bucket[value].push(key);
  }

  for (let i = bucket.length - 1; i >= 0 && res.length < k; i--) {
    if (bucket[i]) {
      res.push(...bucket[i]);
    }
  }
  return res;
};

console.info(topKFrequent([1,1,1,2,2,3], 2));
