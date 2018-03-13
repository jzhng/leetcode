// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {

  const letterMap = {
    '2' : ['a', 'b', 'c'],
    '3' : ['d', 'e', 'f'],
    '4' : ['g', 'h', 'i'],
    '5' : ['j', 'k', 'l'],
    '6' : ['m', 'n', 'o'],
    '7' : ['p', 'q', 'r', 's'],
    '8' : ['t', 'u', 'v'],
    '9' : ['w', 'x', 'y', 'z']
  };

  const res = [];
  if (digits === '') {
    return res;
  }

  res.push('');

  for (let i = 0; i < digits.length; i++) {
    while (res[0].length === i) {
      let s = res.shift();
      for (let c of letterMap[digits[i]]) {
        res.push( s + c);
      }
    }
  }
  return res;
};

console.info(letterCombinations('23'));
