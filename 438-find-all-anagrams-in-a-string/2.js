/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
  const res = [], n = p.length, chrs = new Array(128).fill(0);

  for (let i = 0; i < n; i++) {
    chrs[p.charCodeAt(i)]++;
  }

  let l = 0, r = 0, count = p.length;
  while (r < s.length) {
    if (r - l === p.length && chrs[s.charCodeAt(l++)]++ >= 0) {
      count++;
    }

    if (chrs[s.charCodeAt(r++)]-- >= 1) {
      count--;
    }

    if (count === 0) {
      res.push(l);
    }
  }
  return res;
};

const s1 = 'abab', p1 = 'ab';
const s2 = 'cbaebabacd', p2 = 'abc';
const s3 = 'ababababab', p3 = 'aab';

console.info(findAnagrams(s1, p1));
console.info(findAnagrams(s2, p2));
console.info(findAnagrams(s3, p3));
