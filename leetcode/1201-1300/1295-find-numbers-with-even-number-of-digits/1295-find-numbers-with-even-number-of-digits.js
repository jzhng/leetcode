/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
  let res = 0;
  for (let num of nums) {
    let digit = 1;
    while (num >= 10) {
      digit++;
      num = (num - (num % 10)) / 10;
    }
    if (digit % 2 === 0) res++;
  }
  return res;
};

console.info(findNumbers([12,345,2,6,7896]));
