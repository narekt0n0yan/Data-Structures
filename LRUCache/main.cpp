#include <iostream>
#include "LRU.h"

int main() {
    LRU cache(2); // capacity = 2

    cache.put(1, 10);
    cache.put(2, 20);
    std::cout << "Get 1: " << cache.get(1) << std::endl; // returns 10

    cache.put(3, 30); // evicts key 2
    std::cout << "Get 2: " << cache.get(2) << std::endl; // returns -1 (evicted)
    
    cache.put(4, 40); // evicts key 1
    std::cout << "Get 1: " << cache.get(1) << std::endl; // returns -1 (evicted)
    std::cout << "Get 3: " << cache.get(3) << std::endl; // returns 30
    std::cout << "Get 4: " << cache.get(4) << std::endl; // returns 40

    // Access 3 to make it recently used
    std::cout << "Get 3 (again): " << cache.get(3) << std::endl; // returns 30

    // Add 5, should evict key 4 now (since 3 was recently accessed)
    cache.put(5, 50);

    std::cout << "Get 3: " << cache.get(3) << std::endl; // returns 30
    std::cout << "Get 4: " << cache.get(4) << std::endl; // returns -1 (evicted)
    std::cout << "Get 5: " << cache.get(5) << std::endl; // returns 50

    return 0;
}
