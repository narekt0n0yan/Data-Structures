#include <unordered_map>  
#include <list>           
#include <utility>  

using namespace std;


class LRU {
private:
    int capacity;
    unordered_map <int, list<pair<int, int>>::iterator> cacheMap;
    list<pair<int, int>> cacheList;
    
    
public:
    LRU(int capacity);
    int get(int key);
    void put(int key, int value);
};