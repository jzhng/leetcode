/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
  const map = {};
  for (let i = 0; i < s.length; i++) {
    let c = s[i];
    if (!map[c]) {
      map[c] = {cnt: 0, chr: c};
    }
    map[c].cnt++;
  }

  return Object.keys(map)
    .map(key => map[key])
    .sort((a, b) => b.cnt - a.cnt)
    .map(({cnt, chr}) => chr.repeat(cnt))
    .reduce((a, b) => a + b, '');
};

const s1 = 'tree';
const s2 = 'cccaaa';
const s3 = 'Aabb';
console.info(frequencySort(s1));
console.info(frequencySort(s2));
console.info(frequencySort(s3));
