
#include <unordered_map>
#include <iterator>
#include <vector>
#include <array>
using namespace std;

class Solution {
    
    inline static const int MODULO = pow(10, 9) + 7;
    inline static const array<int, 2> DELICIOUSNESS_RANGE { 0, static_cast<int> (pow(2, 20)) };
    inline static const int MAX_VALUE_FOR_PAIR = 2 * DELICIOUSNESS_RANGE[1];

public:
    int countPairs(const vector<int>& deliciousness) {
        unordered_map<int, int> frequency;
        for (const auto& n : deliciousness) {
            ++frequency[n];
        }

        long long totalPairs = 0;
        for (const auto& n : frequency) {

            int powerOfTwo = 1;
            while (n.first > powerOfTwo - n.first) {
                powerOfTwo <<= 1;
            }

            while (powerOfTwo <= MAX_VALUE_FOR_PAIR) {

                //C++20: frequency.contains(powerOfTwo - n.first)
                if (frequency.find(powerOfTwo - n.first) != frequency.end()) {
                    if (n.first != powerOfTwo - n.first) {
                        totalPairs = totalPairs + static_cast<long long> (n.second) * frequency[powerOfTwo - n.first];
                    } else {
                        totalPairs = totalPairs + static_cast<long long> (n.second) * (n.second - 1) / 2;
                    }
                }
                powerOfTwo <<= 1;
            }
        }
        return static_cast<int> (totalPairs % MODULO);
    }
};
