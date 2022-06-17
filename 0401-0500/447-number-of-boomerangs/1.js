// 447. Number of Boomerangs
// https://leetcode.com/problems/number-of-boomerangs/description/

/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfBoomerangs = function(points) {
  let res  = 0;

  for (let i = 0; i < points.length; i++) {
    let rcd = new Map();
    for (let j = 0; j< points.length; j++) {
      if (j !== i) {
        let d = dis(points[i], points[j]);
        let cnt = rcd.get(d) || 0;
        rcd.set(d, cnt + 1);
      }
    }

    for (let v of rcd.values()) {
      res += v * (v-1);
    }
  }
  return res;
};

function dis(a, b) {
  return Math.pow((a[0] - b[0]), 2) + Math.pow((a[1] - b[1]), 2);
}

const points = [[0,0],[1,0],[2,0]];
console.info(numberOfBoomerangs(points));

