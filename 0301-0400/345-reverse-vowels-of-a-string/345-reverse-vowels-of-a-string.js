// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
  s = s.split('');

  const n = s.length - 1;
  const regex = /[aeiou]/i;
  for (let l = 0, r = n; l <= r; l++, r--) {
    while (l <= n && !regex.test(s[l])) {
      l++;
    }
  
    while (r >= 0 && !regex.test(s[r])) {
      r--;
    }

    if (l < r) {
      let c = s[l];
      s[l] = s[r];
      s[r] = c;
    }
  }

  return s.join('');
};

const s1 = 'hello';
const s2 = 'leetcode';
const s3 = 'aA';
console.info(reverseVowels(s1));
console.info(reverseVowels(s2));
console.info(reverseVowels(s3));
