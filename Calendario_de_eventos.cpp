//Carlos requiere tener un control de sus actividades diarias. Para ello est� buscando una aplicaci�n inform�tica que
//le permita realizar ese control. Carlos necesita que la aplicaci�n le permita ingresar nuevos eventos en su
//calendario y que luego le permita visualizar cronol�gicamente los eventos planificados para el d�a de hoy y para
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
   cout<<"2.-Descripci�n del evento"<<endl;
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







