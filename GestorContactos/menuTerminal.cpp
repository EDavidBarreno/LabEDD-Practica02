#include "menuTerminal.h"
#include <iostream>
#include <limits> // Para limpiar el buffer de entrada
#include <vector>

using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    vector<int> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index][i] == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index][i] == key) {
                table[index].erase(table[index].begin() + i);
                break;
            }
        }
    }
};



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
        cout << "1--- Salir. \n\n";
        cout << "Su respuesta es: --->";

        try {
            getline(cin, opcion);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //Opcion para salir
            if (opcion == "1") {
                cout << "\n\n   -------------------------------------------\n";
                cout << "   ---       SALIENDO DE LA TERMINAL       ---\n";
                cout << "   ---   Regresando al menu principal...   ---\n";
                cout << "   -------------------------------------------\n\n\n\n";
                break;
            }
            //Opcion para crear nuevo grupo
            if (opcion.find("ADD NEW-GROUP") == 0) {
                int n = 0;
                size_t startPos = opcion.find("ADD NEW-GROUP") + 13; // Longitud de "ADD NEW-GROUP"
                size_t endPos = opcion.find("FIELDS", startPos);
                string nombreGrupo = opcion.substr(startPos, endPos - startPos);

                cout << "\n\nGrupo creado correctamente con el nombre: " << nombreGrupo << "\n\n";
            }
            //Opcion para agregar contactos
            if (opcion == "ADD CONTACT IN") {
                cout << "\n\n--- NUEVO CONTACTO AGREGADO CORRECTAMENTE---\n\n";
            }
            //Opcion para buscar contactos
            if (opcion == "FIND CONTACT IN") {
                cout << "\n\n--- SE BUSCO CONTACTO CORRECTAMENTE---\n\n";
            }

        } catch (const invalid_argument& e) {
            cout << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (opcion != "1");
}