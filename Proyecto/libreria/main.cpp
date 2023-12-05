#include"funciones.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;
typedef unsigned int uint;


int main() {

    // !!!!!  LE ESTOY AGREGANDO UN ATRIBUTO MAS A LAS CLASES --> el "CUPO"  !!!!!!!

    cout<<"5/12"<<endl;
    Clase clases[60] = {
        {1, "Spinning", 8, 45}, {2, "Spinning", 10, 45}, {3, "Spinning", 12, 45}, {4, "Spinning", 16, 45}, {5, "Spinning", 18, 45},
        {6, "Yoga", 9, 25}, {7, "Yoga", 10, 25}, {8, "Yoga", 11, 25}, {9, "Yoga", 15, 25}, {10, "Yoga", 16, 25},
        {11, "Yoga", 19, 25}, {12, "Pilates", 8, 15}, {13, "Pilates", 9, 15}, {14, "Pilates", 10, 15}, {15, "Pilates", 12, 15},
        {16, "Pilates", 18, 15}, {17, "Pilates", 19, 15}, {18, "Stretching", 8, 40}, {19, "Stretching", 14, 40},
        {20, "Stretching", 15, 40}, {21, "Stretching", 16, 40}, {22, "Stretching", 18, 40}, {23, "Stretching", 19, 40},
        {24, "Zumba", 8, 50}, {25, "Zumba", 10, 50}, {26, "Zumba", 12, 50}, {27, "Zumba", 16, 50}, {28, "Zumba", 17, 50},
        {29, "Zumba", 18, 50}, {30, "Boxeo", 16, 30}, {31, "Boxeo", 17, 30}, {32, "Boxeo", 18, 30}, {33, "Boxeo", 19, 30},
        {34, "Musculacion", 7, 100}, {35, "Musculacion", 7.30, 100}, {36, "Musculacion", 8, 100}, {37, "Musculacion", 8.30, 100},
        {38, "Musculacion", 9, 100}, {39, "Musculacion", 9.30, 100}, {40, "Musculacion", 10, 100}, {41, "Musculacion", 10.30, 100},
        {42, "Musculacion", 11, 100}, {43, "Musculacion", 11.30, 100}, {44, "Musculacion", 12, 100}, {45, "Musculacion", 12.30, 100},
        {46, "Musculacion", 13, 100}, {47, "Musculacion", 13.30, 100}, {48, "Musculacion", 14, 100}, {49, "Musculacion", 14.30, 100},
        {50, "Musculacion", 15, 100}, {51, "Musculacion", 15.30, 100}, {52, "Musculacion", 16, 100}, {53, "Musculacion", 16.30, 100},
        {54, "Musculacion", 17, 100}, {55, "Musculacion", 17.30, 100}, {56, "Musculacion", 18, 100}, {57, "Musculacion", 18.30, 100},
        {58, "Musculacion", 19, 100}, {59, "Musculacion", 19.30, 100}, {60, "Musculacion", 20, 100}
    };
    //VARIABLES A USAR
    Asistencia* asistencias = nullptr;
    int cantAsistencias;

    leer_archivo("asistencias_1697673600000.dat", asistencias, cantAsistencias);
    buscarRepetidos(asistencias, cantAsistencias);

    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " LECTURA DEL ARCHIVO BINARIO : " << endl;
    cout << "\nLA CANTIDAD DE ASISTENCIAS son: " << cantAsistencias << endl;
    cout << " " << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

    // Imprimir las asistencias Corregidas :´D
    for (int i = 0; i < cantAsistencias; i++) {
        cout << "idCliente: " << asistencias[i].idCliente << endl;
        cout << "CantInscriptos: " << asistencias[i].cantInscriptos << endl;

        for (uint j = 0; j < asistencias[i].cantInscriptos; j++) {
            cout << "Inscripcion " << j + 1 << ": idClase --> " << asistencias[i].cursosInscriptos[j].idClase
                 << ", FechaInscripcion --> " << asistencias[i].cursosInscriptos[j].fechaInscripcion << endl;
        }
    }

    cout << " " << endl;
    cout << " --------------------------------------------------------------------------  " << endl;
    cout << "                      DATOS DE LAS CLASES \n" << endl;
    cout << " --------------------------------------------------------------------------  " << endl;

    // Imprimir los DATOS de las clases
    for (int i = 0; i < 60; ++i) {
        cout << "idClase--> " << clases[i].idClase << " || Nombre_clase--> " << clases[i].nombre <<
            " || Hora--> " << clases[i].horario << " || Cupo--> " << clases[i].cupo << endl;
    }

    srand(time(nullptr));
    // Llama a la función actualizarClases
    actualizarClases(asistencias, cantAsistencias, clases, 60);

    // Llama a la función imprimirClases
    imprimirClasesActualizadas(clases, 60);


    // R A N D O M
    //     ||
    //     ||
    //     \/


    srand(time(nullptr)); //SEMILLA para que no se repita la misma STRUCT Asistencia

    // Genera un tamanio random (Entre 1 y 100) para el ARRAY de asistencias
    uint tamanioArray = rand() % 100 + 1;

    // sE crea un array dimaico de asistencias
    Asistencia* arrayAsistencias = new Asistencia[tamanioArray];  // <------ ARRAY DONDE ALMACENO LAS ASISTENCIAS RANDOM!  ( arrayAsistencias )

    // Llenar el array con asistencias generadas aleatoriamente
    for (uint i = 0; i < tamanioArray; ++i) {
        arrayAsistencias[i] = generarAsistenciaAleatoria();
    }

    // Mostrar las asistencias generadas
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "\nARRAY DE ASISTENCIAS GENERADAS DE MANERA ALEATORIA :" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

    for (uint i = 0; i < tamanioArray; ++i) {
        cout << "idCliente--> " << arrayAsistencias[i].idCliente << " || " << "cantInscriptos--> " << arrayAsistencias[i].cantInscriptos;

        // Se muestra cada inscripcion
        cout << " || cursosInscriptos: { ";
        for (uint j = 0; j < arrayAsistencias[i].cantInscriptos; ++j) {
            cout << "(" << arrayAsistencias[i].cursosInscriptos[j].idClase << ", "
                 << arrayAsistencias[i].cursosInscriptos[j].fechaInscripcion << ") ";
        }
        cout << "}" << endl;
    }
    // Llamar a la función para escribir el array de asistencias en el archivo binario
    // Lo reescribe en el archivo binario que anteriormente fue leido
    escribirAsistenciasEnArchivo("asistencias_1697673600000.dat", arrayAsistencias, tamanioArray);



    //_________________________________________________________________________________________________________
    // Puedo testear que se hayan escrito nuevos Datos en el Binario Original repitiendo la lectura e impresion
    // Este BLOQUE puedo borrarlo posteriormente, solo queria testear si guardaba bien en el archivo


    leer_archivo("asistencias_1697673600000.dat", asistencias, cantAsistencias);
    buscarRepetidos(asistencias, cantAsistencias);

    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " LECTURA DEL ARCHIVO BINARIO : " << endl;
    cout << "\nLA CANTIDAD DE ASISTENCIAS son: " << cantAsistencias << endl;
    cout << " " << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

    // Imprimir las asistencias Corregidas :´D
    for (int i = 0; i < cantAsistencias; i++) {
        cout << "idCliente: " << asistencias[i].idCliente << endl;
        cout << "CantInscriptos: " << asistencias[i].cantInscriptos << endl;

        for (uint j = 0; j < asistencias[i].cantInscriptos; j++) {
            cout << "Inscripcion " << j + 1 << ": idClase --> " << asistencias[i].cursosInscriptos[j].idClase
                 << ", FechaInscripcion --> " << asistencias[i].cursosInscriptos[j].fechaInscripcion << endl;
        }
    }
    //__________________________________________________________________________________________________________



    // Hay que liberar la memoria reservada para el array
    for (uint i = 0; i < tamanioArray; ++i) {
        delete[] arrayAsistencias[i].cursosInscriptos;
    }
    delete[] arrayAsistencias;


    // --X-- Liberar la memoria asignada dinámicamente --X--//
    for (int i = 0; i < cantAsistencias; i++) {
        delete[] asistencias[i].cursosInscriptos;
    }
    delete[] asistencias;
    return 0;
}
