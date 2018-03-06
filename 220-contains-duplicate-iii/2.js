/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
  if (t < 0 || k < 1) return false;

  const rcd = new Map();
  const w = t + 1;
  for (let i = 0; i < nums.length; i++) {
    let n = nums[i];
    let id = Math.floor(n / w);
    if (rcd.has(id) ||
        rcd.has(id - 1) && (Math.abs(n - rcd.get(id-1)) < w) ||
        rcd.has(id + 1) && (Math.abs(n - rcd.get(id+1)) < w)) {
      return true;
    }

    rcd.set(id, n);
    if (i >= k) {
      rcd.delete(Math.floor(nums[i-k] / w ));
    }
  }
  return false;
};

const nums1 = [ 2, 4, 6, 4, 2], k1 = 1, t1 = 1;
const nums2 = [-1, -1], k2 = 1, t2 = 0;
const nums3 = [2, 1], k3 = 1, t3 = 1;
const nums4 = [-1, -1], k4 = 1, t4 = -1;
console.info(containsNearbyAlmostDuplicate(nums1, k1, t1));
console.info(containsNearbyAlmostDuplicate(nums2, k2, t2));
console.info(containsNearbyAlmostDuplicate(nums3, k3, t3));
console.info(containsNearbyAlmostDuplicate(nums4, k4, t4));
