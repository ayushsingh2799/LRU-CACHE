// Author: Ayush_Singh
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define md 1000000007

 class Node{
 public:
    string key;
    int value;
    Node(string key,int value)  // constructor
    {
        this->key=key;
        this->value=value;
    }

 };

 class LRUCache{
 public:
    int maxSize;
    list<Node> l;
    unordered_map<string,list<Node>::iterator> m;
    LRUCache(int maxSize)
    {
        this->maxSize=maxSize;
        if(this->maxSize==0){
            this->maxSize=1;
        }
    }

    void insertKeyValue(string key,int value)
    {
       if(m.count(key)!=0){
        auto it=m[key];  
        it->value=value;  // replace the old value with the new value
       }
       else
       {
           // if cache size is full
           if(l.size()==maxSize)
           {
               Node last=l.back();
               m.erase(last.key);  // removes the entry from hashmap
               l.pop_back();  // remove the last node of linkedlist which is basically least recently used
           }
           Node newKey(key,value);
           l.push_front(newKey);
           m[newKey.key]=l.begin();
          
       }
    }

    int getValue(string key)
    {
         int value=INT_MAX;
         if(m.count(key)!=0)
         {
            auto it=m[key];
            value=it->value; // getting the value of key
            l.push_front(*it); // pushing it on the top because it has been recently used
            l.erase(it); // deleting the old node
            m[key]=l.begin();
         }
         return value;

    }

    string mostRecentKey()
    {
         auto it=l.begin();
         return it->key;
    }


 };


int main() 
{
    LRUCache lru(3);
    lru.insertKeyValue("apple",10);
    lru.insertKeyValue("mango",20);
    lru.insertKeyValue("banana",30);
    cout<< lru.mostRecentKey()<<endl;
    cout<<lru.getValue("mango")<<endl;
}