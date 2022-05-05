
import java.util.HashMap;
import java.util.Map;

public class Solution {

    private static final int MODULO = (int) Math.pow(10, 9) + 7;
    private static final int[] DELICIOUSNESS_RANGE = {0, (int) Math.pow(2, 20)};
    private static final int MAX_VALUE_FOR_PAIR = 2 * DELICIOUSNESS_RANGE[1];

    public int countPairs(int[] deliciousness) {

        Map<Integer, Integer> frequency = new HashMap<>();
        for (int n : deliciousness) {
            frequency.putIfAbsent(n, 0);
            frequency.put(n, frequency.get(n) + 1);
        }

        long totalPairs = 0;
        for (int n : frequency.keySet()) {

            int powerOfTwo = 1;
            while (n > powerOfTwo - n) {
                powerOfTwo <<= 1;
            }

            while (powerOfTwo <= MAX_VALUE_FOR_PAIR) {
                if (frequency.containsKey(powerOfTwo - n)) {
                    if (n != powerOfTwo - n) {
                        totalPairs = totalPairs + (long) frequency.get(n) * frequency.get(powerOfTwo - n);
                    } else {
                        totalPairs = totalPairs + (long) frequency.get(n) * (frequency.get(n) - 1) / 2;
                    }
                }
                powerOfTwo <<= 1;
            }
        }
        return (int) (totalPairs % MODULO);
    }
}
