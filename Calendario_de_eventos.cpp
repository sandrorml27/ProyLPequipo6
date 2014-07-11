//Carlos requiere tener un control de sus actividades diarias. Para ello está buscando una aplicación informática que
//le permita realizar ese control. Carlos necesita que la aplicación le permita ingresar nuevos eventos en su
//calendario y que luego le permita visualizar cronológicamente los eventos planificados para el día de hoy y para
//toda la semana.
//SANDRO MORENO	777
//JOHANNA DEL POZO
//ERICA PILCO
//GONZALO VELAZTEGUI


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
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"				 MENU DE EVENTOS "<<endl;
   cout<<endl;
   cout<<endl;
	cout<<"			1.-INGRESAR NUEVO EVENTO "<<endl;
   cout<<"			2.-VER MIS EVENTOS PARA HOY "<<endl;
   cout<<"			3.-VER MIS EVENTOS PARA TODA LA SEMANA "<<endl;
   cout<<"			4.-SALIR "<<endl;
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
   		clrscr ();
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<endl;
      	cout<<"	INGRESE EL NOMBRE DEL NUEVO EVENTO: "<<endl;
         cin>>nuevo_evento;
         clrscr ();
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<endl;
      	cout<<"	INGRESE LA DESCRIPCION DEL NUEVO EVENTO: "<<endl;
         cin>>descripcion_del_evento;
         clrscr ();
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<endl;
      	cout<<"	INGRESE EL DIA DEL EVENTO: "<<endl;
         cin>>dia;
         clrscr ();
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<endl;
      	cout<<"	INGRESE EL MES DEL EVENTO: "<<endl;
         cin>>mes;
         clrscr ();
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<endl;
      	cout<<"	INGRESE EL AÑO DEL EVENTO: "<<endl;
         cin>>anio;
         clrscr ();
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<"	INGRESE LA HORA DE INICIO DEL EVENTO: "<<endl;
         cin>>horai;
         clrscr ();
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<"	INGRESE LA HORA DE FINALIZACION DEL EVENTO: "<<endl;
         cin>>horaf;
         archivo<<'*'<<dia;
         archivo<<'-'<<mes;
         archivo<<'-'<<anio<<endl;
         archivo<<nuevo_evento<<endl;
         archivo<<descripcion_del_evento<<endl;
         archivo<<horai<<endl;
         archivo<<horaf<<endl<<endl;
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
   cout<<endl;
   cout<<endl;
   char dia[2];
   char mes[3];
	char anio[5];
	char caracter;
	ifstream archivo("D:miarchivo.txt", ios::in);
	while(!archivo.eof()) //lee linea por linea
	{
		archivo.get(caracter);//lee caracter por caracter
      if(caracter=='*')
      {
      	archivo.get(caracter);
         for(int i=0;i<=1;i++)
         {
         	dia[i]=caracter;
            archivo.get(caracter);
         }
         int dd;
      	dd=atoi(dia);//transforma una linea de caracteres en entero
         int Cdia=horaac->tm_mday;
         if(dd==Cdia)
         {
      		if(caracter=='-')
      		{
            	archivo.get(caracter);
         		for(int j=0;j<1;j++)
         		{
         			mes[j]=caracter;
            		archivo.get(caracter);
         		}
         		int mm;
               int Cmes=horaac->tm_mon+1;
      			mm=atoi(mes);//transforma una linea de caracteres en entero
         		if(mm==Cmes)
         		{
      				if(caracter=='-')
      				{
      					archivo.get(caracter);
         				for(int m=0;m<=3;m++)
         				{
         					anio[m]=caracter;
            				archivo.get(caracter);
         				}
         				float aa;
                     float Canio;
                     Canio=horaac->tm_year+1900;
      					aa=atoi(anio);//transforma una linea de caracteres en entero
         				if(aa==Canio) //asignar en otra variable entera
         				{
                     	int a=0;
                        char cadena[50];
                     	while(a<5)
                        {

                           if(a=0)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<" "<<cadena<<endl;
                           }
                           if(a=1)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<"NOMBRE DEL EVENTO:	"<<cadena<<endl;
                           }
                           if(a=2)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<"DESCRIPCION DEL EVENTO:	"<<cadena<<endl;
                           }
                           if(a=3)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<"HORA DE INICIO:		"<<cadena<<":00"<<endl;
                           }
                           if(a=4)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<"HORA DE FINALIZACION:	"<<cadena<<":00"<<endl;
                           }

                           a++;
                        }

         				}
         			}
         		}
				}
			}
   	}
      archivo.get(caracter);

	}
   	getch();
		archivo.close();
}
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
Ver_mis_eventos_para_toda_la_semana()
{
   cout<<"lista de eventos "<<endl;
   	clrscr ();
	time_t t=time(0); //pone el reloj a cero
	tm *horaac =localtime(&t);   //crea un puntero para la hora local
	cout<<"Fecha actual: "<<endl;
   cout<<"HORA: "<<horaac->tm_hour<<"H"<<horaac->tm_min<<endl<<"FECHA: "<<horaac->tm_mday<<"/"<<(horaac->tm_mon+1)<<"/"<<(horaac->tm_year+1900)<<endl; //punteros a diferentes variables hora fecha.... etc
   cout<<endl;
   cout<<endl;
   char dia[1];
   char mes[1];
	char anio[3];
	char caracter;
   ifstream archivo("D:miarchivo.txt", ios::in);

	while(!archivo.eof()) //lee linea por linea
	{
   for(int t=0;t<=7;t++)
	{
		archivo.get(caracter);//lee caracter por caracter
      if(caracter=='*')
      {
      	archivo.get(caracter);
         for(int i=0;i<=1;i++)
         {
         	dia[i]=caracter;
            archivo.get(caracter);
         }
         int dd;
      	dd=atoi(dia);//transforma una linea de caracteres en entero
         int Cdia=horaac->tm_mday+t;
         if(dd==Cdia)
         {
      		if(caracter=='-')
      		{
            	archivo.get(caracter);
         		for(int j=0;j<1;j++)
         		{
         			mes[j]=caracter;
            		archivo.get(caracter);
         		}
         		int mm;
               int Cmes=horaac->tm_mon+1;
      			mm=atoi(mes);//transforma una linea de caracteres en entero
         		if(mm==Cmes)
         		{
      				if(caracter=='-')
      				{
      					archivo.get(caracter);
         				for(int m=0;m<=3;m++)
         				{
         					anio[m]=caracter;
            				archivo.get(caracter);
         				}
         				float aa;
                     float Canio;
                     Canio=horaac->tm_year+1900;
      					aa=atoi(anio);//transforma una linea de caracteres en entero
         				if(aa==Canio) //asignar en otra variable entera
         				{
                     	int a=0;
                        char cadena[50];
                     	while(a<5)
                        {

                           if(a=0)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<" "<<cadena<<endl;
                           }
                           if(a=1)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<"NOMBRE DEL EVENTO:	"<<cadena<<endl;
                           }
                           if(a=2)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<"DESCRIPCION DEL EVENTO:	"<<cadena<<endl;
                           }
                           if(a=3)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<"HORA DE INICIO:		"<<cadena<<":00"<<endl;
                           }
                           if(a=4)
                           {
                           	archivo.getline(cadena,50);
                           	cout<<"HORA DE FINALIZACION:	"<<cadena<<":00"<<endl<<endl;
                           }

                           a++;
                        }

         				}
         			}
         		}
				}
			}
   	}
      archivo.get(caracter);
	}
}
   getch();
   archivo.close();
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




