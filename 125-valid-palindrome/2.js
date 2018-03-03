/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
  s = s.toLowerCase().replace(/[^a-z0-9]/g, '');

  for (let l = 0, r = s.length - 1; l <= r; l++, r--) {
    if (s[l] !== s[r]) {
      return false;
    }
  }
  return true;
};

const s1 = 'A man, a plan, a canal: Panama';
const s2 = 'race a car';
const s3 = ' ';
const s4 = '';

console.info(isPalindrome(s1));
console.info(isPalindrome(s2));
console.info(isPalindrome(s3));
console.info(isPalindrome(s4));
