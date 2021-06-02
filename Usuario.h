#include <iostream>
#include "Video.h"
using namespace std;

class Usuario{
    private:
        string cuenta;
        string nombre;
        int misVideos[20];
        int contadorVideos;

    public:
        Usuario();
        void setCuenta(string _cuenta){ cuenta = _cuenta;};
        string getCuenta(){ return cuenta;};
        void setNombre(string _nombre){ nombre = _nombre;};
        string getNombre(){ return nombre;};
        int getContadorVideos(){ return contadorVideos; };
        int getUnIdMisVideos(int indice);
        int operator+(int id);
};

Usuario::Usuario(){
    nombre = "default";
    cuenta = "default";
    contadorVideos = 0;
    for(int i = 0; i < 20; i++){ misVideos[i] = 0; }
}

int Usuario::getUnIdMisVideos(int indice){
    for(int i = 0; i < 20; i++){
        if (indice == misVideos[i]){
            return misVideos[i];
        }
    }
}

int Usuario::operator+(int id){
    bool notPossible = false;
    for(int i = 0; i < 20; i++){
        if (misVideos[i] == id || contadorVideos >= 20)
        {
            notPossible = true; 
        }
    }
    if(notPossible == false){
        misVideos[contadorVideos] = id;
        contadorVideos++;
    }
    notPossible = false; 
}