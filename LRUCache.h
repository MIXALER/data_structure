//
// Created by yuanh on 2021/4/21.
//

#ifndef LEETCODE_LRUCACHE_H
#define LEETCODE_LRUCACHE_H

#endif //LEETCODE_LRUCACHE_H

#include <map>

using namespace std;

struct listnode{
    listnode* next;
    listnode* pre;
    int val;
    int key;
    listnode(int key_,int val_):key(key_),val(val_),next(nullptr),pre(nullptr){}
    listnode():next(nullptr),pre(nullptr){}
};

class LRUCache {
public:
    LRUCache(int capacity):capacity_(capacity) {
        head = new listnode();
        tail = new listnode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        auto it = m.find(key);
        if(it == m.end())
            return -1;
        else{
            listnode* node = it->second;
            int val = node->val;
            listnode* prenode = node->pre;
            prenode->next = node->next;
            node->next->pre = prenode;
            prenode = tail->pre;
            prenode->next = node;
            node->pre = prenode;
            node->next = tail;
            tail->pre = node;
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if(it == m.end()){
            if(capacity_ && m.size() == capacity_){
                int key = head->next->key;
                m.erase(key);
                head->next->next->pre = head;
                head->next = head->next->next;
            }
            listnode* node = new listnode(key,value);
            m.insert({key,node});
            listnode* prenode = tail->pre;
            prenode->next = node;
            node->pre = prenode;
            node->next = tail;
            tail->pre = node;
        }else{
            listnode* node = it->second;
            node->val = value;
            listnode* prenode = node->pre;
            prenode->next = node->next;
            node->next->pre = prenode;
            prenode = tail->pre;
            prenode->next = node;
            node->pre = prenode;
            node->next = tail;
            tail->pre = node;
        }
    }
private:
    listnode* head;
    listnode* tail;
    map<int,listnode*> m;
    int capacity_;
};