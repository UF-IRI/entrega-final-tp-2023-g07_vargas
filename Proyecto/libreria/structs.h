// En este archivo decidí guardar las librerias principales tambien.
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

typedef unsigned int uint;


//INSCRIPCION
typedef struct {
    uint idClase;
    time_t fechaInscripcion;
} Inscripcion;

//ASISTENCIA
typedef struct {
    uint idCliente;
    uint cantInscriptos;
    Inscripcion* cursosInscriptos;
} Asistencia;

// CLASE
typedef struct {
    uint idClase;
    string nombre;
    uint horario;
    uint cupo;
} Clase;

// CLIENTE
typedef struct {
    uint idCliente;
    uint nombre;
    string mail;
    int telefono;
    string fecha_nacimiento;
    bool estado;
} Cliente;

// RESERVA
typedef struct {
    uint idCliente;
    uint idClase;
} Reserva;
