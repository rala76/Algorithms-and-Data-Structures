#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

class HashMap {
public:
    int size = 0;
    int capacity = 2;
    vector<pair<string, string>*> map;

    HashMap() {
        map = *(new vector<pair<string, string>*> {0, 0});
    }
    
    int hash(string& key) {
        int index = 0;
        for (char& c : key) {
            index += int(c);
        }

        return index % capacity;
    }

    string* get (string& key) {
        int index = hash(key);
        while (map[index]) {
            if (map[index]->first == key) {
                return &map[index]->second;
            }
            
            index++;
            index = index % capacity;
        }
        
        return nullptr;
    }
    
    void put(string& key, string& val) {
        int index = hash(key);

        while (true) {
            if (map[index] == 0) {
                map[index] = new pair<string, string>(key, val);

                size++;
                if (size >= capacity / 2) {
                    rehash();
                }

                return;
            } else if (map[index]->first == key) {
                map[index]->second = val;
                return;
            }

            index++;
            index = index % capacity;
        }
    }

    void remove(string& key) {
        if (!get(key)) {
            return;
        }
        
        int index = hash(key);

        while(true) {
            if (map[index]->first == key) {
                // Removing an element using open-addressing actually causes a bug,
                // because we may create a hole in the list, and our get() may
                // stop searching early when it reachs this hole.
                map[index] = 0;
                size--;

                return;
            }

            index++;
            index = index % capacity;
        }
    }

    void rehash() {
        capacity = 2 * capacity;
        vector<pair<string, string>*> newMap = *(new vector<pair<string, string>*>());
        
        for (int i = 0; i < capacity; i++) {
            newMap.push_back(0);
        }
        
        vector<pair<string, string>*> oldMap = map;
        map = newMap;
        size = 0;

        for (auto& pair : oldMap) {
            if (pair != 0) {
                put(pair->first, pair->second);
            }
        }
    }

    void print() {
        cout << "Printing size=" << size << endl;
        for (auto& pair : map) {
            if (pair) {
                cout << pair->first << ' ' << pair->second << '-';
            }
            cout << endl;
        }
    }
};

int main() {
    return 0;
}