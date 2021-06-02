#ifndef Video_h
#include <iostream>

using namespace std;

class Video{
    private:
        int idVideo;
        string titulo;
        string genero;
        int duracion;
        int calificacion;

    protected:
        Video();
        Video(int id, string _titulo, string _genero, int _duracion, int _calificacion);
        void setIdVideo(int id){ idVideo = id;};
        int getIdVideo(){ return idVideo; };
        void setTitulo(string _titulo){ titulo = _titulo; };
        string getTitulo(){ return titulo; };
        void setGenero(string _genero){ genero = _genero; };
        string setGenero(){ return genero; };
        void setDuracion(int _duracion){ duracion = _duracion; };
        int getDuracion(){ return duracion; };
        void setCalificacion(int _calificacion){ calificacion = _calificacion; };
        int getCalificacion(){ return calificacion; };
        void virtual muestra();
};

Video::Video(){
    idVideo = 0;
    titulo = "";
    genero = "";
    duracion = 0;
    calificacion = 0;
}

Video::Video(int id, string _titulo, string _genero, int _duracion, int _calificacion){
    idVideo = id;
    titulo = _titulo;
    genero = _genero;
    duracion = _duracion;
    calificacion = _calificacion;
}

void Video::muestra(){
    //TODO
}

#endif