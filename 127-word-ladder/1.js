// 127. Word Ladder
// https://leetcode.com/problems/word-ladder/description/

// TLE
/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
  const queue = [], visited = new Set(), n = wordList.length;

  if (beginWord === endWord) return 1;

  visited.add(beginWord);
  queue.push({word: beginWord, len: 1});
  while (queue.length) {
    let curr = queue.shift(), word = curr.word, len = curr.len;
    for (let i = 0; i < n; i++) {
      let next = wordList[i];
      if (!visited.has(next)) {
        let diff = 0;
        for (let j = 0; j < word.length; j++) {
          if (word[j] !== next[j]) diff++;
        }
        if (diff === 1) {
          if (next === endWord) return len + 1;
          if (word.length === next.length) {
            visited.add(next);
            queue.push({word: next, len: len+1});
          }
        }
      }
    }
  }
  return 0;
};

console.info(ladderLength('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log', 'cog']));
console.info(ladderLength('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log']));
