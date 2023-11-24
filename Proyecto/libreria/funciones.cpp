#include "funciones.h"
#include "structs.cpp"

//____________________________________________________________
//           LECTURA DE ARCHIVO BINARIO
//____________________________________________________________
void leer_archivo(const char* nombreArchivo, Asistencia*& asistencias, int& cantAsistencias) {
    ifstream archibinrd(nombreArchivo, ios::binary);

    cantAsistencias = 0;  // Inicializa el contador de asistencias

    if (archibinrd.is_open()) {
        while (!archibinrd.eof()) {
            Asistencia asistencia;

            archibinrd.read((char*)&asistencia.idCliente, sizeof(uint));
            if (archibinrd.eof()) {
                break; // Fin del archivo
            }

            archibinrd.read((char*)&asistencia.cantInscriptos, sizeof(uint));

            asistencia.cursosInscriptos = new Inscripcion[asistencia.cantInscriptos];

            for (uint j = 0; j < asistencia.cantInscriptos; j++) {
                archibinrd.read((char*)&asistencia.cursosInscriptos[j], sizeof(Inscripcion));
            }

            // Agregar la asistencia al array
            Asistencia* temp = new Asistencia[cantAsistencias + 1];
            for (int i = 0; i < cantAsistencias; i++) {
                temp[i] = asistencias[i];
            }
            temp[cantAsistencias] = asistencia;
            delete[] asistencias;
            asistencias = temp;

            cantAsistencias++;
        }

        archibinrd.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}



void buscarRepetidos(Asistencia*& asistencias, int cantAsistencias) {
    for (int i = 0; i < cantAsistencias; i++) {
        // Crear un nuevo array de Inscripcion sin repetidos
        Inscripcion* nuevosCursos = new Inscripcion[asistencias[i].cantInscriptos];
        int nuevosCursosIdx = 0;

        // Verificar y agregar idClase al nuevo array solo si no se ha agregado antes
        for (uint j = 0; j < asistencias[i].cantInscriptos; j++) {
            bool repetido = false;

            for (int k = 0; k < nuevosCursosIdx; k++) {
                if (asistencias[i].cursosInscriptos[j].idClase == nuevosCursos[k].idClase) {
                    repetido = true;
                    break;
                }
            }

            if (!repetido) {
                nuevosCursos[nuevosCursosIdx] = asistencias[i].cursosInscriptos[j];
                nuevosCursosIdx++;
            }
        }

        // Liberar el array antiguo y asignar el nuevo array sin repetidos
        delete[] asistencias[i].cursosInscriptos;
        asistencias[i].cursosInscriptos = nuevosCursos;
        asistencias[i].cantInscriptos = nuevosCursosIdx;
    }
}

//Nueva--> Actualizar las clases en cuanto a su cantidad de Cupos tras la reserva

void actualizarClases(Asistencia* asistencias, int cantAsistencias, Clase* clases, int cantClases) {
    // Recorrer el array de asistencias
    for (int i = 0; i < cantAsistencias; i++) {
        // Recorrer el array de cursosInscriptos en cada asistencia
        for (uint j = 0; j < asistencias[i].cantInscriptos; j++) {
            // Obtener el idClase de la Inscripcion actual
            uint idClaseActual = asistencias[i].cursosInscriptos[j].idClase;

            // Buscar la clase correspondiente en el array clases
            for (int k = 0; k < cantClases; k++) {
                if (clases[k].idClase == idClaseActual) {
                    // Verificar si hay cupo disponible
                    if (clases[k].cupo > 0) {
                        // Restar 1 al cupo de la clase
                        clases[k].cupo--;
                    }
                    else {
                        // No hay más cupo
                        cout << "No hay más cupo para la clase con idClase " << idClaseActual << endl;
                    }
                    break; // Salir del bucle una vez que se ha encontrado la clase
                }
            }
        }
    }
}



// Esta funcion es para imprimir los DATOS_ACTUALIZADOS de las clases
void imprimirClasesActualizadas(Clase* clases, int cantClases) {

    // Boludeces para lo visual
    cout << " " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " " << endl;
    cout << "DATOS ACTUALIZADOS DE LAS CLASES:" << endl;

    for (int i = 0; i < cantClases; ++i) {
        // Solo imprimir las clases con cupo
        if (clases[i].cupo > 0) {
            cout << "idClase--> " << clases[i].idClase << " || Nombre_clase--> " << clases[i].nombre <<
                " || Hora--> " << clases[i].horario << " || Cupo--> " << clases[i].cupo << endl;
        }
    }
}
