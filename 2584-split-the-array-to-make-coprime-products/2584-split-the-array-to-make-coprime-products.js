var findValidSplit = function (a) {
    let pivotIndex = 0;
    for (let i = 0; i <= pivotIndex; ++i)
        for (let j = a.length - 1; j > pivotIndex; --j)
            if (gcd(a[i], a[j]) !== 1) {
                pivotIndex = j;
                break;
            }
    if (pivotIndex === a.length - 1) {
        return -1;
    }
    return pivotIndex;
};
function gcd(a, b) {
    let t;
    while (b) (t = b), (b = a % b), (a = t);
    return a;
}