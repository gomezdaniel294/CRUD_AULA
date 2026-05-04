#pragma once
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
#include <mysql.h>
using namespace std;

class Estudiante :Persona {
	//atributos
private: string codigo;
	   int id_estudiante = 0;
public:
	Estudiante() {}
	Estudiante(int id_est, string cod, string nom, string ape, string dir, string fn, int tel, int id_ts)
		: Persona(nom, ape, dir, fn, tel, id_ts) {
		id_estudiante = id_est;
		codigo = cod;
	}

	void setId_estudiante(int e) { id_estudiante = e; }
	void setcodigo(string c) { codigo = c; }
	void setnombres(string n) { nombres = n; }
	void setapellidos(string a) { apellidos = a; }
	void setdireccion(string d) { direccion = d; }
	void settelefono(int t) { telefono = t; }
	void setfecha_nacimiento(string f) { fecha_nacimiento = f; }
	void setid_tipo_sangre(int ts) { id_tipo_sangre = ts; }

	//get para mostrar el atributo 
	int getId_estudiante(int e) { return id_estudiante; }
	string getcodigo(string c) { return codigo; }
	string getnombres(string n) { return nombres; }
	string getapellidos(string a) { return apellidos; }
	string getdireccion(string d) { direccion; }
	int gettelefono(int t) { return telefono; }
	string getfecha_nacimiento(string f) { return fecha_nacimiento; }
	int getid_tipo_sangre(int ts) { return id_tipo_sangre; }

	//metodos

	void crear() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconector()) {
			string t = to_string(telefono);
			string id_ts = to_string(id_tipo_sangre);
			string consulta = "INSERT INTO estudinates (codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre)VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + fecha_nacimiento + "','" + id_ts + "'); ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconector(), c);
			if (!q_estado) {
				cout << "ingreso de datos exitosos... " << endl;
			}
			else {
				cout << "consulta fallida" << endl;
			}
		cn.cerrar_conexion();
		}
	}
	void leer() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconector()) {
			cout << "_______Datos del estudiante_______" << endl;
			string consulta = "SELECT * FROM db_escuela.estudiantes; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconector(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconector());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}
			}
		}
		else {
			cout << "XXXX Fallo la conexion XXXX" << endl;
		}
		cn.abrir_conexion();
	}
	void actualizar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconector()) {
			string t = to_string(telefono);
			string id_ts = to_string(id_tipo_sangre);
			string id_e = to_string(id_estudiante);
			string consulta = "update estudinates set codigo = '" + codigo + "' , nombres = '" + nombres + "' , apellidos = '" + apellidos + "', direccion = '" + direccion + "' , telefono = " + t + " , fecha_nacimiento = '" + fecha_nacimiento + "', id_tipo_sangre = " + id_ts + " where id_estudiante = " + id_e + " ";
				const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconector(), c);
			if (!q_estado) {
				cout << "ingreso de modificacion exitosa ... " << endl;
			}
			else {
				cout << "modificacion fallida" << endl;
			}
		cn.cerrar_conexion();
		}
	}
	void borrar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconector()) {
			string t = to_string(telefono);
			string id_ts = to_string(id_tipo_sangre);
			string id_e = to_string(id_estudiante);
			string consulta = "delete from where id_estudiante = " + id_e + "";
				const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconector(), c);
			if (!q_estado) {
				cout << "eliminacion de datos exitosa ... " << endl;
			}
			else {
				cout << "eliminacion fallida" << endl;
			}

		cn.cerrar_conexion();
		}
	}
};