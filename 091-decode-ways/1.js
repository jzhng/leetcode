// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/description/

/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
  if (!s) return 0;

  const n = s.length, nums = new Array(n+1).fill(0);

  nums[0] = 1;
  nums[1] = s[0] === '0' ? 0 : 1;

  for (let i = 2; i <= n; i++) {
    const last = parseInt(s[i-1]);
    const lastTwo = parseInt(s.substr(i-2, 2));

    if (last !== 0) {
      nums[i] += nums[i-1];
    }

    if (lastTwo >= 10 && lastTwo <= 26) {
      nums[i] += nums[i-2];
    }
  }
  return nums[n];
};

console.info(numDecodings('1224'));
console.info(numDecodings('1204'));
console.info(numDecodings(''));
console.info(numDecodings('0'));
console.info(numDecodings('909'));
console.info(numDecodings('27'));
