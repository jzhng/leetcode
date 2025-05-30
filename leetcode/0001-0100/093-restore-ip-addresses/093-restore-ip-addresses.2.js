// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/description/

/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
  function sliceString(idx, restored, count) {
    if (count < 4) {
      for (let i = 1; i < 4; i++) {
        if (idx + i > s.length) break;
        let num = s.slice(idx, idx + i);
        if ((num.length > 1 && num[0] === '0') || parseInt(num) > 255) {
          continue;
        }
        sliceString(idx + i, `${restored}${num}${count === 3 ? '' : '.'}`, count + 1);
      }
    } else if (count === 4) {
      if (idx === s.length) res.push(restored);
    }
  }

  const res = [];
  sliceString(0, '', 0);
  return res;
};

console.info(restoreIpAddresses('25525511135'));
console.info(restoreIpAddresses('0000'));
console.info(restoreIpAddresses('010010'));
