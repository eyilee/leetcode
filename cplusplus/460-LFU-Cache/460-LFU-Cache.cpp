#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LFUCache
{
public:
    LFUCache (int capacity)
    {
        this->capacity = capacity;
    }

    int get (int key)
    {
        if (capacity == 0) { return -1; }

        if (cache.find (key) != cache.end ()) {
            touch (key);
            return cache[key];
        }

        return -1;
    }

    void put (int key, int value)
    {
        if (capacity == 0) { return; }

        if (cache.find (key) != cache.end ()) {
            touch (key);
            cache[key] = value;
            return;
        }

        if (cache.size () >= capacity) {
            auto end = freqs_list.end ();
            end--;
            int evict = end->back ();
            end->pop_back ();

            int freq = freqs[evict];
            if (end->empty ()) {
                freqs_list.pop_back ();
                freqs_head.erase (freq);
            }

            freqs_node.erase (evict);
            cache.erase (evict);
            freqs.erase (evict);
        }

        // insert to head map
        if (freqs_head.find (0) == freqs_head.end ()) {
            freqs_head[0] = freqs_list.insert (freqs_list.end (), list<int> ());
        }

        // add the node
        freqs_head[0]->push_front (key);

        // insert to node map
        freqs_node[key] = freqs_head[0]->begin ();

        cache[key] = value;
        freqs[key] = 0;
    }

    void touch (int key)
    {
        int freq = freqs[key];
        auto head = freqs_head[freq];
        auto node = freqs_node[key];

        // remove the node from head map
        head->erase (node);

        // insert to head map
        if (freqs_head.find (freq + 1) == freqs_head.end ()) {
            freqs_head[freq + 1] = freqs_list.insert (head, list<int> ());
        }

        // add the node
        freqs_head[freq + 1]->push_front (key);

        // insert to node map
        freqs_node[key] = freqs_head[freq + 1]->begin ();

        if (head->empty ()) {
            freqs_list.erase (head);
            freqs_head.erase (freq);
        }

        freqs[key]++;
    }

private:
    int capacity;
    unordered_map<int, int> cache;
    unordered_map<int, int> freqs;
    unordered_map<int, list<list<int>>::iterator> freqs_head;
    unordered_map<int, list<int>::iterator> freqs_node;
    list<list<int>> freqs_list;
};

int main ()
{
    LFUCache cache (2);

    cache.put (1, 1);
    cache.put (2, 2);
    cache.get (1);       // returns 1
    cache.put (3, 3);    // evicts key 2
    cache.get (2);       // returns -1 (not found)
    cache.get (3);       // returns 3.
    cache.put (4, 4);    // evicts key 1.
    cache.get (1);       // returns -1 (not found)
    cache.get (3);       // returns 3
    cache.get (4);       // returns 4
}
