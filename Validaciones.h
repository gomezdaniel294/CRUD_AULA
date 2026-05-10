#pragma once
#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <ctime>
#include <mysql.h>

using namespace std;

class Validaciones {

public:

    static bool campoVacio(string texto);
    static bool longitudMaxima(string texto, int maximo);
    static bool contieneSQLInyeccion(string texto);
    static bool soloLetras(string texto);
    static bool soloNumeros(string texto);


    // Esto es para estudiantes

    static bool validarCodigo(string codigo);
    static bool codigoExiste(MYSQL* conexion, string codigo);
    static bool validarNombre(string nombre);
    static bool validarApellido(string apellido);
    static bool validarDireccion(string direccion);
    static bool validarTelefono(string telefono);
    static bool validarFechaNacimiento(string fecha);
    static bool validarTipoSangre(
        MYSQL* conexion,
        int id_tipo_sangre
    );
};