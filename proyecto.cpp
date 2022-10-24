#include"myLib.h"

string driver_name, car, destino; string text; int chofi, destin, carro; int precio_carro, precio_destino, precio_final;  //op 1 travel now
set<Calificacion> calificacion; int stars=0; //op 4 calificar drivers
string color, nombre; int llantas;  string marca; //op 6  suggestions

int main()
{
  login();
    ofstream archivoEscr; ifstream archivoLec;
    
    cout<<"Welcome!"<<endl;
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
                cout<<"\nChoose the destination: "<<endl; 
                mostrarArchivo("Destinos.txt");

                cin>>destin;
                destino = nombre_destino(destin);
                precio_destino = destino_precio(destin);

                //elegir conductor
                cout<<"\nChoose the driver: "<<endl; 
                mostrarArchivo("Conductores.txt");

                cin>>chofi;
                driver_name = nombre_conductor(chofi);

                //elegir carro
                cout<<"\nChoose the car : "<<endl;  
                mostrarArchivo("Carros.txt");

                cin>>carro;
                car = nombre_vehiculo(carro);
                precio_carro = vehiculo_precio(carro);

                //imprimir en historial 
                precio_final = precio_carro + precio_destino;
                archivoEscr<<date_hour()<<endl;
                archivoEscr<<"Driver: "<<driver_name<<"    "<<"Car: "<<car<<"    "<<"Destination: "<<destino<<"    "<<"Total Price: "<<precio_final<<endl<<endl;
                archivoEscr.close();

                //hilo  (tiempo en que el uber llegará) 
                pthread_t my_thread1; int i;
                pthread_create(&my_thread1,NULL,&worker,NULL ); //inicia hilo 
                pthread_join(my_thread1,(void**)&i);
              //  pthread_exit(NULL);  

                cout<<"Your uber arrived, enjoy your trip.\n\n";
                break;
        case 2:
                mostrarArchivo("viajes_realizados.txt");
          break;
        case 3: //reserve a future trip
              
                cout<<"Booked trip, be aware of the date the uber will pick you up.\n\n";

          break;
        case 4: //calificate drivers

                cout<<"Choose the driver you want to rate: "<<endl; 
                mostrarArchivo("Conductores.txt");

                cin>>chofi;
                driver_name = nombre_conductor(chofi);

                cout<<"Type the number of stars: (1-5): "; cin>>stars;
                calificacion.insert(Calificacion(stars,driver_name)); //crear set 

                for(set<Calificacion>::iterator it = calificacion.begin(); it != calificacion.end(); it++)  //solo imprimir
                {
                 it-> print();
                }
    
          break;

        case 5: //show info drivers and cars 
                cout<<"Available drivers:"<<endl;          mostrarArchivo("Conductores.txt");
                cout<<"\nAvailable vehicles:"<<endl;       mostrarArchivo("Carros.txt");
          break;

        case 6: //sugerir añadir nuevos vehiculos
          cout<<"Propose to add new vehicles"<<endl; cout<<"If you want to suggest a car, press 1.\nIf you want to suggest a motorbike, press 2."<<endl;
          
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
                  archivoEscr<<"Vehicle information: (color, name, model): "<<vector[0]->mostrar(); archivoEscr<<endl;
                break;
                case 2:
                  cout<<"Suggest the motorbike"<<endl;
                  cout<<"Type vehicle name: "; cin>>nombre;  cout<<"\nType vehicle brand: "; cin>>marca;   cout<<"\nType the number of tires: "; cin>>llantas;
                  vector[1] = new moto(nombre,marca,llantas);
                  archivoEscr<<"Vehicle information: (color, name, number of tires): "<<vector[1]->mostrar();  archivoEscr<<endl;
                break;
                default: 
                  cout<<"Please enter a correct option "<<endl;
                break;
          }          
                archivoEscr.close();
                cout<<"Request made, thanks.\n";      
                  
          break; 

        case 7: //mostrar carros sugeridos
               cout<<"Suggested vehicles:"<<endl;
               mostrarArchivo("sugeridos.txt");
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