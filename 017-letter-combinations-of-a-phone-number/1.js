// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {

  function findCombinations(index, s) {
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
  
    if (index === digits.length) {
      res.push(s);
    } else {
      const c = digits[index], letters = letterMap[c];
      for (let i = 0; i < letters.length; i++) {
        findCombinations(index + 1, s + letters[i]);
      }
    }
  }

  const res = [];
  if (digits === '') {
    return res;
  }

  findCombinations(0, '');
  return res;
};

console.info(letterCombinations('23'));
