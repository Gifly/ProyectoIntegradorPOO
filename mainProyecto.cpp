#include <iostream>
#include <fstream>
#include <string>
#include "Usuario.h"
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
using namespace std;

int main(){
    Video *arrVideos[50];
    Usuario persona1;
    string nombreArchivo;
    //cout << "Ingresa el archivo de video que desees" << endl;
    char tipoVideo, tipoVideoArr[50];
    int id, duracion, calificacion, episodio, temporada, j, contadorVideos, op, calificacionEsp, idUser;
    string titulo, genero, serie, generoEsp, nombreTemporal, cuentaTemporal;
    
    cin >> nombreArchivo;
    ifstream ArchivoVideos(nombreArchivo);
    while(ArchivoVideos >> tipoVideo){
        if(tipoVideo ==  'p'){
            ArchivoVideos >> id >> titulo >> genero >> duracion >> calificacion;
            arrVideos[j] = new Pelicula(id, titulo, genero, duracion, calificacion);
            tipoVideoArr[j] = 'p';
            j++;
        }
        else if(tipoVideo == 'e')
        {
            ArchivoVideos >> id >> titulo >> genero >> duracion >> calificacion >> serie >> episodio >> temporada;
            arrVideos[j] = new Episodio(serie, episodio, temporada,id,  titulo, genero, duracion, calificacion);
            tipoVideoArr[j] = 'e';
            j++;
        }
    }
    contadorVideos = j;

   do {
        cout << "Menu de opciones " << endl;
        cout << endl;
        cout << "1) Consultar la lista de videos disponibles " << endl;
        cout << "2) Consultar la lista de Videos con cierta calificación " << endl;
        cout << "3) Consultar la lista de Videos por género " << endl;
        cout << "4) Ver datos del usuario " << endl;
        cout << "5) Modificar el perfil del usuario " << endl;
        cout << "6) Agregar video a la lista del usuario " << endl;
        cout << "7) terminar " << endl;
        cout << "opcion ->";
        cin >> op;
        
        switch (op) {
            case 1: {
                for(int i=0; i <contadorVideos; i++){
                    if (tipoVideoArr[i] == 'e')
                    {
                        cout << "Episodio "<<endl;
                        arrVideos[i]->muestra();
                    } else {
                        cout << "Pelicula "<<endl;
                        arrVideos[i]->muestra();
                    }
                }
                break;
            }
        
            case 2: {
                cin >> calificacionEsp;
                if (calificacionEsp < 0 || calificacionEsp > 5)
                {
                    cout << "Error Ingresar una Calificación Valida!" << endl;
                    cout << endl;
                } else {
                    for(int i=0; i <contadorVideos; i++){
                        if (arrVideos[i]->getCalificacion()==calificacionEsp){
                            arrVideos[i]->muestra();
                        }
                    }
                }    
                break;
            }
                
            case 3:  {
                cin >> generoEsp;
                for(int i=0; i <contadorVideos; i++){
                    if (arrVideos[i]->getGenero()==generoEsp){
                        arrVideos[i]->muestra();
                    }
                }                   
                break;
            }

            case 4: {
                cout << "Nombre :" <<persona1.getNombre()<< endl;
                cout << "Usuario: "<<persona1.getCuenta() << endl;
                cout << endl;
                for(int i=0; i<contadorVideos;i++){
                    for(int k=0; k<persona1.getContadorVideos();k++){
                        if(arrVideos[i]->getIdVideo() == persona1.getUnIdMisVideos(k)){
                            arrVideos[i]->muestra();
                        }
                    }
                }
                break;
            }
                
            case 5:  {
                cin >> nombreTemporal;
                cin >> cuentaTemporal;
                if(nombreTemporal == persona1.getNombre() && cuentaTemporal == persona1.getCuenta()){
                    string _nombre, _cuenta;
                    cout << "Ingrese El Nuevo Nombre :"<<endl;
                    cin >> _nombre;
                    cout << endl;
                    cout << "Ingrese El Nuevo Usuario :"<< endl;
                    cin >> _cuenta;
                    cout << endl;
                    persona1.setNombre(_nombre);
                    persona1.setCuenta(_cuenta);
                } else{
                    cout << "Error Esas Credenciales no se encuentran en nuestro Sistema...";
                    cout << endl;
                }                
                break;
            }

            case 6:  {
                bool loop = false;
                while(loop == false){
                cin >> idUser;
                    for (int i=0;i<contadorVideos;i++){
                        if(arrVideos[i]->getIdVideo()==idUser){
                            persona1 += idUser;
                            loop = true;
                        }
                    }   
                }              
                break;
            }
        }
        
    } while (op != 7);
    return 0;
}