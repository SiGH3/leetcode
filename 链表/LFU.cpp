#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq; // key -> (value, freq)
    unordered_map<int, list<int>> freqToKeys; // freq -> {keys}
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freqToKeys

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (!keyToValFreq.count(key)) return -1;
        updateFreq(key);
        return keyToValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToValFreq.count(key)) {
            keyToValFreq[key].first = value;
            updateFreq(key);
        } else {
            if (keyToValFreq.size() >= capacity) removeLFU();

            keyToValFreq[key] = {value, 1};
            freqToKeys[1].push_back(key);
            keyToIter[key] = --freqToKeys[1].end();
            minFreq = 1;
        }
    }

private:
    void updateFreq(int key) {
        int freq = keyToValFreq[key].second;
        keyToValFreq[key].second++;

        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty() && minFreq == freq) minFreq++;

        freqToKeys[freq + 1].push_back(key);
        keyToIter[key] = --freqToKeys[freq + 1].end();
    }

    void removeLFU() {
        int keyToRemove = freqToKeys[minFreq].front();
        freqToKeys[minFreq].pop_front();
        keyToValFreq.erase(keyToRemove);
        keyToIter.erase(keyToRemove);
    }
};