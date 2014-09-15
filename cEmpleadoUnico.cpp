//
//  cEmpleadoUnico.cpp
//  Agencia de traduccion
//
//  Created by Borja Irigoyen on 3/05/14.
//  Copyright (c) 2014 Practicas POO. All rights reserved.
//

#include "cEmpleadoUnico.h"
#include <fstream>

cEmpleadoUnico::cEmpleadoUnico(){
    nombre = "";
    disponible=true;
    nIdiomas = 0;
    for (int i=0; i<5; i++) {
        idiomas[i]="";
    }
}

cEmpleadoUnico::cEmpleadoUnico(string nom,int nI,string idi[]){
    nombre = nom;
    disponible=true;
    nIdiomas = nI;
    for (int i=0; i<nI; i++) {
        idiomas[i]=idi[i];
    }
}

void cEmpleadoUnico::mostrarEmpleados(){
    cout<<endl<<"Nombre: "<<nombre;
    cout<<endl<<"Numero de idiomas: "<<nIdiomas;
    for (int i=0; i<nIdiomas; i++) {
        cout<<endl<<"Idioma: "<<idiomas[i];
    }
}

bool cEmpleadoUnico::buscarIdioma(string idi){
    
    bool encontrado=false;
    int i=0;
    
    while ((i<nIdiomas)&&(!encontrado)) {
        if (idiomas[i]==idi)
            encontrado=true;
    }
    return encontrado;
}


