/**
 * @param {string} s
 * @return {string}
 */
var reverseString = function(s) {
  s = s.split('');

  let l = 0, r = s.length - 1;
  while (l <= r) {
    let c = s[l];
    s[l] = s[r];
    s[r] = c;
    l++;
    r--;
  }

  return s.join('');
};

let s = 'hello';
console.info(reverseString(s));
