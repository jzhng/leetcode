/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
  const wordDict = new Set(wordList), toVisit = [];
  
  if (beginWord === endWord) return 1;

  addNextWords(beginWord, toVisit, wordDict);

  let dist = 1;
  while (toVisit.length) {
    let len = toVisit.length;
    for (let i = 0; i < len; i++) {
      let word = toVisit.shift();
      if (word === endWord) return dist + 1;
      addNextWords(word, toVisit, wordDict);
    }
    dist++;
  }

  return 0;
};

function addNextWords(word, toVisit, wordDict) {
  const alphs = 'abcdefghijklmnopqrstuvwxyz';

  if (wordDict.has(word)) {
    wordDict.delete(word);
  }

  for (let i = 0; i < word.length; i++) {
    let chs = word.split(''), _t = chs[i];
    for (let j = 0; j < alphs.length; j++) {
      if (_t !== alphs[j]) {
        chs[i] = alphs[j];
        let next = chs.join('');
        if (wordDict.has(next)) {
          toVisit.push(next);
          wordDict.delete(next);
        }
      }
    }
    chs[i] = _t;
  }
}

console.info(ladderLength('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log', 'cog']));
console.info(ladderLength('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log']));
