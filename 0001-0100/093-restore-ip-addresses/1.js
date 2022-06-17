// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/description/

/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
  function sliceString(index, arr, s) {
    if (index < 3) {
      for (let i = 1; i < 4; i++) {
        sliceString(index + 1,  [...arr, s.slice(0, i)], s.slice(i));
      }
    } else {
      arr.push(s);
      for (let num of arr) {
        if (!num || (num.length > 1 && num[0] === '0')
            || parseInt(num) > 255) {
          return;
        }
      }
      res.push(arr.join('.'));
    }
  }

  const res = [];
  sliceString(0, [], s);
  return res;
};

console.info(restoreIpAddresses('25525511135'));
console.info(restoreIpAddresses('0000'));
console.info(restoreIpAddresses('010010'));
