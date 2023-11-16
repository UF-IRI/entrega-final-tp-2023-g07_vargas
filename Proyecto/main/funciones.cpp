#include "funciones.h"
#include "structs.cpp"


//--- para verificar y eliminar clases duplicadas ----

void eliminarClasesDuplicadas(Asistencia& asistencia) {
    for (int i = 0; i < asistencia.cantInscriptos - 1; i++) {
        for (int j = i + 1; j < asistencia.cantInscriptos; j++) {
            if (asistencia.cursosInscriptos[i].idClase == asistencia.cursosInscriptos[j].idClase) {
                // Clase duplicada encontrada, eliminarla
                for (int k = j; k < asistencia.cantInscriptos - 1; k++) {
                    asistencia.cursosInscriptos[k] = asistencia.cursosInscriptos[k + 1];
                }
                asistencia.cantInscriptos--; // Disminuir la cantidad de inscripciones
                j--; // Ajustar el índice j después de eliminar la clase duplicada
            }
        }
    }
}

//___________________________________________________________________________________
//me falta hacer un RANDOM que genere datos para completar un nuevo archivo binario
//y escribirlo en el Binario con la funcion de ESCRIBITR EN ARCHIVO.




// Esta función es para generar datos aleatorios para UNA Asistencia (STRUCT)
Asistencia generarAsistenciaAleatoria() {
    const int idClaseMax = 60;          //33 clases + 27 musculacio (así lo vi el archivo)
    const int cantInscripcionesMax = 6; // mi plan del gimnasio permite 6 inscripciones por dia
    static int idClienteActual = 1;     // empieza generando id's desde el 1 asi no se repiten en este random

    // creo una variable del tipo Asistencia
    Asistencia asistencia;

    // asigna un idCliente de manera única y secuencial
    asistencia.idCliente = idClienteActual++;

    // genera datos aleatorios para cantInscripciones
    asistencia.cantInscriptos = rand() % cantInscripcionesMax + 1; // para evitar cantInscriptos == 0

    // reserva memoria para el array de Inscripcion
    asistencia.cursosInscriptos = new Inscripcion[asistencia.cantInscriptos];

    // genera datos aleatorios para cada Inscripcion
    for (int i = 0; i < asistencia.cantInscriptos; i++) {
        asistencia.cursosInscriptos[i].idClase = rand() % idClaseMax + 1; // evita idClase == 0
        asistencia.cursosInscriptos[i].fechaInscripcion = time(nullptr) - (rand() % 2592000); // fecha aleatoria en los últimos 30 días
    }

    return asistencia;
}


//___________________________________________________________________________________________


// función que RETORNA un array de Asistencias de tamanio aleatorio (entre 1 y 1000 personas anotadas)
Asistencia* generarArrayAsistenciasAleatorias() {
    const int tam_max = 1000;
    int tamanio = rand() % tam_max + 1; // determina el tamaño aleatorio entre 1 y 1000

    // Array dinamico de tamanio aleatorio
    Asistencia* arrayAsistencias = new Asistencia[tamanio];

    // llenara el array con asistencias generadas ANTERIORMENTE
    for (int i = 0; i < size; i++) {
        arrayAsistencias[i] = generarAsistenciaAleatoria(); //UTILIZO LA FUNCION  " generarAsistenciaAleatoria() "
    }

    return arrayAsistencias;
}

//___________________________________________________________________________________________










int run_() {
    srand(time(nullptr));

    // Generar un array de asistencias de tamaño aleatorio
    Asistencia* asistencias = generarArrayAsistenciasAleatorias();

    // Hacer algo con el array de asistencias (por ejemplo, imprimir información)

    // Liberar la memoria asignada para el array de asistencias
    delete[] asistencias;

    return 0;
}
