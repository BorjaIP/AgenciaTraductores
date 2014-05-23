//
//  cEmpleadoUnico.h
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#ifndef Agencia_de_traduccion_cEmpleadoUnico_h
#define Agencia_de_traduccion_cEmpleadoUnico_h
#include "cEmpleado.h"

class cEmpleadoUnico:public cEmpleado {
    
public:
    
    cEmpleadoUnico();
    cEmpleadoUnico(string,int,string[]);
    string getNombre(){return nombre;}                      //Devuelve el nombre.
    int getnIdiomas(){return nIdiomas;}                     //Devuelve el numero de idiomas.
    string getidiomas(int i){return idiomas[i];}            //Devuelve los idiomas.
    bool getDisponible(){return disponible;}                //Devuelve si esta disponible.
    void setDisponible(bool dis){disponible=dis;}           //Cambiamos el estado de disponible.
    void mostrarEmpleados();                                //Muestra la informacion del empleado.
    bool buscarIdioma(string);                              //Compara el idioma pasado por parametro con los que tiene ese empleado.
};


#endif
