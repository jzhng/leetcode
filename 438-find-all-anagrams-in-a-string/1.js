// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
  const res = [];
  const pMap = mapChrs(p, 0, p.length - 1);
  for (let l = 0, r = p.length - 1; r < s.length; l++, r++) {
    let map = mapChrs(s, l, r);
    if (sameMap(pMap, map)) {
      res.push(l);
    }
  }
  return res;
};

function mapChrs(s, l, r) {
  const map = new Map();
  for (let i = l; i <= r; i++) {
    map.set(s[i], map.has(s[i]) ? map.get(s[i]) + 1 : 1 );
  }
  return map;
}

function sameMap(a, b) {
  if (a.size !== b.size) {
    return false;
  }

  for (let [key, val] of a) {
    let testVal = b.get(key);
    if (testVal !== val) {
      return false;
    }
  }
  return true;
}

const s1 = 'abab', p1 = 'ab';
const s2 = 'cbaebabacd', p2 = 'abc';
const s3 = 'ababababab', p3 = 'aab';

console.info(findAnagrams(s1, p1));
console.info(findAnagrams(s2, p2));
console.info(findAnagrams(s3, p3));
