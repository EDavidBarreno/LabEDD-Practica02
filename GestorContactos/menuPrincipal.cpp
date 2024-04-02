#include "menuPrincipal.h"
#include "menuTerminal.h"
#include "menuReportes.h"
#include "menuGraficas.h"
#include "menuArchivos.h"
#include <iostream>
#include <limits> // Para limpiar el buffer de entrada
using namespace std;

void mostrarMenuPrincipal() {
    int opcion;

    do {
        cout << "\n\n   -------------------------------\n";
        cout << "   ---    BIENBENIDO A SU      ---\n";
        cout << "   ---  GESTOR DE CONTACTOS    ---\n";
        cout << "   -------------------------------";
        cout << "\n\nA continuacion seleccione una opcion: \n\n";
        cout << "1--- Acceder a la Terminal.\n";
        cout << "2--- Menu Reportes.\n";
        cout << "3--- Graficas de las Estructuras.\n";
        cout << "4--- Exportacion de Contactos.\n";
        cout << "5--- Salir del sistema.\n\n";
        cout << "Su respuesta es: --->";

        try {
            cin >> opcion;

            if (cin.fail()) {
                throw invalid_argument("ERROR --- Ingresar solo numeros del 1 al 5.");
            }

            switch (opcion) {
                case 1:
                    mostrarMenuTerminal();
                    break;
                case 2:
                    mostrarMenuReportes();
                    break;
                case 3:
                    mostrarMenuGraficas();
                    break;
                case 4:
                    mostrarMenuArchivos();
                    break;
                case 5:
                    cout << "\n\n   ------------------------------------------------\n";
                    cout << "   ---            SALIENDO DEL SISTEMA          ---\n";
                    cout << "   ---   De parte de nuestros Administradores   ---\n";
                    cout << "   ---       le deseamos un lindo dia!!         ---\n";
                    cout << "   ------------------------------------------------\n";
                    break;
                default:
                    cout << "ERROR --- Ingresar solo numeros del 1 al 5.\n";
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (opcion != 5);
}