/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
var fourSumCount = function(A, B, C, D) {
  const rcd = new Map();
  const n = A.length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      let sum = A[i] + B[j];
      let count = rcd.get(sum) || 0;
      rcd.set(sum, ++count);
    }
  }

  let res = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      res += (rcd.get(-C[i] - D[j]) || 0);
    }
  }
  return res;
};

const A = [ 1, 2], B = [-2,-1], C = [-1, 2], D = [ 0, 2];
console.info(fourSumCount(A, B, C, D));
