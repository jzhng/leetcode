// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/description/

/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
  const map = new Map();
  s = s.split('');
  for (let c of s) {
    if (map.has(c)) {
      map.set(c, map.get(c) + 1);
    } else {
      map.set(c , 1);
    }
  }

  const bucket = [];
  for (let [key, value] of map) {
    if (!bucket[value]) {
      bucket[value] = [key];
    } else {
      bucket[value].push(key);
    }
  }

  let res = '';
  for (let i = bucket.length - 1; i >= 0; i--) {
    if (bucket[i]) {
      for (let c of bucket[i]) {
        res += c.repeat(i);
      }
    }
  }
  return res;
};

const s1 = 'tree';
const s2 = 'cccaaa';
const s3 = 'Aabb';
console.info(frequencySort(s1));
console.info(frequencySort(s2));
console.info(frequencySort(s3));
