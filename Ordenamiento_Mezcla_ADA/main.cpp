#include <iostream>
using namespace std;

/********************* METODO DE ORDENACION POR MEZCLA *******************/

void mezclar(int A[], int izq, int der, int centro)
{
  int i=izq;
  int j=centro+1;
  int* aux= new int[der-izq+1];
  int k=0;


  while ((i<=centro) &&(j<=der))
  {
      if(A[i]<A[j])
      {
          aux[k]=A[i];
          i++;
      }
      else
      {
          aux[k]=A[j];
          j++;
      }
      k++;
  }

  /*Para Evitar los centinelas; cuando ya no haya que comparar se copiará el resto del vector*/
  while (i<=centro)
  {
      aux[k]=A[i];
      i++;
      k++;
  }

  while (j<=der)
  {
      aux[k]=A[j];
      j++;
      k++;
  }

  /*Traspaso todo el Vector aux  al array A */
  for(i=0;i<k;i++)
  {

      A[i+izq]=aux[i];
  }

}


void ordenarMezcla(int A[], int p, int q)
{
  int centro=0;

  if (p<q)
  {
      centro=(p+q)/2;
      ordenarMezcla(A,p,centro);
      ordenarMezcla(A,centro+1,q);
      mezclar(A,p,q,centro);///Mandas Posciciones :)

  }
}



int main()
{
    int lista[5];
    lista[0]=89;
    lista[1]=4;
    lista[2]=2000;
    lista[3]=45;
    lista[4]=1;
    lista[4]=170000;

    ordenarMezcla( lista, 0,6);
    for(int i=0;i<5;i++)
    {
        cout<<lista[i]<<endl;
    }
    return 0;
}
