/*For this hash function I used the Quadratic Probing method*/
/*The elements will be stored far away from eachother to cont conflic with other elements that might cause a collision in the function*/
#include <iostream>
#include <list>    //linked list
#include <cstring> //Key value  that will be an in type
using namespace std;

class HashTable
{
private:
    static const int hashGroups = 10;          //static amout of groups
    list<pair<int, string>> table[hashGroups]; //list 1, index 0, list 2, index . . .

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    int sum{};
    for (int i{}; i < hashGroups; i++)
    {
        sum += table[i].size();
    }
    if (!sum)
    {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups; //Key of 905 for instance, in return this function will return 5
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. Value replaced." << endl;
            break;
        }
    }
    if (!keyExists)
    {
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key)
{
int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr); //will return a iterator to the next iterator
            cout << "[INFO] Item removed." << endl;
            break;
        }
    }

    if (!keyExists){
        cout << "[WARNING] Key not found. Pair not removed" << endl;
    }
    return;

}

void HashTable::printTable()
{
    for (int i{}; i < hashGroups; i++)
    {
        if(table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            cout << "[INFO] key:" << bItr->first << " Value: " << bItr->second << endl;
        }
    }
    return;
}


int main() {

    HashTable HT;
    if (HT.isEmpty()) 
    {
        cout << "Correct answer!" << endl;
    }
    else {
        cout << "Need to check out code!" << endl;
    }

    HT.insertItem(905, "Jim");
    HT.insertItem(201, "Tom");
    HT.insertItem(332, "Bob");
    HT.insertItem(124, "Sally");
    HT.insertItem(107, "Sandy");
    HT.insertItem(929, "Barb");
    HT.insertItem(928, "Rob");
    HT.insertItem(928, "Rick");

    HT.printTable();

    HT.removeItem(332);
    HT.removeItem(108); //Random key that is not in the HashTable

    if (HT.isEmpty()) 
    {
        cout << "Need to check out code!";
    }
    else {
        cout << "Correct Answer!!" << endl;
    }
    return 0;
}