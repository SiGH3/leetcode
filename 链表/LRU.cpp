#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct DLinkedNode{
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key, int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int,DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int capacity;
    int size;

public:
    LRUCache(int _capacity) :capacity(_capacity),size(0){
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head -> next = tail;
        tail -> prev = head;
    }
        
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }    
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
        
    void put(int key, int value) {
        if(!cache.count(key)){
             // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key,value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if(size>capacity){
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                 // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else{
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

int main() {
    vector<string> operations = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    vector<vector<int>> values = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};

    LRUCache* cache = nullptr;
    vector<string> results;

    for (int i = 0; i < operations.size(); ++i) {
        if (operations[i] == "LRUCache") {
            cache = new LRUCache(values[i][0]);
            results.push_back("null");
        } else if (operations[i] == "put") {
            cache->put(values[i][0], values[i][1]);
            results.push_back("null");
        } else if (operations[i] == "get") {
            results.push_back(to_string(cache->get(values[i][0])));
        }
    }

    for (const string& res : results) {
        cout << res << " ";
    }
    cout << endl;

    delete cache; // 释放内存
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */