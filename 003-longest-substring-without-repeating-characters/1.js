// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  const n = s.length;
  let l = 0, r = -1, len = 0;
  let freq = [];
  
  while (l < n) {
    if (r < n - 1 && !freq[s[r+1]]) {
      ++r;
      if (freq[s[r]] === 0) {
        freq[s[r]]++;
      } else {  // undefined
        freq[s[r]] = 1;
      }
    } else {
      freq[s[l++]]--;
    }
    len = Math.max(len, r - l + 1);
  }
  return len;
};

const s1 = 'abcabccbb';
const s2 = 'bbbbb';
console.info(lengthOfLongestSubstring(s1));
console.info(lengthOfLongestSubstring(s2));
