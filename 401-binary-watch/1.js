// 401. Binary Watch
// https://leetcode.com/problems/binary-watch/description/

/**
 * @param {number} num
 * @return {string[]}
 */
var readBinaryWatch = function(num) {
  function generateTime(pos, count, h, m) {
    if (count === num) {
      res.push(`${h}:${m < 10 ? `0${m}`: m}`);
    } else {
      for (let i = pos; i < 11; i++) {
        let dH = 0, dM = 0;
        if (i < 5) {
          dH = Math.pow(2, 4 - i);
          if (h + dH > 11) continue;
          h += dH;
        } else {
          dM = Math.pow(2, 10 - i);
          if (m + dM > 59) continue;
          m += dM;
        }
        generateTime(i + 1, count + 1, h, m);
        h -= dH;
        m -= dM;
      }
    }
  }

  const res = [];
  generateTime(1, 0, 0, 0);
  return res;
};

console.info(readBinaryWatch(1));
// console.info(readBinaryWatch(2));
