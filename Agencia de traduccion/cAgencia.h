//
//  cAgencia.h
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#ifndef Agencia_de_traduccion_cAgencia_h
#define Agencia_de_traduccion_cAgencia_h
#include <iostream>
#include <fstream>
#include "cEmpleadoUnico.h"
#include "cEmpleadoEquipo.h"
#include "cServicio.h"


using namespace std;

class cAgencia{
    
private:
    
    cEmpleadoUnico *empleados[100];         //Creamos un array de punteros de empleados.
    cServicio *servicios[10];               //Creamos un array de punteros para crear los servicios.
    int nEmpleados;
    int nServicios;
    void importarFichero();                 //Metodo que importa la informacion del fichero en el array de punteros.
    void contratarServicio();               //Contrata un servicio de traduccion.
    void rescindirServicio();               //Rencinde un servicio de traduccion.
    void visualizarServicios();             //Muestra todos los servicios que estan en la agencia.
    void contratarEmpleado();               //Contrata a un empleado.
    void despedirEmpleado();                //Despide a un empleado.
    void mostrarEmpleado();                 //Muestra la informacion de un empleado.
    void listaEmpleados();                  //Muestra una lista completa de todos los empleados que hay.
    
public:
    
    cAgencia();
    ~cAgencia();
    void menu();                            //Menu en el que aparecen todas las opciones.
};

#endif
