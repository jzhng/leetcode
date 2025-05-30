// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/description/

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
  const map = new Map();
  const res = [];

  for (let s of strs) {
    const key = s.split('').sort().join('');
    if (map.has(key)) {
      map.get(key).push(s);
    } else {
      map.set(key, [s]);
    }
  }

  for (let v of map.values()) {
    res.push(v);
  }
  return res;
};

const strs = ['eat', 'tea', 'tan', 'ate', 'nat', 'bat'];
console.info(groupAnagrams(strs));
