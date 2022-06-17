// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/description/

/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
  const stack = [ ];

  path = path.split('/');
  for (let s of path) {
    switch (s) {
      case '' :
      case '.':
        break;
      case '..':
        stack.pop();
        break;
      default:
        stack.push(s);
    }
  }
  return `/${stack.join('/')}`;
};

console.info(simplifyPath('/home/'));
console.info(simplifyPath('/../'));
console.info(simplifyPath('/home//foo/'));
console.info(simplifyPath('/a/./b/../../c/'));
console.info(simplifyPath('/home/foo/.ssh/../.ssh2/authorized_keys/'));
