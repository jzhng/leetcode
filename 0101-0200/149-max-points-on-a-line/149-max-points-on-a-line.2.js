/**
 * Definition for a point.
 * function Point(x, y) {
 *     this.x = x;
 *     this.y = y;
 * }
 */
/**
 * @param {Point[]} points
 * @return {number}
 */
var maxPoints = function(points) {
  const n = points.length;
  if (n < 3) {
    return n;
  }

  let res = 0, rcd = new Map();
  for (let i = 0; i < n - 1; i++) {
    let num = 1, maxSlope = 0;
    rcd.clear();
    for (let j = i + 1; j < n; j++) {
      let dx = points[i].x - points[j].x;
      let dy = points[i].y - points[j].y;
      if (dx === 0 && dy === 0) {
        num++;
        continue;
      }
      let dd = gcd(dx, dy);
      const key = `${dy/dd}/${dx/dd}`;
      let cnt = rcd.get(key) || 0;
      rcd.set(key, ++cnt);
      maxSlope = Math.max(maxSlope, cnt);
    }
    res = Math.max(res, maxSlope + num);
  }
  return res;
};

function gcd(a, b) {
  if (b === 0) {
    return a;
  }
  return gcd(b, a % b);
}

const p1 = [{x:0,y:0},{x:1,y:1},{x:2,y:2},{x:3,y:2}];
const p2 = [{x:84,y:250},{x:0,y:0},{x:1,y:0},{x:0,y:-70},{x:0,y:-70},{x:1,y:-1},{x:21,y:10},{x:42,y:90},{x:-42,y:-230}];
const p3 = [{x:1,y:1},{x:1,y:1},{x:1,y:1}];
const p4 = [{x:0,y:0},{x:94911151,y:94911150},{x:94911152,y:94911151}]
console.info(maxPoints(p1));
console.info(maxPoints(p2));
console.info(maxPoints(p3));
console.info(maxPoints(p4)); 
