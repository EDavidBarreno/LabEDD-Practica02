#ifndef GESTORCONTACTOS_MENUTERMINAL_H
#define GESTORCONTACTOS_MENUTERMINAL_H
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void mostrarMenuTerminal();


class HashTable {
private:

    int size;
    int elementsCount;
    vector<pair<string, int>> table;

    int hashFunction(const string& key) {
        // Una función de hash simple para este ejemplo
        return hash<string>{}(key) % size;
    }

    int probeFunction(int index, int attempt) {
        // Función de sondeo lineal para este ejemplo
        return (index + attempt) % size;
    }

    void rehash() {
        int newSize = size * 2; // Duplicar el tamaño de la tabla
        vector<pair<string, int>> newTable(newSize);
        for (const auto& pair : table) {
            int index = hashFunction(pair.first) % newSize;
            int attempt = 0;
            while (newTable[index].first != "") {
                attempt++;
                index = probeFunction(hashFunction(pair.first), attempt) % newSize;
            }
            newTable[index] = pair;
        }
        size = newSize;
        table = std::move(newTable);
    }

public:

    HashTable(int tableSize) : size(tableSize), elementsCount(0) {
        table.resize(size, make_pair("", -1));
    }

    void insert(const string& key, int value) {
        if ((elementsCount * 100 / size) >= 60) { // Verificar el factor de carga
            rehash();
        }
        int index = hashFunction(key);
        int attempt = 0;
        while (table[index].first != "") {
            attempt++;
            index = probeFunction(hashFunction(key), attempt);
        }
        table[index] = make_pair(key, value);
        elementsCount++;
    }

    int search(const string& key) {
        int index = hashFunction(key);
        int attempt = 0;
        while (table[index].first != key && table[index].first != "") {
            attempt++;
            index = probeFunction(hashFunction(key), attempt);
        }
        if (table[index].first == key) {
            return table[index].second;
        } else {
            return -1; // Retorna -1 si la clave no se encuentra
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Indice " << i << ": ";
            if (table[i].first != "") {
                cout << "( " << table[i].first << ", " << i << " ) ";

                //cout << "( " << table[i].first<< " )" ;
            }
            cout << endl;
        }
    }
};

class HashTable2 {
private:

    int size2; // Cambiar el nombre de la variable
    int elementsCount2; // Cambiar el nombre de la variable
    vector<pair<string, int>> table2; // Cambiar el nombre de la variable

    int hashFunction2(const string& key) { // Cambiar el nombre de la función
        // Una función de hash simple para este ejemplo
        return hash<string>{}(key) % size2; // Usar el nuevo tamaño
    }

    int probeFunction2(int index, int attempt) { // Cambiar el nombre de la función
        // Función de sondeo lineal para este ejemplo
        return (index + attempt) % size2; // Usar el nuevo tamaño
    }

    void rehash2() { // Cambiar el nombre de la función
        int newSize2 = size2 * 2; // Duplicar el tamaño de la tabla
        vector<pair<string, int>> newTable2(newSize2); // Cambiar el nombre de la variable
        for (const auto& pair : table2) {
            int index = hashFunction2(pair.first) % newSize2; // Usar el nuevo tamaño
            int attempt = 0;
            while (newTable2[index].first != "") {
                attempt++;
                index = probeFunction2(hashFunction2(pair.first), attempt) % newSize2; // Usar el nuevo tamaño
            }
            newTable2[index] = pair;
        }
        size2 = newSize2; // Actualizar el nuevo tamaño
        table2 = std::move(newTable2); // Cambiar el nombre de la variable
    }

public:

    HashTable2(int tableSize) : size2(tableSize), elementsCount2(0) {
        table2.resize(size2, make_pair("", -1));
    }

    void insert2(const string& key, int value) {
        if ((elementsCount2 * 100 / size2) >= 60) {
            rehash2();
        }
        int index = hashFunction2(key);
        int attempt = 0;
        while (table2[index].first != "") {
            attempt++;
            index = probeFunction2(hashFunction2(key), attempt);
        }
        table2[index] = make_pair(key, value);
        elementsCount2++;
    }

    int search2(const string& key) {
        int index = hashFunction2(key);
        int attempt = 0;
        while (table2[index].first != key && table2[index].first != "") {
            attempt++;
            index = probeFunction2(hashFunction2(key), attempt);
        }
        if (table2[index].first == key) {
            return table2[index].second;
        } else {
            return -1;
        }
    }

    void display2() {
        for (int i = 0; i < size2; ++i) {
            cout << "Indice " << i << ": ";
            if (table2[i].first != "") {
                cout << "( " << table2[i].first << ", " << i << " ) ";
            }

            cout << endl;
        }
    }
};
class HashTable3 {
private:

    int size3; // Cambiar el nombre de la variable
    int elementsCount3; // Cambiar el nombre de la variable
    vector<pair<string, int>> table3; // Cambiar el nombre de la variable

    int hashFunction3(const string& key) { // Cambiar el nombre de la función
        // Una función de hash simple para este ejemplo
        return hash<string>{}(key) % size3; // Usar el nuevo tamaño
    }

    int probeFunction3(int index, int attempt) { // Cambiar el nombre de la función
        // Función de sondeo lineal para este ejemplo
        return (index + attempt) % size3; // Usar el nuevo tamaño
    }

    void rehash3() { // Cambiar el nombre de la función
        int newSize3 = size3 * 2; // Duplicar el tamaño de la tabla
        vector<pair<string, int>> newTable3(newSize3); // Cambiar el nombre de la variable
        for (const auto& pair : table3) {
            int index = hashFunction3(pair.first) % newSize3; // Usar el nuevo tamaño
            int attempt = 0;
            while (newTable3[index].first != "") {
                attempt++;
                index = probeFunction3(hashFunction3(pair.first), attempt) % newSize3; // Usar el nuevo tamaño
            }
            newTable3[index] = pair;
        }
        size3 = newSize3; // Actualizar el nuevo tamaño
        table3 = std::move(newTable3); // Cambiar el nombre de la variable
    }

public:

    HashTable3(int tableSize) : size3(tableSize), elementsCount3(0) { // Cambiar el nombre de la variable
        table3.resize(size3, make_pair("", -1)); // Cambiar el nombre de la variable
    }

    void insert3(const string& key, int value) { // Cambiar el nombre de la función
        if ((elementsCount3 * 100 / size3) > 60) { // Verificar el factor de carga
            rehash3(); // Cambiar el nombre de la función
        }
        int index = hashFunction3(key); // Cambiar el nombre de la función
        int attempt = 0;
        while (table3[index].first != "") {
            attempt++;
            index = probeFunction3(hashFunction3(key), attempt); // Cambiar el nombre de la función
        }
        table3[index] = make_pair(key, value);
        elementsCount3++;
    }

    int search3(const string& key) { // Cambiar el nombre de la función
        int index = hashFunction3(key); // Cambiar el nombre de la función
        int attempt = 0;
        while (table3[index].first != key && table3[index].first != "") {
            attempt++;
            index = probeFunction3(hashFunction3(key), attempt); // Cambiar el nombre de la función
        }
        if (table3[index].first == key) {
            return table3[index].second;
        } else {
            return -1; // Retorna -1 si la clave no se encuentra
        }
    }

    void display3() {
        for (int i = 0; i < size3; ++i) {
            cout << "Indice " << i << ": ";
            if (table3[i].first != "") {
                cout << "( " << table3[i].first << ", " << i << " ) ";
            }
            cout << endl;
        }
    }
};

#endif //GESTORCONTACTOS_MENUTERMINAL_H
