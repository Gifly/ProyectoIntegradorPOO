#include <iostream>
#include <fstream>
#include "Usuario.h"
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
using namespace std;

int main(){
    Video *arrVideo[50];
    Usuario persona1;
    string nombreArchivo;
    //cout << "Ingresa el archivo de video que desees" << endl;
    char tipoVideo;
    int id, duracion, calificacion, episodio, temporada, i;
    string titulo, genero, serie;
    
    cin >> nombreArchivo;
    ifstream ArchivoVideos(nombreArchivo);
    while(ArchivoVideos >> tipoVideo){
        if(tipoVideo ==  'p'){
            ArchivoVideos >> id >> titulo >> genero >> duracion >> calificacion;
            arrVideo[i] = new Pelicula(id, titulo, genero, duracion, calificacion);
            i++;
        }
        else if(tipoVideo == 'e')
        {
            ArchivoVideos >> id >> titulo >> genero >> duracion >> calificacion >> serie >> episodio >> temporada;
            arrVideo[i] = new Episodio(id, titulo, genero, duracion, calificacion, serie, episodio, temporada);
        }
    }
    
    return 0;
}