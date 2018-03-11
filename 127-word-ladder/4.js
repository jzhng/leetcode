/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
  const alphs = 'abcdefghijklmnopqrstuvwxyz';
  const wordDict = new Set(wordList);
  
  if (beginWord === endWord) return 1;
  if (!wordDict.has(endWord)) return 0;

  let begin = [ beginWord ], end = [ endWord ], dist = 1;
  while (begin.length && end.length) {
    if (begin.length > end.length) {
      let _q = begin; begin = end; end = _q;
    }

    let nextQueue = [];
    for (let word of begin) {
      let chs = word.split('');
      for (let i = 0; i < word.length; i++) {
        let _t = chs[i];
        for (let j = 0; j < alphs.length; j++) {
          if (_t !== alphs[j]) {
            chs[i] = alphs[j];
            let next = chs.join('');
            if (end.includes(next)) return dist + 1;
            if (wordDict.has(next)) {
              nextQueue.push(next);
              wordDict.delete(next);
            }
          }
        }
        chs[i] = _t;
      }
    }
    dist++;
    begin = nextQueue;
  }

  return 0;
};

console.info(ladderLength('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log', 'cog']));
console.info(ladderLength('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log']));
console.info(ladderLength('hot', 'dog', ['hot', 'cog', 'dog', 'tot', 'hog', 'hop', 'pot', 'dot']));
