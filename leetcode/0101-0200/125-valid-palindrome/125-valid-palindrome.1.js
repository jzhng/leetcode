// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/description/

/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
  s = s.toLowerCase();
  let lChr, rChr;

  for (let l = 0, r = s.length - 1; l <= r; l++, r--) {
    lChr = s.charAt(l);
    while (l <= r && !isAlphanumeric(lChr)) {
      lChr = s.charAt(++l);
    }

    rChr = s.charAt(r);
    while (l <= r && !isAlphanumeric(rChr)) {
      rChr = s.charAt(--r);
    }

    if (l <= r && lChr !== rChr) {
      return false;
    }
  }

  return true;
};

function isAlphanumeric(c) {
  return (c >= 'a' && c <= 'z' ||
          c >= 'A' && c <= 'Z' ||
          c >= '0' && c <= '9');
}

const s1 = 'A man, a plan, a canal: Panama';
const s2 = 'race a car';
const s3 = ' ';
const s4 = '';

console.info(isPalindrome(s1));
console.info(isPalindrome(s2));
console.info(isPalindrome(s3));
console.info(isPalindrome(s4));
