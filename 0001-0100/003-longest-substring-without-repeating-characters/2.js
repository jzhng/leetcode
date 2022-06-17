/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  const n = s.length;
  const set = new Set();
  let l = 0, r = -1, len = 0;  // [l, r)

  while (l < n && r < n) {
    if (!set.has(s[r])) {
      set.add(s[r++]);
      len = Math.max(len, r - l);
    } else {
      set.delete(s[l++]);
    }
  }
  return len;
};

const s1 = 'abcabccbb';
const s2 = 'bbbbb';
console.info(lengthOfLongestSubstring(s1));
console.info(lengthOfLongestSubstring(s2));
