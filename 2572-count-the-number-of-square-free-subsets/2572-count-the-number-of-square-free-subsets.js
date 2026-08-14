const MOD = 10 ** 9 + 7;
const PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
function filterSquareFreeNumbers(numbers) {
  return numbers.filter((number) => ![2, 3, 5].some((prime) => number % (prime * prime) === 0));
}
function mapNumbersToPrimeBimap(numbers) {
  return numbers.map((number) => PRIMES.reduce((bimap, prime, i) => (number % prime === 0 ? bimap + (1 << i) : bimap), 0));
}
function squareFreeSubsets(numbers) {
  const primeBimaps = mapNumbersToPrimeBimap(filterSquareFreeNumbers(numbers));
  const n = primeBimaps.length;
  const cache = Array.from({ length: n + 1 }, () => Array(1 << PRIMES.length).fill(-1));
  function dfs(i, totalBitmask) {
    if (i === n) return 1;
    if (cache[i][totalBitmask] !== -1) return cache[i][totalBitmask];
    let subsetCount = dfs(i + 1, totalBitmask);
    if ((totalBitmask & primeBimaps[i]) === 0) {
      subsetCount += dfs(i + 1, totalBitmask | primeBimaps[i]);
      subsetCount %= MOD;
    }
    cache[i][totalBitmask] = subsetCount;
    return subsetCount;
  }
  let subsetCount = dfs(0, 0);
  subsetCount = (subsetCount - 1 + MOD) % MOD;
  return subsetCount;
}