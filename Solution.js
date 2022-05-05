
/**
 * @param {number[]} deliciousness
 * @return {number}
 */
var countPairs = function (deliciousness) {
    const MODULO = Math.pow(10, 9) + 7;
    const DELICIOUSNESS_RANGE = [0, Math.pow(2, 20)];
    const MAX_VALUE_FOR_PAIR = 2 * DELICIOUSNESS_RANGE[1];

    const frequency = new Map();
    for (let n of deliciousness) {
        if (!frequency.has(n)) {
            frequency.set(n, 0);
        }
        frequency.set(n, frequency.get(n) + 1);
    }

    let totalPairs = 0;
    for (let n of frequency.keys()) {

        let powerOfTwo = 1;
        while (n > powerOfTwo - n) {
            powerOfTwo <<= 1;
        }

        while (powerOfTwo <= MAX_VALUE_FOR_PAIR) {
            if (frequency.has(powerOfTwo - n)) {
                if (n !== powerOfTwo - n) {
                    totalPairs = totalPairs + frequency.get(n) * frequency.get(powerOfTwo - n);
                } else {
                    totalPairs = totalPairs + Math.floor(frequency.get(n) * (frequency.get(n) - 1) / 2);
                }
            }
            powerOfTwo <<= 1;
        }
    }
    return totalPairs % MODULO;
};
