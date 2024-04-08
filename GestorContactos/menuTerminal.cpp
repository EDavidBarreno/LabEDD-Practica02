#include "menuTerminal.h"
#include <iostream>
#include <limits> // Para limpiar el buffer de entrada
#include <vector>
#include <string>
#include <sstream>






using namespace std;
HashTable hashTable(5); // Tamaño de la tabla hash
vector<string> strings = {};
HashTable2 hashTable2(5);
vector<string> strings2 = {};
HashTable3 hashTable3(5);
vector<string> strings3 = {};


bool esPalabraClave(const std::string& palabra) {
    // Lista de palabras clave
    std::vector<std::string> palabrasClave = {"STRING", "INTEGER", "CHAR", "DATE"};

    // Verificar si la palabra es una palabra clave
    for (const std::string& clave : palabrasClave) {
        if (palabra == clave) {
            return true;
        }
    }
    return false;
}





struct Registro {
    string columna1;
    string columna2;
};
struct Registro2 {
    string columna1a;
    string columna2a;
    string columna3a;
};
vector<Registro> registros;
vector<Registro2> registros2;



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
                cout << "\n\n--->Tabla Hash De Los GRUPOS: " << endl;
                hashTable.display();
                cout << "\n\n--->Tabla Hash Del GRUPO - PARAMETROS: " << endl;
                hashTable2.display2();
                cout << "\n\n--->Tabla Hash De Los VALORES: " << endl;
                hashTable3.display3();
                cout << "Registros añadidos:" << endl;
                for (const auto& registro : registros2) {
                    cout  << registro.columna1a << ", ";
                    cout << registro.columna2a << ", ";
                    cout << registro.columna3a << endl;
                }
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


                        //VERIFICACION SI EXISTE O NO EL GRUPO
                        if (hashTable.search(nombreGrupo) != -1) {
                            cout << "El grupo ya existe en la tabla hash. No se agregará nuevamente." << endl;
                        } else {

                            //Extacción de parámetros
                            string parametros = opcion.substr(inicioParametro+1, finParametro - inicioParametro-1);
                            stringstream ss(parametros);
                            string token;
                            vector<string> valoresParametros;
                            bool parametrosValidos = true; // Bandera para verificar si todos los parámetros son válidos
                            while (getline(ss, token, ',')) {
                                // Eliminar espacios en blanco al principio y al final de cada token
                                token.erase(0, token.find_first_not_of(" \t")); // Eliminar espacios en blanco al inicio
                                token.erase(token.find_last_not_of(" \t") + 1); // Eliminar espacios en blanco al final
                                // Verificar si el token es uno de los tipos de datos permitidos
                                if (token.find("STRING") != string::npos || token.find("INT") != string::npos || token.find("CHAR") != string::npos || token.find("DATE") != string::npos) {
                                    valoresParametros.push_back(token);
                                } else {
                                    cout << "ERROR: Parametro invalido en la declaracion de campos (---)" << endl;
                                    parametrosValidos = false; // Si hay un parámetro inválido, marcar como false
                                }
                            }

                            // Si todos los parámetros son válidos, entonces agregar a las tablas hash
                            if (parametrosValidos) {
                                // Insertar el nombre del grupo en la tabla hash solo si no existe
                                string nombreGrupo = opcion.substr(startPos+1, endPos - startPos-1);
                                // Eliminar los espacios en blanco al inicio y al final del nombre del grupo
                                nombreGrupo.erase(0, nombreGrupo.find_first_not_of(" "));
                                nombreGrupo.erase(nombreGrupo.find_last_not_of(" ") + 1);
                                cout << "\n\nGrupo creado correctamente con el nombre: --->" << nombreGrupo << "\n\n";
                                hashTable.insert(nombreGrupo, nombreGrupo.length());
                                strings.push_back(nombreGrupo);
                                hashTable2.insert2(nombreGrupo + " (" + parametros+")", (nombreGrupo + " - " + parametros).length());
                                registros.push_back({nombreGrupo,parametros});
                                // Imprimir y agregar a la tabla los parámetros válidos
                                cout << "Valores de los parametros validos:" << endl;
                                for (const string& valorParametro : valoresParametros) {
                                    cout << "   "<<valorParametro << endl;
                                }
                                /*for (size_t i = 0; i < registros.size(); ++i) {
                                    std::cout << "  Fila " << i + 1 << ": ";
                                    std::cout << "  Columna 1: " << registros[i].columna1 << ", ";
                                    std::cout << "  Columna 2: " << registros[i].columna2 << std::endl;
                                }*/

                            }
                            valoresParametros.clear();
                        }


                        //Limpiarmos
                        nombreGrupo = "";
                        strings.clear();
                        strings2.clear();

                    }
                }

            }




            //Opcion para agregar contactos
            if (opcion.find("ADD CONTACT IN") == 0) {
                // Encontrar la posición de "FIELDS"
                size_t startPos = opcion.find("ADD CONTACT IN") + 13; // Longitud de "ADD CONTACT IN"
                size_t endPos = opcion.find("FIELDS", startPos);

                // Verificar si se encontraron las palabras clave esperadas
                if (startPos != string::npos && endPos != string::npos) {
                    // Extraer el nombre del grupo entre "ADD CONTACT IN" y "FIELDS" y eliminar los espacios en blanco adicionales
                    string nombreGrupo = opcion.substr(startPos+1, endPos - startPos-1);
                    // Eliminar los espacios en blanco al inicio y al final del nombre del grupo
                    nombreGrupo.erase(0, nombreGrupo.find_first_not_of(" "));
                    nombreGrupo.erase(nombreGrupo.find_last_not_of(" ") + 1);

                    // Buscar el grupo en la HashTable
                    int indiceGrupo = hashTable.search(nombreGrupo);

                    // Verificar si el grupo existe
                    if (indiceGrupo != -1) {
                        for (size_t i = 0; i < registros.size(); ++i) {
                            if (registros[i].columna1 == nombreGrupo) {
                                //cout << "\n\nValor encontrado en la fila " << i + 1 << endl;
                                //cout << "Columna 2 correspondiente: " << registros[i].columna2 << endl;//Valores para insertar
                                //Logica de validar valores
                                // Parametros
                                size_t inicioParametro = opcion.find("(",endPos+5); // Longitud de "("
                                size_t finParametro = opcion.find(")",inicioParametro); // Longitud de ")"
                                string parametros = opcion.substr(inicioParametro+1, finParametro - inicioParametro-1);
                                stringstream ss(parametros);
                                string token;
                                vector<string> valoresParametros;

                                int contador1=0;
                                while (getline(ss, token, ',')) {
                                    // Eliminar espacios en blanco al principio y al final de cada token
                                    token.erase(0, token.find_first_not_of(" \t")); // Eliminar espacios en blanco al inicio
                                    token.erase(token.find_last_not_of(" \t") + 1); // Eliminar espacios en blanco al final
                                    // Verificar si el token es uno de los tipos de datos permitidos
                                    contador1++;
                                }
                                size_t inicioParametro2 = registros[i].columna2.find("(",0); // Longitud de "("
                                size_t finParametro2 = registros[i].columna2.find(")",inicioParametro2); // Longitud de ")"
                                string parametros2 = registros[i].columna2.substr(inicioParametro2+1, finParametro2 - inicioParametro2-1);
                                stringstream ss2(parametros2);
                                string token2;
                                vector<string> valoresParametros2;
                                int contador2=0;
                                while (getline(ss2, token2, ',')) {
                                    // Eliminar espacios en blanco al principio y al final de cada token
                                    token2.erase(0, token2.find_first_not_of(" \t")); // Eliminar espacios en blanco al inicio
                                    token2.erase(token2.find_last_not_of(" \t") + 1); // Eliminar espacios en blanco al final
                                    // Crear un flujo de cadena
                                    std::stringstream ss4(token2);
                                    std::string palabra4;

                                    // Leer palabras de la cadena
                                    while (ss4 >> palabra4) {
                                        // Verificar si la palabra es una palabra clave
                                        if (esPalabraClave(palabra4)) {
                                            break;  // Si encontramos una palabra clave, salimos del bucle
                                        }
                                        // Si no es una palabra clave, imprimimos la palabra
                                        //std::cout << palabra4 << " ";
                                        valoresParametros2.push_back(palabra4);
                                    }
                                    contador2++;
                                }


                                if(contador1==contador2){
                                    size_t inicioParametro3 = opcion.find("(",0); // Longitud de "("
                                    size_t finParametro3 = opcion.find(")",inicioParametro); // Longitud de ")"
                                    string parametros3 = opcion.substr(inicioParametro3+1, finParametro3 - inicioParametro3-1);
                                    stringstream ss3(parametros3);
                                    string token3;
                                    vector<string> valoresParametros3;

                                    cout << "Valores agregados correctamente en: --->" << nombreGrupo<<endl;
                                    size_t posicion4 = 0;
                                    while (getline(ss3, token3, ',')) {
                                        // Eliminar espacios en blanco al principio y al final de cada token
                                        token3.erase(0, token3.find_first_not_of(" \t")); // Eliminar espacios en blanco al inicio
                                        token3.erase(token3.find_last_not_of(" \t") + 1); // Eliminar espacios en blanco al final
                                        // Verificar si el token es uno de los tipos de datos permitidos
                                        //cout<<token3<<endl;

                                        if (posicion4 >= 0) {
                                            //std::string valorBuscado = valoresParametros2[posicion4];
                                            //std::cout << "El valor en la posición " << posicion4 << " es: " << valorBuscado << std::endl;
                                            hashTable3.insert3(valoresParametros2[posicion4]+" "+ token3,(valoresParametros2[posicion4]+" "+ token3).length());
                                            registros2.push_back({nombreGrupo,parametros3, valoresParametros2[posicion4] +" "+ token3 });
                                            posicion4++;
                                        } else {
                                            std::cout << "Posición fuera de rango." << std::endl;
                                        }


                                    }
                                    token3="";
                                    valoresParametros3.clear();
                                } else{
                                    cout<<"Parametros invalidos, verifique su ingreso.";
                                }


                                //Limpiamos
                                token="";
                                token2="";
                                nombreGrupo="";
                                contador1=0;
                                contador2=0;
                                strings3.clear();
                                valoresParametros.clear();
                                valoresParametros2.clear();
                            }
                        }





                    } else {
                        cout << "ERROR: El grupo '" << nombreGrupo << "' no existe en la HashTable." << endl;
                    }
                } else {
                    cout << "ERROR: Formato incorrecto para agregar contacto." << endl;
                }
            }




            //Opcion para buscar contactos
            if (opcion.find("FIND CONTACT IN")==0) {
                // Encontrar la posición de "FIELDS"
                size_t startPos = opcion.find("FIND CONTACT IN") + 14; // Longitud de "ADD CONTACT IN"
                size_t endPos = opcion.find("CONTACT-FIELD", startPos);

                // Verificar si se encontraron las palabras clave esperadas
                if (startPos != string::npos && endPos != string::npos) {
                    // Extraer el nombre del grupo entre "FIND CONTACT IN" y "CONTACT-FIELD" y eliminar los espacios en blanco adicionales
                    string nombreGrupo = opcion.substr(startPos+1, endPos - startPos-1);
                    // Eliminar los espacios en blanco al inicio y al final del nombre del grupo
                    nombreGrupo.erase(0, nombreGrupo.find_first_not_of(" "));
                    nombreGrupo.erase(nombreGrupo.find_last_not_of(" ") + 1);

                    // Buscar el grupo en la HashTable
                    int indiceGrupo = hashTable.search(nombreGrupo);

                    // Verificar si el grupo existe
                    if (indiceGrupo != -1) {
                        //Jalamos los parametros
                        size_t startPos2 = opcion.find("CONTACT-FIELD") + 12; // Longitud de "ADD CONTACT IN"
                        size_t endPos2 = opcion.find(";", startPos2);
                        // Verificar si se encontraron las palabras clave esperadas
                        if (startPos2 != string::npos && endPos2 != string::npos) {
                            string nombreGrupo3 = opcion.substr(startPos2+1, endPos2 - startPos2-1);
                            // Eliminar los espacios en blanco al inicio y al final del nombre del grupo
                            nombreGrupo3.erase(0, nombreGrupo3.find_first_not_of(" "));
                            nombreGrupo3.erase(nombreGrupo3.find_last_not_of(" ") + 1);
                            // Reemplazamos "=" por un espacio en blanco
                            size_t found = nombreGrupo3.find("=");
                            if (found != std::string::npos) {
                                nombreGrupo3.replace(found, 1, " ");
                            }

                            for (const auto& registro : registros2) {
                                if (registro.columna3a == nombreGrupo3) {
                                    cout << "El valor:  " << nombreGrupo3 << "  se encuentra en la tabla: " << nombreGrupo<< endl;
                                    cout << " Los valores del contacto son: " << " ( "<<nombreGrupo<<" - "<<registro.columna2a << " )"<<endl;
                                }
                            }


                        } else {
                            cout << "ERROR: Formato incorrecto para encontrar un contacto." << endl;
                        }
                    } else {
                        cout << "ERROR: El grupo '" << nombreGrupo << "' no existe en la HashTable." << endl;
                    }
                }
            }

        } catch (const invalid_argument& e) {
            cout << e.what() << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (opcion != "2");
}
