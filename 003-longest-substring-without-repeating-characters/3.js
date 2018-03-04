/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  const n = s.length;
  const map = new Map();
  let len = 0;

  for (let j = 0, i = 0; j < n; j++) {
    if (map.has(s[j])) {
      i = Math.max(map.get(s[j]), i);
    }
    len = Math.max(len, j - i + 1);
    map.set(s[j], j + 1);
  }

  return len;
};

const s1 = 'abcabccbb';
const s2 = 'bbbbb';
console.info(lengthOfLongestSubstring(s1));
console.info(lengthOfLongestSubstring(s2));
