// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/description/

/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function(s) {
  function sliceString(pos, subs) {
    if (pos === s.length) return res.push(subs);
    for (let i = 1; i + pos <= s.length; i++) {
      if (isPali(s, pos, pos + i - 1)) {
        sliceString(pos + i, [...subs, s.slice(pos, pos + i)]);
      }
    }
  }
  
  function isPali(s, l, r) {
    while (l < r) {
      if (s[l++] !== s[r--]) return false;
    }
    return true;
  }

  const res = [];
  sliceString(0, []);
  return res;
};

console.info(partition('ababcc'));
