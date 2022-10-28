#include<iostream>
#include<cstdlib>
#include<fstream> 
#include<string>
#include<map>
#include<set>

using namespace  std;
class Calificacion //calificar conductores
{
    int n_estrellas;
    string name;

    public: 
        Calificacion():n_estrellas(0),name("")  {} //inicializarlo vacío
        Calificacion(int n_estrellas, string name):n_estrellas(n_estrellas),name(name){}  //con esto ya no es necesario hacer los gets 
  
        void print() const
        {
            ofstream archivoEscr;
            archivoEscr.open("calificaciones.txt", ios :: out | ios::app);
            if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}

            archivoEscr<<"Name: "<<name<<"\t  ------------->  Number of stars: "<<n_estrellas<<endl;
            archivoEscr.close();
        }
        bool operator<(const Calificacion &other) const  //esto es para que jale sets y maps con objetos, ya que usa < para comparar y ordenar
        {
            return n_estrellas < other.n_estrellas;
        }
};
