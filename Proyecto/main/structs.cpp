#include "structs.h"

// Definición de la estructura Inscripcion
typedef struct {
    int idClase;
    time_t fechaInscripcion;
} Inscripcion;

// Definición de la estructura Cliente
typedef struct {
    int idCliente;
    int cantInscriptos;
    Inscripcion* cursosInscriptos; // Puedes cambiar esto si hay más de una inscripción por cliente
} Asistencia;




