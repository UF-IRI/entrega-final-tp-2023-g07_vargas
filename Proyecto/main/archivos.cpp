#include "archivos.h"
#include "structs.cpp"
#include "funciones.cpp"

#include <iostream>
#include <fstream>

using namespace std;
//FUNCION DE LECTURA DEL BINARIO
void leer_archivo() {
    ifstream archivo("asistencias_1697673600000.dat", ios::binary);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    // buscar como obtener tam de archivo bin..
    // para calcular el tamanio del archivo
    archivo.seekg(0, ios::end);
    streampos fileSize = archivo.tellg();
    archivo.seekg(0, ios::beg);

    const int MAX_ASISTENCIAS = 1200; // Tamaño máximo del array de asistencias por dia (se anota a todas las clases)
    Asistencia asistencias[MAX_ASISTENCIAS]; // CREO EL ARRAY PRINCIPAL DE ASISTENCIAS. <-- °_°
    int cantAsistencias = 0;

    // Leer el archivo
    while (archivo.tellg() < fileSize && cantAsistencias < MAX_ASISTENCIAS) {
        Asistencia asistencia; //variable Asistencia: uso AUXILIAR

        // cargar en "asistencia" (var.) los datos -> idCliente + la.cant.clases.inscriptas
        archivo.read((char*)&asistencia.idCliente, sizeof(int));
        archivo.read((char*)&asistencia.cantInscriptos, sizeof(int));

        //---> creo ARRAY para guardar datos de la inscripcion de su currespondiente asistencia <----
        // se toma el tamanio acorde con cantInscriptos (clases a las que se anoto este cliente)
        asistencia.cursosInscriptos = new Inscripcion[asistencia.cantInscriptos];

        // lee cada inscripción
        // y guarda en el array creado
        for (int i = 0; i < asistencia.cantInscriptos; i++) {
            archivo.read((char*)&asistencia.cursosInscriptos[i].idClase, sizeof(int));
            archivo.read((char*)&asistencia.cursosInscriptos[i].fechaInscripcion, sizeof(time_t));
        }

        // llama a función de lib "funiciones.cpp" para
        // eliminar clases duplicadas de un mismo cliente
        eliminarClasesDuplicadas(asistencia);

        // almacena la asistencia en el array
        //cantAsistencias-> var. de incremento
        asistencias[cantAsistencias++] = asistencia;

        archivo.close();
    }



    // Puedo Imprimir el array de asistencias limpio, con los clientes sin tener clases duplicadas

    for (int i = 0; i < cantAsistencias; i++) {
        cout << "Asistencia " << i + 1 << ":" << endl;
        cout << "ID Cliente: " << asistencias[i].idCliente << endl;
        cout << "Cantidad de Inscriptos: " << asistencias[i].cantInscriptos << endl;

        for (int j = 0; j < asistencias[i].cantInscriptos; j++) {
            cout << "  Inscripcion " << j + 1 << ":" << endl;
            cout << "    ID Clase: " << asistencias[i].cursosInscriptos[j].idClase << endl;
            cout << "    Fecha Inscripcion: " << asctime(gmtime(&asistencias[i].cursosInscriptos[j].fechaInscripcion));
        }

        // liberar la memoria del array de Inscripcion
        delete[] asistencias[i].cursosInscriptos;
    }

    return 0;
}

//_____________________________________________________________________________________________
//______________ ESCRITURA EN ARCHIVO _________________________________________________________
// le paso un array de asistencias pero con datos generados aleatoriamente por la compu

void escribir_archivo(Asistencia* arrayAsistencias, int cantAsistencias) {
    // Se abre el archivo binario en modo escritura binaria
    std::ofstream archibinwr("asistencias_1697673600000.dat", std::ios::binary);

    // verifico si el archivo se abrió correctamente
    if (archibinwr.is_open()) {
        // aca un for para iterar sobre todas las asistencias en el array
        for (int i = 0; i < cantAsistencias; i++) {
            // escribo en el archivo el valor del campo idCliente
            archibinwr.write(reinterpret_cast<char*>(&arrayAsistencias[i].idCliente), sizeof(int));

            // escribo en el archivo la cantidad de inscriptos
            archibinwr.write(reinterpret_cast<char*>(&arrayAsistencias[i].cantInscriptos), sizeof(int));

            // bucle para iterar sobre cada inscripción en la asistencia actual
            for (int j = 0; j < arrayAsistencias[i].cantInscriptos; j++) {
                //se escribe en el archivo la información sobre el curso inscrito
                archibinwr.write(reinterpret_cast<char*>(&arrayAsistencias[i].cursosInscriptos[j]),
                                 sizeof(Inscripcion));
            }
        }
    }

    // Se cierra el archivo
    archibinwr.close();
}

