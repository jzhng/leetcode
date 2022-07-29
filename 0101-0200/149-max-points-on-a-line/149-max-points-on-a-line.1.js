// 149. Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line/description/

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

  let max = 0;
  for (let i = 0; i < n - 1; i++) {
    for (let j = i+1; j < n; j++) {
      let num = 2;
      for (let k = 0; k < n; k++) {
        if (k === i || k === j) continue;
        if (samePoint(points[i], points[k]) || samePoint(points[j], points[k])) {
          num++;
        } else if (!samePoint(points[i], points[j]) &&
                    sameLine(points[i], points[j], points[k])) {
          num++;
        }
      }
      if (num > max) max = num;
    }
  }
  return max;
};

function sameLine(a, b, c) {
  return (b.x - a.x) * (c.y - a.y) === (c.x - a.x) * (b.y - a.y);
}

function samePoint(a, b) {
  return (a.x === b.x) && (a.y === b.y);
}

const p1 = [{x:0,y:0},{x:1,y:1},{x:2,y:2},{x:3,y:2}];
const p2 = [{x:84,y:250},{x:0,y:0},{x:1,y:0},{x:0,y:-70},{x:0,y:-70},{x:1,y:-1},{x:21,y:10},{x:42,y:90},{x:-42,y:-230}];
const p3 = [{x:1,y:1},{x:1,y:1},{x:1,y:1}];
 // fails on this as sameLine return true ..  94911151 * 94911151 === 94911150 * 94911152
const p4 = [{x:0,y:0},{x:94911151,y:94911150},{x:94911152,y:94911151}]
console.info(maxPoints(p1));
console.info(maxPoints(p2));
console.info(maxPoints(p3));
console.info(maxPoints(p4)); 
