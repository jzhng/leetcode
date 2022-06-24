// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  const rcd = new Map(), res = [];
  for (let i = 0; i < nums1.length; i++) {
    let v = nums1[i];
    rcd.set(v, rcd.has(v) ? rcd.get(v) + 1 : 1);
  }

  for (let i = 0; i < nums2.length; i++) {
    let v = nums2[i];
    if (rcd.has(v)) {
      let n = rcd.get(v);
      rcd.set(v, --n);
      res.push(v);
      if (!n) {
        rcd.delete(v);
      }
    }
  }
  return res;
};

const nums1 = [1, 2, 2, 1], nums2 = [2, 2];
console.info(intersect(nums1, nums2));

