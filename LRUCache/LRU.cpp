#include "LRU.h"


LRU::LRU(int capacity){
    this->capacity = capacity;
    }

int LRU::get(int key){
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()){
            return -1;
        }
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        return it->second->second;
    }

void LRU::put(int key, int value){
    auto it = cacheMap.find(key);
    if (it != cacheMap.end()){
        it->second->second = value;
        cacheList.splice(cacheList.begin(), cacheList, it->second);
    }else{
        if (cacheList.size() == capacity){
            cacheMap.erase(cacheList.back().first);
            cacheList.pop_back();
        }
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }
    }
