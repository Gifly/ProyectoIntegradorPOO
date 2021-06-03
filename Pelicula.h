#ifndef Pelicula_h
#define Pelicula_h

#include <string>
#include <iostream>
#include "Video.h"

using namespace std;

class Pelicula:public Video{
    public:
        Pelicula();
        Pelicula(int id, string _titulo, string _genero,  int _duracion, int _calificacion);
        void muestra();
};

Pelicula :: Pelicula() : Video(){
    idVideo = 0;
    titulo = "";
    genero = "";
    duracion = 0;
    calificacion = 0;
}

Pelicula :: Pelicula(int id, string _titulo, string _genero, int _duracion, int _calificacion) :Video(id, _titulo, _genero,  _duracion, _calificacion){
    idVideo = id;
    titulo = _titulo;
    genero = _genero;
    duracion = _duracion;
    calificacion = _calificacion;
}

void Pelicula::muestra(){
    cout << "Titulo: " << titulo << endl;
    cout << "Genero: " << genero << endl;
    cout << "Duración : " << duracion << " min"<< endl;
    cout << "Calificación: " << calificacion  <<  " Estrellas"<< endl;
    cout << "Id de Película: "<< idVideo << endl;
    cout << endl;
}
#endif /* Pelicula_h */
