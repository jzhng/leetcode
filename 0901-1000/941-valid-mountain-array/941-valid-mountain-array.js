/**
 * @param {number[]} arr
 * @return {boolean}
 */
var validMountainArray = function(arr) {
  if (arr.length < 3) return false;

  let i = 0;
  while (arr[i] < arr[i+1] && i < arr.length - 1) i++;
  if (i === 0 || i == arr.length - 1) return false;

  while (arr[i] > arr[i+1] && i < arr.length - 1) i++;
  return i === arr.length - 1;
};

console.info(validMountainArray([0,3,3]));
console.info(validMountainArray([1,3,2]));

