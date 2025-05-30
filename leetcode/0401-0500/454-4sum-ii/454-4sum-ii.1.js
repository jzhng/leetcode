// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/description/

/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
var fourSumCount = function(A, B, C, D) {
  const rcd = {};
  for (let i = 0; i < A.length; i++) {
    for (let j = 0; j < B.length; j++) {
      let sum = A[i] + B[j];
      rcd[sum] = rcd[sum] || 0;
      rcd[sum]++;
    }
  }

  let res = 0;
  for (let i = 0; i < C.length; i++) {
    for (let j = 0; j < D.length; j++) {
      let target = -C[i] - D[j];
      if (typeof rcd[target] === 'number') {
        res += rcd[target];
      }
    }
  }
  return res;
};

const A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2];
console.info(fourSumCount(A, B, C, D));
