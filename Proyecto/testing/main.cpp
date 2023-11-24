#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

int main(int argc, char** argv) {
    return Catch::Session().run(argc, argv);
}

#include <gtest/gtest.h>

// Tu función leer_archivo
void leer_archivo(const char* nombreArchivo, Asistencia*& asistencias, int& cantAsistencias);

// Definición de una prueba
TEST(LeerArchivoTest, CantidadAsistencias) {
    const char* nombreArchivo = "asistencias_1697673600000.dat";
    Asistencia* asistencias = nullptr;
    int cantAsistencias = 0;

    leer_archivo(nombreArchivo, asistencias, cantAsistencias);

    // Verificar si cantAsistencias es igual a 153
    EXPECT_EQ(cantAsistencias, 153);

    // Liberar memoria
    for (int i = 0; i < cantAsistencias; i++) {
        delete[] asistencias[i].cursosInscriptos;
    }
    delete[] asistencias;
}

// Punto de entrada para las pruebas
int main(int argc, char** argv) {
    // Inicializar Google Test
    ::testing::InitGoogleTest(&argc, argv);

    // Ejecutar las pruebas
    return RUN_ALL_TESTS();
}
