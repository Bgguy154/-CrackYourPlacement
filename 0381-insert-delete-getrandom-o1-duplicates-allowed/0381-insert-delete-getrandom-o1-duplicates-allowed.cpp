class RandomizedCollection {
    private:

    std::unordered_map<int, std::unordered_set<int>> valueToIndicesMap; // Maps values to indices at which they occur.

    std::vector<int> valuesList;
    std::default_random_engine randomGenerator; 
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool isFirstOccurrence = valueToIndicesMap[val].empty();

        valueToIndicesMap[val].insert(valuesList.size());

        valuesList.push_back(val);

        return isFirstOccurrence;
    }
    
    bool remove(int val) {
          auto it = valueToIndicesMap.find(val);

        if (it == valueToIndicesMap.end()) {

            return false;

        }

        auto removeIndex = *(it->second.begin());

        it->second.erase(removeIndex);

        int lastValueIndex = valuesList.size() - 1;

        if (removeIndex < lastValueIndex) {

            int lastValue = valuesList[lastValueIndex];

            valuesList[removeIndex] = lastValue;

            valueToIndicesMap[lastValue].erase(lastValueIndex);

            valueToIndicesMap[lastValue].insert(removeIndex);

        }

        valuesList.pop_back(); // Remove the last element from the vector

        if (it->second.empty()) {

            valueToIndicesMap.erase(it); // Remove key from map if no indices are left

        }

        return true;
    }
    
    int getRandom() {
        if (valuesList.empty()) {

            return -1;

        }

        std::uniform_int_distribution<int> distribution(0, valuesList.size() - 1);

        return valuesList[distribution(randomGenerator)];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */