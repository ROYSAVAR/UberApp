#include<iostream>
#include<cstdlib>
#include<fstream> 
#include<vector>
#include<string>
#include<map>
#include<set>
#include<ctime>
#include<windows.h>
#include<pthread.h>
using namespace  std;

void menu()
{
    cout<<"\nChoose an option:\n";
    cout<<"1. Travel now. \n2. Show previous trips.\n3. Reserve a future trip.\n4. Show future trips.\n5. Calificate drivers.\n6. Show drivers' rates.\n7. Show drivers' and cars information.\n8. Suggest adding new cars.\n9. Show suggested cars.\n10.Exit.\n\n ";
}

void mostrarArchivo(string name) //mostrar archivos
{
  ifstream archivoLec;
  string text;

   archivoLec.open(name, ios::in);  //abrir archivo en modo lectura
   if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} 
   while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
   archivoLec.close();
}
void login() //inicio de sesion
{
  int cont = 0;
  string usuario = "Passenger1"; string contrasena = "password123"; string usuarioMetido, contraMetida;
   
    do //LOGIN
    {
       cout<<"USSERNAME: "; cin>>usuarioMetido; cout<<"PASSWORD:  "; cin>>contraMetida; 

       if(cont == 3) //si se intenta mas de 4 veces terminar el programa 
       {
        system("cls");
        cout<<"Too many trys, temporaly bloked."<<endl;
        exit(-1);  //salir de todo el programa
       } 

       if(contraMetida!=contrasena || usuario != usuarioMetido) // si ususario o contra estan mal, volver a intentar
       {
        system("cls");
        mostrarArchivo("LetrasUber.txt");
        cout<<"Ussername or password are wrong, please try again."<<endl;
       }
       cont++;
    } while (contraMetida!=contrasena || usuario != usuarioMetido);
}

string nombre_conductor(int chofi)
{
                string driver_name;
                if(chofi == 1){driver_name = "Ricardo Espinoza";}
                if(chofi == 2){driver_name = "Ivan Galban";}
                if(chofi == 3){driver_name = "Angel Alcantara";}
                if(chofi == 4){driver_name = "Caleb Flores";}
                if(chofi == 5){driver_name = "Maria Rodriguez";}
                if(chofi == 6){driver_name = "Ana Martinez ";}
                if(chofi == 7){driver_name = "Juan Hernandez";}
  return driver_name;
}

string nombre_vehiculo(int carro)
{
                string car;
                if(carro == 1){car = "VolksWagen Sedan";}
                if(carro == 2){car = "Nissan Sentra"; }
                if(carro == 3){car = "VolksWagen Vento";}
                if(carro == 4){car = "Nissan March"; }
                if(carro == 5){car = "Nissan Frontier";}
                if(carro == 6){car = "VolksWagen Chevy";}
                if(carro == 7){car = "Lamborhini Veneno";}
                if(carro == 8){car = "Camaro ZL1"; }
                if(carro == 9){car = "Audi A200"; }
  return car;
}

int vehiculo_precio(int carro)
{
                int precio_carro;
                if(carro == 1){precio_carro = 1000;}
                if(carro == 2){precio_carro = 1500;}
                if(carro == 3){precio_carro = 1500;}
                if(carro == 4){precio_carro = 1250;}
                if(carro == 5){precio_carro = 1900;}
                if(carro == 6){precio_carro = 1100;}
                if(carro == 7){precio_carro = 3500;}
                if(carro == 8){precio_carro = 4500;}
                if(carro == 9){precio_carro = 4150;}
  return precio_carro;
}

string nombre_destino(int dest)
{
  string destino;
                if(dest == 1){destino = "Colima"; }
                if(dest == 2){destino = "Quintana Roo"; }
                if(dest == 3){destino = "Guadalajara"; }
                if(dest == 4){destino = "Zacatecas";}
                if(dest == 5){destino = "Monterrey"; }
                if(dest == 6){destino = "Chihuahua"; }
                if(dest == 7){destino = "Veracruz";  }
                if(dest == 8){destino = "CDMX";  }
                if(dest == 9){destino = "Durango";  }
                if(dest ==10){destino = "Sinaloa"; }
  return destino;
}

int destino_precio(int dest)
{
  int precio_destino;
                if(dest == 1){precio_destino = 850;}
                if(dest == 2){precio_destino = 1600;}
                if(dest == 3){precio_destino = 450;}
                if(dest == 4){precio_destino = 250;}
                if(dest == 5){precio_destino = 650;}
                if(dest == 6){precio_destino = 850;}
                if(dest == 7){precio_destino = 1050;}
                if(dest == 8){precio_destino = 900;}
                if(dest == 9){precio_destino = 650;}
                if(dest ==10){ precio_destino = 850;}
  return precio_destino;
}

//hilos
//tiempo en el que el uber llega a recogerme
void *worker(void *arg) 
{
  int seg = 20;
  bool ciclo = true;
  while (ciclo)
  {
    system("cls"); //limpiar consola
    cout<<"Trip created, your uber will arrive in:    ";
    cout<<seg<<" seconds"<<endl;
    Sleep(1000); //funcion para definir en cuanto tiempo quiero que se este actualizando el while en milisegundos (1000 seria 1 seg)
    seg--;
    if(seg == 0)
    {
      ciclo = false;
    }
  }
    pthread_exit(NULL);
}



