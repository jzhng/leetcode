// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/description/

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
  s = s.split('');
  t = t.split('');

  const map = new Map();
  for (let i = 0; i < s.length; i++) {
    const c = s[i];
    if (!map.has(c)) {
      map.set(c, t[i]);
    } else if (map.get(c) !== t[i]) {
      return false;
    }
  }

  const k = new Set(map.keys());
  const v = new Set(map.values());
  return k.size === v.size;
};

const s1 = 'title', t1 = 'paper';
const s2 = 'ab', t2 = 'aa';
console.info(isIsomorphic(s1, t1));
console.info(isIsomorphic(s2, t2));
