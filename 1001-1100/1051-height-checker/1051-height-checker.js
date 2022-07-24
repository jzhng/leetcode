/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
  const original = [...heights];
  const expected = heights.sort((a, b) => a - b);

  let res = 0;
  for (let i = 0; i < original.length; i++) {
      if (expected[i] !== original[i]) res++;
  }
  return res;
};

const heights = [10,6,6,10,10,9,8,8,3,3,8,2,1,5,1,9,5,2,7,4,7,7];
console.info(heightChecker(heights));
