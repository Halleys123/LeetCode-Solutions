var maximumWealth = function (accounts) {
  let sum = 0,
    max = Number.MIN_VALUE;
  for (let i = 0; i < accounts.length; i++) {
    sum = 0;
    for (let j = 0; j < accounts[0].length; j++) {
      sum += accounts[i][j];
    }
    max = Math.max(max, sum);
  }
  return max;
};
