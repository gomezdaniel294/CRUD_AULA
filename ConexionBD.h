#pragma once
#include <mysql.h>
#include <iostream> 
using namespace std; 
class ConexionBD{
private :
	MYSQL* conector;
public: 
	void abrir_conexion() {
		conector = mysql_init(0);
		conector = mysql_real_connect(conector, "localhost","root","LinK@nao294GS","db_escuela",3306,NULL,0);
	}
	MYSQL* getconector() {
		return conector; 
	}
	void cerrar_conexion() {
		mysql_close(conector);
	}
};

