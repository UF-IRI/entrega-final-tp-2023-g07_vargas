#include<iostream>
#include<string>
#include<fstream>
#include "structs.cpp"

//1) LECTURA DEL ARCHIVO BINARIO
void leer_archivo(const char* nombreArchivo, Asistencia*& asistencias, int& cantAsistencias);


//2) Busca los idClase repetidos en una asistencia
void buscarRepetidos(Asistencia*& asistencias, int cantAsistencias);


//3) Actualizar las clases en cuanto a su cantidad de Cupos tras la reserva
void actualizarClases(Asistencia* asistencias, int cantAsistencias, Clase* clases, int cantClases);


//4) RETORNA-> un array de Asistencias de tamanio aleatorio y
void imprimirClasesActualizadas(Clase* clases, int cantClases);



