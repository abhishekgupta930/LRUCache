
#include<iostream>
#include<unordered_map> 
#include<list> 

using namespace std;

class LRUCache {

public:
	
    // Doubly LinkedList STL
    list<int> myList;

    // Unordered Map in STL is implemented as hash Table
    unordered_map<int, int > umap; 
    
    // MAX size of LRU Cache
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }
    
	// Read the entry from Cache
	
    int get(int key) 
	{


        // Key is present in Cache
        if (umap.find(key)!= umap.end())
            {
                // Take the key out of doubly linkedlist and 
                // Update position in Doubly linked List i.e
                // place it in the front. 
                // Finally return the value coressponding to the key 
                myList.remove(key);
                myList.push_front(key);
                return umap[key];
            }
        else
            {
                // Entry not found in Cache/Map
                return -1;
            }
        

    }
    
    void put(int key, int value) {

        
        // If Linklist is full. Remove the element from
        // the back which is going to be least recently used.
        if ( umap.size() == size && umap.find(key) == umap.end())
        	{
	            umap.erase(myList.back());
	            myList.pop_back();
        	}
      
        // If key already exists 

        if (umap.find(key) != umap.end())
        	{
	            umap.erase(key);
	            umap.insert({key, value});
	            myList.remove(key);
	            myList.push_front(key);
        	}

        else 
			{
		        // Add at the key value pair in map
		        umap.insert({key, value});
		        // Add the entry in fromt of linkedlist
		        myList.push_front(key);
        	} 
    }
};

int main()
 {
    // Driver Code
    //Set Capacity of LRU Cache
    int capacity = 5;

    // Create Cache Object
    LRUCache* obj = new LRUCache(capacity);

	// Add key pair value in cache
	obj->put(2,3);
    obj->put(4,7);
    obj->put(6,11);
    obj->put(8,13);

	// Retrieve key pair value from chache
    cout << "value is : "<<  obj->get(17) << "\n";
    cout << "value is : "<<  obj->get(4) << "\n";
    cout << "value is : "<<  obj->get(6) << "\n";
    cout << "value is : "<<  obj->get(8) << "\n";

    obj->put(10,17);
    obj->put(12,19);
    cout << "value is : "<<  obj->get(2) << "\n";
    return 0;

  }
 
