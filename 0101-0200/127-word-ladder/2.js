/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
  const visited = new Set(), nextMap = new Map(); n = wordList.length;
  let queue = [];

  if (beginWord === endWord) return 1;

  wordList[-1] = beginWord;
  for (let i = -1; i < n; i++) {
    let word = wordList[i], nextWords = [];
    for (let j = 0; j < n; j++) {
      if (i !== j) {
        let next = wordList[j], diff = 0;
        for (let k = 0; k < word.length; k++) {
          if (word[k] !== next[k]) diff++;
        }
        if (diff === 1) nextWords.push(next);
      }
    }
    nextMap.set(word, nextWords);
  }

  visited.add(beginWord);
  queue.push(beginWord);
  let len = 1;
  while (queue.length) {
    let nextQueue = [];
    for (let i = 0; i < queue.length; i++) {
      let word = queue[i];
      let nextWords = nextMap.get(word);
      for (let next of nextWords) {
        if (!visited.has(next)) {
          if (next === endWord) return len + 1;
          visited.add(next);
          nextQueue.push(next);
        }      
      }
    }
    len++;
    queue = nextQueue;
  }
  return 0;
};

console.info(ladderLength('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log', 'cog']));
console.info(ladderLength('hit', 'cog', ['hot', 'dot', 'dog', 'lot', 'log']));
