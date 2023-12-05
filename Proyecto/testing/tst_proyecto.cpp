#include <catch2/catch.hpp>
#include<testing.pro>
#include <QtTest/QtTest>
#include "funciones.h"



class Test_ : public QObject {
    Q_OBJECT

private slots:
    void testBuscarRepetidos() {
        // SE crea un array de asistencias para la prueba
        Asistencia asistencias[] = {
                                    {1, 3, new Inscripcion[3]{{1, time(nullptr)}, {2, time(nullptr)}, {1, time(nullptr)}}},
                                    {2, 2, new Inscripcion[2]{{3, time(nullptr)}, {4, time(nullptr)}}},
                                    {3, 4, new Inscripcion[4]{{5, time(nullptr)}, {6, time(nullptr)}, {5, time(nullptr)}, {7, time(nullptr)}}},
                                    };
        int cantAsistencias = sizeof(asistencias) / sizeof(Asistencia);

        // Llamar a la función a testear
        buscarRepetidos(asistencias, cantAsistencias);

        // Verificar que no haya repeticiones en los idClase después de llamar a buscarRepetidos
        QCOMPARE(asistencias[0].cantInscriptos, 2);
        QCOMPARE(asistencias[0].cursosInscriptos[0].idClase, 1u);
        QCOMPARE(asistencias[0].cursosInscriptos[1].idClase, 2u);


        QCOMPARE(asistencias[1].cantInscriptos, 2);
        QCOMPARE(asistencias[1].cursosInscriptos[0].idClase, 3u);
        QCOMPARE(asistencias[1].cursosInscriptos[1].idClase, 4u);


        QCOMPARE(asistencias[2].cantInscriptos, 3);
        QCOMPARE(asistencias[2].cursosInscriptos[0].idClase, 5u);
        QCOMPARE(asistencias[2].cursosInscriptos[1].idClase, 6u);
        QCOMPARE(asistencias[2].cursosInscriptos[2].idClase, 7u);
    }
};

QTEST_APPLESS_MAIN(TestProyecto)
#include "tst_proyecto.moc"



class Test_Clase : public QObject {
    Q_OBJECT

private slots:
    void testBuscarRepetidos() {
        // Configuración inicial

        // datos de prueba
        Asistencia asistencia;
        asistencia.idCliente = 1;
        asistencia.cantInscriptos = 3;
        asistencia.cursosInscriptos = new Inscripcion[asistencia.cantInscriptos];

        // Datos de inscripción, incluyendo duplicados
        asistencia.cursosInscriptos[0].idClase = 1;
        asistencia.cursosInscriptos[1].idClase = 2;
        asistencia.cursosInscriptos[2].idClase = 1;  // Aca el duplicado

        //Llamar a la función que queremos probar
        buscarRepetidos(&asistencia, 1);

        // Verificar la prueba
        QCOMPARE(asistencia.cantInscriptos, 2);  // Tiene que haber eliminado el duplicado

        //Debe de verificar que los duplicados se hayan eliminado
        QCOMPARE(asistencia.cursosInscriptos[0].idClase, 1);
        QCOMPARE(asistencia.cursosInscriptos[1].idClase, 2);

        // Liberar memoria
        delete[] asistencia.cursosInscriptos;
    }
};

QTEST_MAIN(TestAsistencia)
#include "funciones.h"
