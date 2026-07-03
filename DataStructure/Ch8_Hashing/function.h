#pragma once

#include <iostream>

void ArrPrint(int arr[], int size);
int InterpolationSearch(int arr[], int low, int high, int x);
int InterpolationSearch2(int arr[], int size, int x);
int SequentialSearch(int arr[], int start, int stop, int x);

int IndexSearch(int arr[], int size, int m, int x);
int IndexSearch2(int arr[], int size, int m, int x);

class IndexTable
{

	struct Index_key
	{
		int key = 0;
		int index = 0;
	};

	Index_key* ptr = nullptr;

public:
	IndexTable(int arr[], int size, int m);
	~IndexTable();

	friend int IndexSearch(int arr[], int size, int m, int x);
	friend int IndexSearch2(int arr[], int size, int m, int x);
};



template<typename K, typename V>
class HashTable
{
public:
    struct Item
    {
        K key = K();
        V value = V();
        bool used = false;
    };

    HashTable(const int& capa = 8)
    {
        capacity = capa;
        table = new Item[capacity];
        count = 0;
    }

    ~HashTable()
    {
        delete[] table;
    }

    void Insert(const Item& item)
    {
        if (count * 2 >= capacity)
        {
            resize(capacity * 2);
        }

        size_t index = HashFunc(item.key);

        for (int i = 0; i < capacity; i++)
        {
            if (table[index].used && table[index].key == item.key)
            {
                table[index].value = item.value;
                return;
            }

            if (!table[index].used)
            {
                table[index] = item;
                table[index].used = true;
                count++;
                return;
            }

            index = (index + 1) % capacity;
        }
    }

    V GetValue(const K& key_)
    {
        size_t index = HashFunc(key_);

        for (int i = 0; i < capacity; i++)
        {
            if (!table[index].used)
            {
                return V();
            }

            if (table[index].key == key_)
            {
                return table[index].value;
            }

            index = (index + 1) % capacity;
        }

        return V();
    }

private:
    Item* table = nullptr;
    int capacity = 0;
    int count = 0;

    size_t HashFunc(const K& key_)
    {
        return key_ % capacity;
    }

    //size_t HashFunc(const std::string& key_)
    //{
    //    size_t hash = 0;

    //    for (char ch : key_)
    //    {
    //        hash = hash * 31 + ch;
    //    }

    //    return hash % capacity;
    //}

    void resize(int newCapacity)
    {
        Item* oldTable = table;
        int oldCapacity = capacity;

        table = new Item[newCapacity];
        capacity = newCapacity;
        count = 0;

        for (int i = 0; i < oldCapacity; i++)
        {
            if (oldTable[i].used)
            {
                Insert(oldTable[i]);
            }
        }

        delete[] oldTable;
    }
};