//Carlos requiere tener un control de sus actividades diarias. Para ello está buscando una aplicación informática que
//le permita realizar ese control. Carlos necesita que la aplicación le permita ingresar nuevos eventos en su
//calendario y que luego le permita visualizar cronológicamente los eventos planificados para el día de hoy y para
//toda la semana.

#include <fstream>//utilizacion de la funcion ofstream
#include <iostream> //utilizacion de la funcion getch
#include <conio>    //utilizacion de la funcion cout
#include <stdio>

//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
int Principal()
{
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
	ofstream archivo("C:/Users/Sistemas/Desktop/sandro/miarchivo.txt", ios::app);
	clrscr ();
	char nuevo_evento[100];
   char descripcion_del_evento[100];
   int dia;
   int mes;
   int anio;

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
         archivo<< nuevo_evento;
         archivo<< descripcion_del_evento;
         archivo<< dia;
         archivo<< mes;
         archivo<< anio;
         clrscr ();
         //Principal();
}
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
Ver_mis_eventos_para_hoy()
{
	cout<<"Fecha actual: "<<endl;
   cout<<"lista de eventos "<<endl;
}
Ver_mis_eventos_para_toda_la_semana()
{
	cout<<"Semana actual: "<<endl;
   cout<<"lista de eventos "<<endl;
   getch();
   Principal();
}
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------//
main()
{
	ifstream archivo("C:/Users/Sistemas/Desktop/sandro/miarchivo.txt", ios::in);
   if (archivo)
   {
   	ofstream archivo("C:/Users/Sistemas/Desktop/sandro/miarchivo.txt", ios::app);
   }
   else
   {
   	ofstream archivo("C:/Users/Sistemas/Desktop/sandro/miarchivo.txt");
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







