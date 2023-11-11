#include <iostream>

//derivadas - los pondre como double por el momento creo que usaremos eso
//Recordar que las derivadas pueden cambiar respecto a la funcion de activacion
double neto_peso(){
    return 0;
}

double salida_neto(){
    return 0;
}

double loss_salida(){
    return 0;
}

//funcion principal derivada loss respecto al peso
double loss_peso(){
    return neto_peso() * salida_neto() * loss_salida();
}