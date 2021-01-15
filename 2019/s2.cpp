#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

// Prime numbers from 0 - the largest input
vector<uint> primes;

/**
 * Gets pair of prime numbers whose sum is of targetVal * 2
 * @param targetVal half of sum to add to
 * GetPair works by using two "pointers". Since the numbers near the beginning and end are the most
 * likely to add up to the target value, one pointer is placed at the beginning of the primes array
 * and one is added at the end.
 *
 * The pointer near the start stays while the pointer near the end moves down.
 * If the pointer values add up smaller than the target value, it either breaks the loop or moves
 * the pointer forward. If it breaks, the current pointer value is stored for use in the next
 * iteration.
 */
pair<uint, uint> getPair(uint targetVal) {
    targetVal *= 2;
    uint pointer = primes.size() - 1; // Store previous pointer state

    // Iterate through each prime
    for (uint index = 0; index < primes.size(); index++) {
        uint prime1 = primes[index];

        while (pointer >= index - 1) {
            if (primes[pointer] + prime1 < targetVal) {
                // If the next value is also smaller or equal to the target
                if (pointer + 1 < primes.size() && primes[pointer + 1] + prime1 <= targetVal) {
                    pointer++;
                } else {
                    break;
                }
            } else if (primes[pointer] + prime1 == targetVal) { // If its equal, return
                return pair<uint, uint>(primes[pointer], prime1);
            } else {
                pointer--;
            }
        }
    }

    return pair<uint, uint>(0, 0);
}

int main() {
    uint inputCount;     // Number of inputs
    vector<uint> inputs; // All input values stored here
    cin >> inputCount;

    for (uint _ = 0; _ < inputCount; _++) { // Add inputs
        uint input;
        cin >> input;
        inputs.push_back(input);
    }

    // Largest input value to get primes from
    uint largest = *std::max_element(std::begin(inputs), std::end(inputs)) * 2;

    /**
     * Prime number generation.
     * @see @link https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
     */
    vector<bool> sieve(largest);
    std::fill(sieve.begin(), sieve.end(), true);

    for (uint index = 2; index < int(sqrt(largest)) + 1; index++) {
        if (sieve[index]) {
            uint increment = 0;
            while ((index * index) + index * increment < largest) {
                sieve[(index * index) + index * increment] = false;
                increment++;
            }
        }
    }

    for (uint i = 0; i < sieve.size(); i++) {
        if (sieve[i] && !(i == 0 || i == 1)) {
            primes.push_back(i);
        }
    }

    std::vector<pair<uint, uint>> pairs;

    for (auto& input : inputs) {
        pairs.push_back(getPair(input));
    }

    for (auto& pair : pairs) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
