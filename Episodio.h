#ifndef Episodio_h
#define Episodio_h
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;

class Episodio : public Video{
    private:
        string serie;
        int numeroEp;
        int numTemporada;
    
    public:
        Episodio();
        Episodio(string _serie, int Ep, int temp, int id, string _titulo,  string _genero, int _duracion, int _calificacion);
        void setSerie(string _serie){ serie = _serie;};
        string getSerie(){ return serie;};
        void setNumeroEp(int Ep){ numeroEp = Ep;};
        int getNumeroEp(){ return numeroEp; };
        void setNumTemporada(int temp){ numTemporada = temp;};
        int getNumTemporada(){ return numTemporada;};
        void muestra();
};

Episodio :: Episodio() : Video(){
    serie = "";
    numeroEp = 0;
    numTemporada = 0;
}

Episodio :: Episodio(string _serie, int Ep, int temp, int id, string _titulo, string _genero, int _duracion, int _calificacion):Video(id, _titulo, _genero, _duracion, _calificacion){
    serie = _serie;
    numeroEp = Ep;
    numTemporada = temp;
}

void Episodio::muestra(){
    cout << "Titulo: " << titulo << endl;
    cout << "| Temporada " << numTemporada << " | Episodio " << numeroEp<< " |"<< endl;
    cout << "Genero: " << genero << endl;
    cout << "Duración : " << duracion << " min"<< endl;
    cout << "Ïd de Episodio: "<< idVideo << endl;
    cout << "Calificación: " << calificacion << " Estrellas" << endl;
    cout << endl;
}

#endif /* Episodio_h */