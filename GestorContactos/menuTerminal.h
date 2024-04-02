#ifndef GESTORCONTACTOS_MENUTERMINAL_H
#define GESTORCONTACTOS_MENUTERMINAL_H
#include <iostream>
#include <vector>
#include <string>
#include <functional> // Para std::hash

using namespace std;

void mostrarMenuTerminal();

class HashTable {
private:
    int size;
    vector<vector<pair<string, int>>> table;

    int hashFunction(const string& key) {
        // Una función de hash simple para este ejemplo
        return hash<string>{}(key) % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    void insert(const string& key, int value) {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value));
    }

    int search(const string& key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1; // Retorna -1 si la clave no se encuentra
    }

    void display() {
        cout << "Tabla Hash:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Índice " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            cout << endl;
        }
    }
};



#endif //GESTORCONTACTOS_MENUTERMINAL_H
