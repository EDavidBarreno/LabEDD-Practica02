#include "menuTerminal.h"
#include <iostream>
#include <limits> // Para limpiar el buffer de entrada
#include <vector>
#include <string>
#include <sstream>

using namespace std;

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
        if ((elementsCount * 100 / size) > 60) { // Verificar el factor de carga
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
        cout << "Tabla Hash De los GRUPOS:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Indice " << i << ": ";
            if (table[i].first != "") {
                cout << "(" << table[i].first << ", " << table[i].second << ") ";
            }
            cout << endl;
        }
    }
};

HashTable hashTable(5); // Tamaño de la tabla hash
vector<string> strings = {};

void mostrarMenuTerminal() {
    string opcion;

    do {
        cout << "\n\n\n\n   -------------------------------\n";
        cout << "   ---    BIENBENIDO A LA      ---\n";
        cout << "   ---       TERMINAL       ---\n";
        cout << "   -------------------------------";
        cout << "\n\nA continuacion introducir las intrucciones: \n\n";
        cout << " --- Para CREAR un grupo de contactos, usar la forma\n"
                "     ADD NEW-GROUP [NOMBRE DEL GRUPO] FIELDS ([campo TipoDato], ...);\n";
        cout << " --- Para AGREGAR un grupo de contactos, usar la forma\n"
                "     ADD CONTACT IN [NOMBRE DEL GRUPO] FIELDS ([dato Del Campo], ...);\n";
        cout << " --- Para VISUALIZAR un grupo de contactos, usar la forma\n"
                "     FIND CONTACT IN [NOMBRE DEL GRUPO] CONTACT-FIELD[campo]=[DatoQueBusca]; \n\n";
        cout << "1--- Mostrar tablas Hash. \n";
        cout << "2--- Salir. \n\n";
        cout << "Su respuesta es: --->";

        try {
            getline(cin, opcion);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (opcion == "1") {
                // Visualizar la tabla hash en consola
                hashTable.display();
            }
            //Opcion para salir
            if (opcion == "2") {
                cout << "\n\n   -------------------------------------------\n";
                cout << "   ---       SALIENDO DE LA TERMINAL       ---\n";
                cout << "   ---   Regresando al menu principal...   ---\n";
                cout << "   -------------------------------------------\n\n\n\n";
                break;
            }



            //Opcion para crear nuevo grupo
            if (opcion.find("ADD NEW-GROUP") == 0) {
                // Encontrar la posición de "FIELDS"
                size_t startPos = opcion.find("ADD NEW-GROUP") + 12; // Longitud de "ADD NEW-GROUP"
                size_t endPos = opcion.find("FIELDS", startPos);
                // Parametros
                size_t inicioParametro = opcion.find("(",endPos+5); // Longitud de "("
                size_t finParametro = opcion.find(")",inicioParametro); // Longitud de ")"
                if (endPos == string::npos || opcion.substr(startPos+1, endPos - startPos - 2).find_first_not_of(" \t") == string::npos ) {
                    cout << "\n\n--- FORMATO INCORRECTO PARA CREAR UN NUEVO GRUPO ---\n\n";
                    continue; // Regresar al inicio del bucle
                } else{
                    if (inicioParametro == string::npos || finParametro == string::npos) {
                        cout << "ERROR: No se encontró la declaracion de campos (---)." << endl;
                        continue;
                    } else{

                        // Extraer el nombre del grupo desde startPos hasta endPos
                        string nombreGrupo = opcion.substr(startPos+2, endPos - startPos - 3); // Restar 3 para excluir el espacio antes de "FIELDS" y sumar 2 para excluir el espacio antes del nombre
                        if (hashTable.search(nombreGrupo) != -1) {
                            cout << "El grupo ya existe en la tabla hash. No se agregará nuevamente." << endl;
                        } else {
                            // Insertar el nombre del grupo en la tabla hash solo si no existe
                            cout << "\n\nGrupo creado correctamente con el nombre: --->" << nombreGrupo << "\n\n";
                            hashTable.insert(nombreGrupo, nombreGrupo.length());
                            strings.push_back(nombreGrupo);
                        }
                        //Extaccion de parametros
                        string parametros = opcion.substr(inicioParametro+1, finParametro - inicioParametro-1);
                        stringstream ss(parametros);
                        string token;
                        vector<string> valoresParametros;
                        while (getline(ss, token, ',')) {
                            // Eliminar espacios en blanco al principio y al final de cada token
                            token.erase(0, token.find_first_not_of(" \t")); // Eliminar espacios en blanco al inicio
                            token.erase(token.find_last_not_of(" \t") + 1); // Eliminar espacios en blanco al final
                            valoresParametros.push_back(token);
                        }

                        // Imprimir cada token obtenido
                        cout << "Valores de los parametros:" << endl;
                        /*for (const string& valoresParametros : valoresParametros) {
                            //cout << valoresParametros << endl;
                            //strings.push_back(nombreGrupo+" - "+valoresParametros);
                        }*/

                        // Insertar elementos en la tabla hash
                        //vector<string> strings = {"hola", "mundo"};

                        // Visualizar la tabla hash en consola
                        //hashTable.display();
                        //Limpiarmos
                        nombreGrupo = "";
                        strings.clear();

                    }
                }

            }


            //Opcion para agregar contactos
            if (opcion == "ADD CONTACT IN") {
            }


            //Opcion para buscar contactos
            if (opcion == "FIND CONTACT IN") {
            }

        } catch (const invalid_argument& e) {
            cout << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (opcion != "2");
}   