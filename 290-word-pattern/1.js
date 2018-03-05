// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/description/

/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
  const p = pattern.split(''), s = str.split(' ');
  if (p.length !== s.length) {
    return false;
  }

  const map = new Map();
  for (let i = 0; i < p.length; i++) {
    let c = p[i];
    if (map.has(c)) {
      if (map.get(c) !== s[i]) {
        return false;
      }
    } else {
      map.set(c, s[i]);
    }
  }

  let set = new Set(map.values());
  return set.size === map.size;
};

const p1 = 'abba', s1 = 'dog cat cat dog';
const p2 = 'abba', s2 = 'dog cat cat fish';
const p3 = 'abba', s3 = 'dog dog dog dog';
console.info(wordPattern(p1, s1));
console.info(wordPattern(p2, s2));
console.info(wordPattern(p3, s3));
