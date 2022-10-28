#include"clases.h"
#include"metodos.h"

string driver_name, car, destino; string text; int chofi, destin, carro; int precio_carro, precio_destino, precio_final;    int aux=0; //op 1 travel now
int day, month, year;  //op 3 future trip
set<Calificacion> calificacion; int stars=0;  Fecha fecha; //op 4 calificar drivers
string color, nombre; int llantas;  string marca; //op 6  suggestions

int main()
{
    system("cls");
    mostrarArchivo("LetrasUber.txt");
    login();
    ofstream archivoEscr; ifstream archivoLec;
    
    system("cls");
    cout<<"Welcome!"<<endl;
    int opcion;
    do
    {
        menu();
        cin>>opcion;
        
        switch (opcion)
        {
        case 1:  //viajar ahora     

                system("cls");
                archivoEscr.open("viajes_realizados.txt", ios :: out | ios::app);
                if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}

                //elegir destino 
                cout<<"\nChoose the destination: "<<endl; 
                mostrarArchivo("Destinos.txt");

                cin>>destin; system("cls");
                destino = nombre_destino(destin);
                precio_destino = destino_precio(destin);

                //elegir conductor
                cout<<"\nChoose the driver: "<<endl; 
                mostrarArchivo("Conductores.txt");

                cin>>chofi; system("cls");
                driver_name = nombre_conductor(chofi);

                //elegir carro
                cout<<"\nChoose the car : "<<endl;  
                mostrarArchivo("Carros.txt");

                cin>>carro; system("cls");
                car = nombre_vehiculo(carro);
                precio_carro = vehiculo_precio(carro);

                //guardar en historial 
                precio_final = precio_carro + precio_destino;
                archivoEscr<<date_hour()<<endl;
                archivoEscr<<"Driver: "<<driver_name<<"    "<<"Car: "<<car<<"    "<<"Destination: "<<destino<<"    "<<"Total Price: "<<precio_final<<endl<<endl;
                archivoEscr.close();

                //hilo  (tiempo en que el uber llegará a recogerme) 
                pthread_t my_thread1; int i;
                pthread_create(&my_thread1,NULL,&worker,NULL ); //inicia hilo de tiempo de espera
                pthread_join(my_thread1,(void**)&i);
                system("cls");
                cout<<"Your uber arrived, enjoy your trip.\n\n";

                break;
        case 2: //mostrar historial
                system("cls");
                mostrarArchivo("viajes_realizados.txt");
        break;
        case 3: //reserve a future trip
                system("cls");
                archivoEscr.open("Futuros_viajes.txt", ios :: out | ios::app);
                if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}

                //elegir destino 
                cout<<"\nChoose the destination: "<<endl; 
                mostrarArchivo("Destinos.txt");

                cin>>destin; system("cls");
                destino = nombre_destino(destin);
                precio_destino = destino_precio(destin);

                //elegir conductor
                cout<<"\nChoose the driver: "<<endl; 
                mostrarArchivo("Conductores.txt");

                cin>>chofi; system("cls");
                driver_name = nombre_conductor(chofi);

                //elegir carro
                cout<<"\nChoose the car : "<<endl;  
                mostrarArchivo("Carros.txt");

                cin>>carro; system("cls");
                car = nombre_vehiculo(carro);
                precio_carro = vehiculo_precio(carro);

                //elegir fecha

                cout<<"\nType the date of your trip (dd,m,yyyy)"<<endl<<endl; 
                cout<<" Type the day : "; cin>>day; 
                cout<<" Type the month : "; cin>>month;  
                cout<<" Type the year : "; cin>>year; 

                fecha = Fecha(day,month,year);
            
                //guardar en futuros viajes 
                precio_final = precio_carro + precio_destino;
                archivoEscr<<"Day the trip was booked: "<<date_hour()<<endl; //"         Day of the trip: "<<day<<"";
                archivoEscr<<"Travel date:  "<<date(fecha)<<"             Remaining days: "<<diasRestantes(fecha)<<endl;
                archivoEscr<<"Driver: "<<driver_name<<"    "<<"Car: "<<car<<"    "<<"Destination: "<<destino<<"    "<<"Total Price: "<<precio_final<<endl<<endl;
                archivoEscr.close();

                system("cls");

                cout<<"Booked trip, be aware of the date the uber will pick you up.\n\n";

        break;
        case 4:  //show future trips
                system("cls");
                cout<<"Future trips:"<<endl<<endl;
                mostrarArchivo("Futuros_viajes.txt");

        break;

        case 5: //calificate drivers
                
                system("cls");
                cout<<"Choose the driver you want to rate: "<<endl<<endl; 
                mostrarArchivo("Conductores.txt");

                cin>>chofi;
                driver_name = nombre_conductor(chofi);
              //  if(buscarEnArchivo(driver_name) == false)
                
                        cout<<"Type the number of stars: (1-5): "; cin>>stars; system("cls");
                        calificacion.insert(Calificacion(stars,driver_name)); //crear set 
                        cout<<"Qualified driver, thank you."<<endl;
                        for(set<Calificacion>::iterator it = calificacion.begin(); it != calificacion.end(); it++)  //solo imprimir
                        {
                        it-> print();
                        }
    
        break;

        case 6: //show driver rates
                system("cls");
                cout<<"Driver rates:"<<endl;     mostrarArchivo("calificaciones.txt");
        break;

        case 7: //show info drivers and cars 
                system("cls");
                cout<<"Available drivers:"<<endl;          mostrarArchivo("Conductores.txt");
                cout<<"\nAvailable vehicles:"<<endl;       mostrarArchivo("Carros.txt");
        break;

        case 8: //suggest add new vehicles
                system("cls");
                cout<<"Propose to add new vehicles"<<endl; cout<<"If you want to suggest a car, press 1.\nIf you want to suggest a motorcycle, press 2."<<endl;
                
                int n; cin>>n;   system("cls");
                Vehiculo *vector[3];

                archivoEscr.open("sugeridos.txt", ios :: out | ios::app);
                if(archivoEscr.fail()){cout<<"El archivo no se puede abrir"<<endl; exit(1);}
                      
                switch (n)
                {
                      case 1:
                        cout<<"Suggest the car"<<endl;
                        cout<<"Type vehicle name: "; cin>>nombre;  cout<<"Type vehicle brand: "; cin>>marca;   cout<<"Type the color: "; cin>>color;
                        vector[0] = new automovil(nombre,marca,color);
                        archivoEscr<<"Vehicle information: (color, name, model): "<<vector[0]->mostrar(); archivoEscr<<endl;
                        system("cls");
                      break;
                      case 2:
                        cout<<"Suggest the motorcycle"<<endl<<endl;
                        cout<<"Type motorcycle name: "; cin>>nombre;  cout<<"Type motorcycle brand: "; cin>>marca;   cout<<"Type the number of tires: "; cin>>llantas;
                        vector[1] = new moto(nombre,marca,llantas);
                        archivoEscr<<"Vehicle information: (color, name, number of tires): "<<vector[1]->mostrar();  archivoEscr<<endl;
                        system("cls");
                      break;
                      default: 
                        cout<<"Please enter a correct option "<<endl;
                      break;
                }          
                      archivoEscr.close();
                      cout<<"Request made, thanks.\n";     
        break; 

        case 9: //show suggested vehicles
               system("cls");
               cout<<"Suggested vehicles:"<<endl<<endl;
               mostrarArchivo("sugeridos.txt");
        break;
        case 10: //exit 
                system("cls");
                mostrarArchivo("ByeMsj.txt");
        break;          
        default: 
                system("cls");
                cout<<"Please enter a correct option"<<endl;
        break;
        }
    } while (opcion!=10);
    
  return 0;
}
