#include<iostream>
#include<string>
#include<fstream>
#include "structs.cpp"

//1) LECTURA DEL ARCHIVO BINARIO
void leer_archivo(const char* nombreArchivo, Asistencia*& asistencias, int& cantAsistencias);


//2) Busca los idClase repetidos dentro de una asistencia
void buscarRepetidos(Asistencia*& asistencias, int cantAsistencias);


//3) Es para actualizar el CUPO de las clases tras hacer la reserva por el cliente
void actualizarClases(Asistencia* asistencias, int cantAsistencias, Clase* clases, int cantClases);


//4) Funcion para imprimir los datos actulizados de las Clases.
void imprimirClasesActualizadas(Clase* clases, int cantClases);
