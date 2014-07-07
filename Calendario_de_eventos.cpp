//Carlos requiere tener un control de sus actividades diarias. Para ello está buscando una aplicación informática que
//le permita realizar ese control. Carlos necesita que la aplicación le permita ingresar nuevos eventos en su
//calendario y que luego le permita visualizar cronológicamente los eventos planificados para el día de hoy y para
//toda la semana.

#include <fstream>//utilizacion de la funcion ofstream
#include <iostream> //utilizacion de la funcion getch
#include <conio>    //utilizacion de la funcion cout
#include <stdio>
#include <time>
#include <string>
#include <stdlib>

//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
int Principal()
{
	clrscr ();
	int a;
	cout<<"1.-Ingresar nuevo evento "<<endl;
   cout<<"2.-Ver mis eventos para hoy "<<endl;
   cout<<"3.-Ver mis eventos para toda la semana "<<endl;
   cout<<"4.-SALIR "<<endl;
   cin>>a;
   return (a);
}
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
Ingresar_nuevo_evento()
{
	ofstream archivo("D:miarchivo.txt", ios::app);
	clrscr ();
	char nuevo_evento[100];
   char descripcion_del_evento[100];
   int dia;
   int mes;
   int anio;
   char horai[5];
   char horaf[5];
      	cout<<"ingrese el nombre de el nuevo evento: "<<endl;
         cin>>nuevo_evento;
      	cout<<"ingrese una descripcion del evento: "<<endl;
         cin>>descripcion_del_evento;
      	cout<<"ingrese el dia del evento: "<<endl;
         cin>>dia;
      	cout<<"ingrese el mes del evento: "<<endl;
         cin>>mes;
      	cout<<"ingrese el año del evento: "<<endl;
         cin>>anio;
         cout<<"ingrese la hora a la que inicia el evento: "<<endl;
         cin>>horai;
         cout<<"ingrese la hora a la que finaliza el evento: "<<endl;
         cin>>horaf;
         archivo<<'*'<<dia<<'-';
         archivo<<'+'<<mes<<'-';
         archivo<<'-'<<anio<<endl;
         archivo<<  nuevo_evento<<endl;
         archivo<< descripcion_del_evento<<endl;
         archivo<< horai<<endl;
         archivo<< horaf<<endl<<'*';
         clrscr ();
}
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
Ver_mis_eventos_para_hoy()
{
	clrscr ();
	time_t t=time(0); //pone el reloj a cero
	tm *horaac =localtime(&t);   //crea un puntero para la hora local
	cout<<"Fecha actual: "<<endl;
   cout<<"HORA: "<<horaac->tm_hour<<"H"<<horaac->tm_min<<endl<<"FECHA: "<<horaac->tm_mday<<"/"<<(horaac->tm_mon+1)<<"/"<<(horaac->tm_year+1900)<<endl; //punteros a diferentes variables hora fecha.... etc
   char dia[1];
   char mes[1];
	char anio[3];
	char caracter;
	ifstream archivo("D:miarchivo.txt", ios::in);
	while(!archivo.eof()) //lee linea por linea
	{
		archivo.get(caracter);//lee caracter por caracter
		cout<<caracter;       //imprime caracter por caracter
      if(caracter=='*')
      {
      	archivo.get(caracter);
         for(int i=0;i<=1;i++)
         {
         	dia[i]=caracter;
            archivo.get(caracter);
         }
         int comparacionD;
      	comparacionD=atoi(dia);
         if(comparacionD==horaac->tm_mday)
         {
         	archivo.get(caracter);//lee caracter por caracter
				cout<<caracter;       //imprime caracter por caracter
      		if(caracter=='+')
      		{
      			archivo.get(caracter);
         		for(int j=0;j<=1;j++)
         		{
         			mes[j]=caracter;
            		archivo.get(caracter);
         		}
         		int comparacionm;
      			comparacionm=atoi(mes);
         		if(comparacionm==horaac->tm_mon+1)
         		{
               	archivo.get(caracter);//lee caracter por caracter
						cout<<caracter;       //imprime caracter por caracter
      				if(caracter=='-')
      				{
      					archivo.get(caracter);
         				for(int m=0;m<=1;m++)
         				{
         					anio[m]=caracter;
            				archivo.get(caracter);
         				}
         				int comparaciona;
      					comparaciona=atoi(anio);
         				if(comparaciona==horaac->tm_year+1900)
         				{
         				}
         			}
         		}
				}
			}
   	}
		archivo.close();
		getch();
	}
}
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
Ver_mis_eventos_para_toda_la_semana()
{
	cout<<"Semana actual: "<<endl;
   cout<<"lista de eventos "<<endl;
   getch();

}
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
main()
{

	ifstream archivo("D:miarchivo.txt", ios::in);
   if (archivo)
   {
   	ofstream archivo("D:miarchivo.txt", ios::app);
   }
   else
   {
   	ofstream archivo("D:miarchivo.txt");
   	archivo.close();

   }

	int s;
   do {
   s=Principal();
   switch(s)
	{
		case 1:
			Ingresar_nuevo_evento();
			break;

		case 2:
			Ver_mis_eventos_para_hoy();
			break;

  	 	case 3:
			Ver_mis_eventos_para_toda_la_semana();
  	   	 break;

      case 4:
			cout<<"precione una tecla para salir"<<endl;;
  	   	 break;

		default:
			cout<<"Ha ingresado un numero no valido"<<endl;
			break;
	}
   }while(s!=4);

   getch();
}


  /*pra acceder al los primeros hacer un  recorrido del archivo con
   main()
{
char caracter;
ifstream archivo("C:/BC5/Archivos/miarchivo.txt", ios::in);
while(!archivo.eof())
{
archivo.get(caracter);
cout<<caracter;
}
archivo.close();
getch();
}   atoi()*/




