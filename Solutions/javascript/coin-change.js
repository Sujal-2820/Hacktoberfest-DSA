// time O(c * a) | space O(a)
var coinChange = function (coins, amount) {
  let change = new Array(amount + 1).fill(amount + 1);
  change[0] = 0;

  for (let i = 1; i < change.length; i++) {
    for (const coin of coins) {
      const diff = i - coin;

      if (coin <= i) {
        change[i] = Math.min(change[i], change[diff] + 1);
      }
    }
  }

  return change[amount] > amount ? -1 : change[amount];
};
