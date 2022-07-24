/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function(arr) {
  let max = -1;
  for (let i = arr.length - 1; i >= 0; i--) {
      let tmp = arr[i];
      arr[i] = max;
      if (tmp > max) max = tmp;
  }
  return arr;
};
