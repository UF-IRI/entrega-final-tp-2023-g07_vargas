#include<iostream>
#include<string>
#include<fstream>

using namespace std;

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

int main() {
    ifstream archivo;
    archivo.open("C:\\VARGAS_GYM_QT\\TRABAJO_GIMNASIO_VARGAS\\asistencias_1697673600000.dat", ios::in);

    if (archivo.fail()) {
        cout << "Error al abrir el archivo.." << endl;
        return 1;
    }

    // Obtener el tamaño del archivo
    archivo.seekg(0, ios::end);
    streampos fileSize = archivo.tellg();
    archivo.seekg(0, ios::beg);

    // Leer el archivo
    while (archivo.tellg() < fileSize) {
        //asistencia guardará los datos leidos
        Asistencia asistencia;

        archivo.read((char*)&asistencia.idCliente, sizeof(int));
        archivo.read((char*)&asistencia.cantInscriptos, sizeof(int));

        // Reservar memoria para el array de Inscripcion
        asistencia.cursosInscriptos = new Inscripcion[asistencia.cantInscriptos];

        // Leer cada inscripción
        for (int i = 0; i < asistencia.cantInscriptos; i++) {
            archivo.read((char*)&asistencia.cursosInscriptos[i].idClase, sizeof(int));
            archivo.read((char*)&asistencia.cursosInscriptos[i].fechaInscripcion, sizeof(time_t));
        }

        // puedo imprimir para ver que haya leido bien
        cout << "ID Cliente: " << asistencia.idCliente << endl;
        cout << "Cantidad de Inscriptos: " << asistencia.cantInscriptos << endl;

        for (int i = 0; i < asistencia.cantInscriptos; i++) {
            cout << "Inscripcion " << i + 1 << ":" << endl;
            cout << "  ID Clase: " << asistencia.cursosInscriptos[i].idClase << endl;
            cout << "  Fecha Inscripcion: " << asctime(gmtime(&asistencia.cursosInscriptos[i].fechaInscripcion));
        }

        // Liberar la memoria del array de Inscripcion
        delete[] asistencia.cursosInscriptos;
    }

    archivo.close();

    return 0;
}
