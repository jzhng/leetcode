/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
  if (!s || s[0] === '0') return 0;

  let p = 1, q = 1;
  for (let i = 1; i < s.length; i++) {
    const lastTwo = parseInt(s.substr(i-1, 2));
    if (s[i] === '0') {
      q = 0;
    }

    if (lastTwo >= 10 && lastTwo <= 26) {
      q += p;
      p = q - p;
    } else {
      p = q;
    }
  }
  return q;
};

console.info(numDecodings('1224'));
console.info(numDecodings('1204'));
console.info(numDecodings(''));
console.info(numDecodings('0'));
console.info(numDecodings('909'));
console.info(numDecodings('27'));
