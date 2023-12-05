#include"funciones.cpp"

//1)
void leer_archivo(const char* nombreArchivo, Asistencia*& asistencias, int& cantAsistencias);

//2)
void buscarRepetidos(Asistencia*& asistencias, int cantAsistencias);

//3)
void actualizarClases(Asistencia* asistencias, int cantAsistencias, Clase* clases, int cantClases);

//4)
void imprimirClasesActualizadas(Clase* clases, int cantClases);

//5)
Asistencia generarAsistenciaAleatoria();

//6)
void escribirAsistenciasEnArchivo(const char* nombreArchivo, Asistencia* arrayAsistencias, uint tamanoArray);

//7)
void liberarMemoriaAsistencias(Asistencia* asistencias, int cantAsistencias);
