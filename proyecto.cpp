#include"myLib.h"

using namespace std;

string color, nombre; int llantas;  string marca; //op 6  suggestions
int num;  vector<int> propas;  int suma_Propinas =0;  //op4 propinas
string driver_name, car, destino; string text; int chofi, destin, carro; int precio_carro, precio_destino, precio_final;  //op 1 travel now
set<Estrellas> estrellas; string stars; //op 4 calificar drivers

int main()
{
  login();
 
    ofstream archivoEscr;
    ifstream archivoLec;
    
    cout<<"Welcome!"<<endl;
    //coment prueba
    //prueba 2
    int opcion;
    do
    {
      menu();
      cin>>opcion;
        switch (opcion)
        {
        case 1:  //viajar ahora     //ir guardando en historial
                
                archivoEscr.open("viajes_realizados.txt", ios :: out | ios::app);
                if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}

                //elegir destino 
                cout<<"\nChoose the destination: "; 
                archivoLec.open("Destinos.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Available destinations: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl<<endl;}
                archivoLec.close();

                destin = 0;
                cin>>destin;
                if(destin == 1){destino = "Colima"; precio_destino = 850;}
                if(destin == 2){destino = "Quintana Roo";  precio_destino = 1600;}
                if(destin == 3){destino = "Guadalajara";  precio_destino = 450;}
                if(destin == 4){destino = "Zacatecas";  precio_destino = 250;}
                if(destin == 5){destino = "Monterrey";  precio_destino = 650;}
                if(destin == 6){destino = "Chiuahua";  precio_destino = 850;}
                if(destin == 7){destino = "Veracruz";  precio_destino = 1050;}
                if(destin == 8){destino = "CDMX";  precio_destino = 900;}
                if(destin == 9){destino = "Durango";  precio_destino = 650;}
                if(destin == 10){destino = "Sinaloa"; precio_destino = 850; }

                //elegir conductor
                cout<<"\nChoose the driver: "; 
                archivoLec.open("Conductores.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Available drivers: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl<<endl;}
                archivoLec.close();

                chofi=0;
                cin>>chofi;
                driver_name = nombre_conductor(chofi);

                //elegir carro
                cout<<"\nChoose the car : ";  
                archivoLec.open("Carros.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Available cars: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl<<endl;}
                archivoLec.close();

                carro = 0;
                cin>>carro;
                if(carro == 1){car = "VolksWagen Sedan"; precio_carro = 1000;}
                if(carro == 2){car = "Nissan Sentra"; precio_carro = 1500;}
                if(carro == 3){car = "VolksWagen Vento"; precio_carro = 1500;}
                if(carro == 4){car = " Nissan March"; precio_carro = 1250;}
                if(carro == 5){car = "Nissan Frontier"; precio_carro = 1900;}
                if(carro == 6){car = "VolksWagen Chevy"; precio_carro = 1100;}
                if(carro == 7){car = "Lamborhini Veneno"; precio_carro = 3500;}
                if(carro == 8){car = "Camaro ZL1"; precio_carro = 4500;}
                if(carro == 9){car = "Audi A200"; precio_carro = 4150;}

                precio_final = precio_carro + precio_destino;
                archivoEscr<<date_hour()<<endl;
                archivoEscr<<"Driver: "<<driver_name<<"    "<<"Car: "<<car<<"    "<<"Destination: "<<destino<<"    "<<"Total Price: "<<precio_final<<endl<<endl;
                archivoEscr.close();
                cout<<"Trip created, wait for your uber at the point where you are right now.\n\n";
                break;
        case 2:
                archivoLec.open("viajes_realizados.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Previous trips: \n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
                archivoLec.close();
          break;
        case 3:
          break;
        case 4: //leave xtra tips and calificate drivers

                /*cout<<"Choose the driver you want to rate: "; 

                archivoLec.open("Conductores.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Available drivers: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl<<endl;}
                archivoLec.close();

                chofi=0;
                cin>>chofi;
                if(chofi == 1){driver_name = "Ricardo Espinoza";}
                if(chofi == 2){driver_name = "Ivan Galban";}
                if(chofi == 3){driver_name = "Angel Alcantara";}
                if(chofi == 4){driver_name = "Caleb Flores";}
                if(chofi == 5){driver_name = "Maria Rodriguez";}
                if(chofi == 6){driver_name = "Ana Martinez ";}
                if(chofi == 7){driver_name = "Juan Hernandez";}

                cout<<"Type the number of stars: (1-5): "; cin>>stars;
                estrellas.insert(Estrellas(stars,driver_name));

                archivoEscr.open("calificaciones.txt", ios :: out | ios::app);
                if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}

                for(set<Estrellas>::iterator it = estrellas.begin(); it != estrellas.end(); it++)  //solo imprimir
                {
                cout<<*it<<endl;
                }
                archivoEscr.close();*/
                
                
          break;
        case 5: //show info drivers and cars 
           archivoLec.open("Conductores.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Drivers: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
                archivoLec.close();
           archivoLec.open("Carros.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"\nAvailable Cars: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
                archivoLec.close(); 
          break;
        case 6: //sugerir añadir nuevos vehiculos
          cout<<"Propose to add new vehicles"<<endl; cout<<"If you want to suggest a car, press 1, if is a motorbike, press 2"<<endl;
          
          int n; cin>>n;   
          Vehiculo *vector[3];

           archivoEscr.open("sugeridos.txt", ios :: out | ios::app);
                if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}
          
          switch (n)
          {
              case 1:
                cout<<"Suggest the car"<<endl;
                cout<<"Type vehicle name: "; cin>>nombre;  cout<<"\nType vehicle brand: "; cin>>marca;   cout<<"\nType the color: "; cin>>color;
                vector[0] = new automovil(nombre,marca,color);
                archivoEscr<<"Vehicle information (color, name, model): "<<vector[0]->mostrar()<<endl;
              
              break;
              case 2:
                cout<<"Suggest the motorbike"<<endl;
                cout<<"Type vehicle name: "; cin>>nombre;  cout<<"\nType vehicle brand: "; cin>>marca;   cout<<"\nType the number of tires: "; cin>>llantas;
                vector[1] = new automovil(nombre,marca,color);
                archivoEscr<<"Vehicle information (color, name, number of tires): "<<vector[1]->mostrar();
              break;
              default: 
                cout<<"Please enter a correct option "<<endl;
              break;
          }          
                archivoEscr.close();
                cout<<"Request made\n";      
                break;
        
          break; 
        case 7: //mostrar carros sugeridos
          archivoLec.open("sugeridos.txt", ios::in);  //abrir archivo en modo lectura
                if(archivoLec.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);} cout<<"Suggested cars: \n\n";
                while(!archivoLec.eof()) { getline(archivoLec,text);  cout<<text<<endl;}
                archivoLec.close();
          break;
        case 8: //salir 
        cout<<"Closing App, Bye."<<endl;
          break;          
        
        default: cout<<"Please enter a correct option"<<endl;
          break;
        }
    } while (opcion!=8);
    
  return 0;
}