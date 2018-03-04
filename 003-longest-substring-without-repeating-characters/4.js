/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  const n = s.length;
  const index = [];
  let len = 0;

  for (let j = 0, i = 0; j < n; j++) {
    i = Math.max(index[s[j]] ? index[s[j]] : 0, i);
    len = Math.max(len, j - i + 1);
    index[s[j]] = j + 1;
  }

  return len;
};

const s1 = 'abcabccbb';
const s2 = 'bbbbb';
console.info(lengthOfLongestSubstring(s1));
console.info(lengthOfLongestSubstring(s2));
