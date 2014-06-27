//Carlos requiere tener un control de sus actividades diarias. Para ello está buscando una aplicación informática que
//le permita realizar ese control. Carlos necesita que la aplicación le permita ingresar nuevos eventos en su
//calendario y que luego le permita visualizar cronológicamente los eventos planificados para el día de hoy y para
//toda la semana.

#include <fstream>//utilizacion de la funcion ofstream
#include <iostream> //utilizacion de la funcion getch
#include <conio>    //utilizacion de la funcion cout



int Principal()
{
	int a;
	cout<<"1.-Ingresar nuevo evento "<<endl;
   cout<<"2.-Ver mis eventos para hoy "<<endl;
   cout<<"3.-Ver mis eventos para toda la semana "<<endl;
   cin>>a;
   return (a);
}

Ingresar_nuevo_evento()
{
	cout<<"1.-Nombre corto del evento"<<endl;
   cout<<"2.-Descripción del evento"<<endl;
   cout<<"3.-Fecha/Hora de Inicio"<<endl;
   cout<<"4.-Fecha/Hora de Fin"<<endl;

}
main()
{
   if (Principal()==1)
   {
   	Ingresar_nuevo_evento();
   }
   if (Principal()==2)
   {
   	Ver_mis_eventos_para_hoy();

   }

   getch();
}







