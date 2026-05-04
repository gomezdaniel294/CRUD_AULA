#include <iostream>
#include "Estudiante.h"
using namespace std;
int main()
{
	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0, id_estudiante = 0;
	cout << "ingrese codigo: ";
	cin >> codigo;
	cin.ignore();

	cout << "ingrese nombre del estudiante:" ;
	getline(cin, nombres);
	cout << "ingrese nombre del apellidos:";
	getline(cin, apellidos);
	cout << "ingrese Direccion:";
	getline(cin, direccion);
	cout << "ingrese Telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "ingrese Fecha de nacimiento:";
	getline(cin, fecha_nacimiento);
	cout << "ingrese tipo de sangre:";
	cin >> id_tipo_sangre;

	Estudiante e = Estudiante(id_estudiante, codigo, nombres, apellidos, direccion, fecha_nacimiento, telefono, id_tipo_sangre);
	e.crear();
	e.leer();

	cout << "ingrese id a modificar ";
	cin >> id_estudiante;
	cout << "ingrese codigo: ";
	cin >> codigo;
	cout << "ingrese nombre del estudiante: ";
	getline(cin, nombres);
	cout << "ingrese nombre del apellidos: ";
	getline(cin, apellidos);
	cout << "ingrese Direccion: ";
	getline(cin, direccion);
	cout << "ingrese Telefono: ";
	cin >> telefono;
	cout << "ingrese Fecha de nacimiento: ";
	getline(cin, fecha_nacimiento);
	cout << "ingrese tipo de sangre: ";
	cin >> id_tipo_sangre;

	e.setId_estudiante(id_estudiante);
	e.setcodigo(codigo);
	e.setnombres(nombres);
	e.setapellidos(apellidos);
	e.setdireccion(direccion);
	e.settelefono(telefono);
	e.setfecha_nacimiento(fecha_nacimiento);
	e.setid_tipo_sangre(id_tipo_sangre);

	e.actualizar();
		e.leer();

		cout << "ingrese id a eliminar  ";
		cin >> id_estudiante;
		e.setId_estudiante(id_estudiante);
		e.borrar();
		e.leer();
}