/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
// var duplicateZeros = function(arr) {
//   for (let i = 0; i < arr.length; i++) {
//     if (arr[i] === 0) {
//       let j = i + 1;
//       if (j >= arr.length) break;
//       for (let k = arr.length - 1; k > j; k--) {
//         arr[k] = arr[k - 1];
//       }
//       arr[j] = 0;
//       i++;
//     }
//   }
// };

var duplicateZeros = function(arr) {
  const temp = [];
  for (let i = 0; i < arr.length; i++) {
    temp.push(arr[i]);
    if (arr[i] === 0) {
      temp.push(arr[i]);
    }
  }

  for (let i = 0; i < arr.length; i++) {
    arr[i] = temp[i];
  }
};

const arr = [1,0,2,3,0,4,5,0];
duplicateZeros(arr);
console.info(arr);
