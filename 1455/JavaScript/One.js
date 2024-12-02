var isPrefixOfWord = function (sentence, searchWord) {
  let reg = new RegExp(`^${searchWord}`, "g");
  let match = sentence.split(" ").findIndex((w, i) => {
    if (reg.test(w)) return true;
    return false;
  });
  return match == -1 ? match : match + 1;
};

console.log(isPrefixOfWord("i love eating burger", "burg")); // 4
console.log(isPrefixOfWord("this problem is an easy problem", "pro")); // 2
