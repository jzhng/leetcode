// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/description/

/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
  const n = t.length, map = new Array(128).fill(0);
  for (let i = 0; i < n; i++) {
    map[t.charCodeAt(i)]++;
  }

  let l = 0, r = 0, count = n;
  let h = 0, len = s.length + 1;
  while (r < s.length) {
    if (map[s.charCodeAt(r++)]-- > 0) {
      count--;
    }

    while (count === 0) {
      if (len > r - l) {
        len = r - l;
        h = l;
      }
      if (map[s.charCodeAt(l++)]++ === 0) {
        count++;
      }
    }
  }
  return len === s.length + 1 ? '' : s.slice(h, h + len);
};

const s = 'ADOBECODEBANC', t = 'ABC';
console.info(minWindow(s, t));
