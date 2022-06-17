// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  const stack = [], matches = { '(': ')', '[': ']', '{': '}' };
  for (let i = 0; i < s.length; i++) {
    const c = s[i];
    if (c in matches) {
      stack.push(c);
    } else {
      if (stack.length === 0) {
        return false;
      } else if (matches[stack.pop()] !== c) {
        return false;
      }
    }
  }
  return stack.length === 0;
};

console.info(isValid('{[()]()}'));
