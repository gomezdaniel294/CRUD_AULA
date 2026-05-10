#include <iostream>
#include "Estudiante.h"
#include "Validaciones.h"
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


	//Validaciones 

	if (!Validaciones::validarCodigo(codigo))
		return 0;


	if (!Validaciones::validarNombre(nombres))
		return 0;

	if (!Validaciones::validarApellido(apellidos))
		return 0;

	if (!Validaciones::validarDireccion(direccion))
		return 0;

	if (!Validaciones::validarTelefono(to_string(telefono)))
		return 0;

	if (!Validaciones::validarFechaNacimiento(fecha_nacimiento))
		return 0;


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

	//validaciones 
	if (!Validaciones::validarCodigo(codigo))
		return 0;

	if (!Validaciones::validarNombre(nombres))
		return 0;

	if (!Validaciones::validarApellido(apellidos))
		return 0;

	if (!Validaciones::validarDireccion(direccion))
		return 0;

	if (!Validaciones::validarTelefono(to_string(telefono)))
		return 0;

	if (!Validaciones::validarFechaNacimiento(fecha_nacimiento))
		return 0;

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