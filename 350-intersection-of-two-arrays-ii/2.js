/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  const rcd = [], res = [];
  for (let i = 0; i < nums1.length; i++) {
    let v = nums1[i];
    rcd[v] = rcd[v] || 0;
    rcd[v]++;
  }

  for (let i = 0; i < nums2.length; i++) {
    let v = nums2[i];
    if (rcd[v]) {
      rcd[v]--;
      res.push(v);
    }
  }
  return res;
};

const nums1 = [1, 2, 2, 1], nums2 = [2, 2];
console.info(intersect(nums1, nums2));
