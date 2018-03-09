// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
  const stack = [];
  const operators = {'+': '+', '-': '-', '*': '*', '/': '/'};
  for (let s of tokens) {
    if (s in operators) {
      let b = stack.pop(), a = stack.pop();
      switch (s) {
        case '+':
          stack.push(a + b);
          break;
        case '-':
          stack.push(a - b);
          break;
        case '*':
          stack.push(a * b);
          break;
        case '/':
          stack.push(~~(a / b)); // not Math.floor
          break;
      }
      // or stack.push(parseInt(result));
    } else {
      stack.push(parseInt(s));
    }
  }
  return stack.pop();
};

console.info(evalRPN(['2', '1', '+', '3', '*']));
console.info(evalRPN(['4', '13', '5', '/', '+']));
console.info(evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]));
