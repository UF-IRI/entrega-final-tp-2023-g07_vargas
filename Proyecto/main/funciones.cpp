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


// Se encarga de la Busqueda de clases repetidas dentro de la asistencia

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



//Nueva --> Actualiza el cupo de las clases tras haber hecho La reserva

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




// Esta funcion es para --> imprimir <-- los DATOS_ACTUALIZADOS de las clases (hay menos cupos)
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








/*
// Función para generar datos aleatorios para UNA Asistencia (STRUCT)
Asistencia generarAsistenciaAleatoria() {
    const int idClaseMax = 60;          // 33 clases + 27 musculación (según lo visto en el archivo)
    const int cantInscripcionesMax = 6; // mi plan del gimnasio permite 6 inscripciones por día
    static int idClienteActual = 0;     // Los idCliente serán secuenciales (1, 2, 3, 4.....)

    // Crear una variable del tipo Asistencia
    Asistencia asistencia;

    // Asignar un idCliente de manera única y secuencial
    asistencia.idCliente = idClienteActual++;

    // Generar datos aleatorios para cantInscripciones
    asistencia.cantInscriptos = rand() % cantInscripcionesMax + 1; // para evitar cantInscriptos == 0

    // Reservar memoria para el array de Inscripcion
    asistencia.cursosInscriptos = new Inscripcion[asistencia.cantInscriptos];

    // Generar datos aleatorios para cada Inscripcion
    for (int i = 0; i < asistencia.cantInscriptos; i++) {
        asistencia.cursosInscriptos[i].idClase = rand() % idClaseMax + 1; // evitar idClase == 0
        asistencia.cursosInscriptos[i].fechaInscripcion = time(nullptr) - (rand() % 2592000); // fecha aleatoria en los últimos 30 días
    }

    return asistencia;
}
//_______________-------------------------------------------

// Función para generar un array de Asistencia con datos aleatorios
Asistencia* generarAsistenciasAleatorias(int& cantAsistencias) {
    const int cantMaximaAsistencias = 100; // Tamaño máximo del array de asistencias

    // Generar un tamaño aleatorio para el array de asistencias
    cantAsistencias = rand() % cantMaximaAsistencias + 1; // Evitar cantAsistencias == 0

    // Crear el array de asistencias
    Asistencia* asistencias = new Asistencia[cantAsistencias];

    // Generar asistencias aleatorias
    for (int i = 0; i < cantAsistencias; i++) {
        asistencias[i] = generarAsistenciaAleatoria();
    }

    return asistencias;
}

// Función para liberar memoria del array de asistencias
void liberarMemoriaAsistencias(Asistencia* asistencias, int cantAsistencias) {
    for (int i = 0; i < cantAsistencias; i++) {
        delete[] asistencias[i].cursosInscriptos;
    }
    delete[] asistencias;
}

*/
