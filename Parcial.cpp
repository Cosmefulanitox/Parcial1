#include "Parcial.h"



void Parcial::Punto1()
{
    int x,y;
    bool band2021[10]={false};
    bool band2022[10]={false};
    int tipomulta[10]= {};
    Multa *m;
    MultaArchivo marchivo;
    m = new Multa [marchivo.getCantidadRegistros()];

    marchivo.leer(m,marchivo.getCantidadRegistros());

    std::cout<<"Los registros de infraccion que tuvieron por lo menos 1infraccion en 2022 y no en 2021 son "<<std::endl;

      for (x = 0; x < marchivo.getCantidadRegistros(); x++)
    {
        if (m[x].getFechaMulta().getAnio() == 2022 && m[x].getEliminado() == 0)
        {
            band2022[m[x].getTipoInfraccion() - 1] = true;
        }
        else if (m[x].getFechaMulta().getAnio() == 2021 && m[x].getEliminado() == 0)
        {
            band2021[m[x].getTipoInfraccion() - 1] = true;
        }
    }




for (y = 0; y < 10; y++)
    {
        if (band2022[y] && !band2021[y])
        {
            std::cout << "Tipo " << y + 1 << std::endl;
        }
        else
        {
            std::cout << "Tipo " << y + 1 << " Sin coincidencias" << std::endl;
        }
    }

    delete[] m;




}
void Parcial::Punto2()
{
    int x;
    Multa *m;
    float mayorImporte;
    int idAgente,idmulta;
    int cant;
    AgenteArchivo agen;
    Agente a;
    MultaArchivo marchivo;
    m = new Multa [marchivo.getCantidadRegistros()];

    marchivo.leer(m,marchivo.getCantidadRegistros());

    mayorImporte= m[0].getMonto();
    idAgente= m[0].getIDAgente();
    idmulta = m[0].getIDMulta();
    for (x=0; x<marchivo.getCantidadRegistros(); x++)
    {
        if(m[x].getMonto()>mayorImporte&&m[x].getPagada()==true)
        {
            mayorImporte = m[x].getMonto();
            idAgente = m[x].getIDAgente();
            idmulta =m[x].getIDMulta();
        }
    }
    cant=agen.buscar(idAgente);
    a=agen.leer(cant);

    std::cout<<"La multa con mayor importe registrada es de $"<<mayorImporte<<std::endl;
    std::cout<<"El agente que confecciono dicha multa fue "<<a.getNombres()<<" "<<a.getApellidos()<<std::endl;


    delete [] m;

}
void Parcial::Punto3()
{
    Multa *m;
    int *comp;
    int cont=0,x,y;
    bool agent;
    MultaArchivo marchivo;
    int cantregistros =marchivo.getCantidadRegistros();
    m = new Multa [cantregistros];
    comp = new int [cantregistros]{};
    comp[cantregistros];

    marchivo.leer(m,cantregistros);

     /*for (x=0; x<marchivo.getCantidadRegistros(); x++)
     {
         if( !m[x].getEliminado() && m[x].getMonto()>25000 )
         {
              std::cout<<m[x].getIDAgente()<<std::endl;
         std::cout<<"Monto: $"<<m[x].getMonto()<<std::endl;
            std::cout<<m[x].getEliminado()<<std::endl;
            std::cout<<"ID MULTA : "<<m[x].getIDMulta()<<std::endl;

         }
     }*///codigo para ver registros no tener en cuenta

      std::cout<<std::endl;
  std::cout<<std::endl;

    for (x=0; x<cantregistros; x++)//el for ciclea por todos los registros de multas
    {
        agent=true;//se establece el parametro true como base para retomar el parametro despues de la primer vuelta

        for(y=0; y<=cantregistros; y++)//este for anidado comprueba los registros de IDAgente que se guardan despues de la primer vuelta, en la primer vuelta no ingreso por que esta inicializado
        {                              //en 0 y no hay registros de ID agente con 0
            if(comp[y]==m[x].getIDAgente())
            {
                agent=false; //En caso de que se detecte que el agente fue ingresado en algun momento se establece en false para que no pase la declaracion del if y rompe el ciclo
                break;

            }
        }

        if (m[x].getMonto()>25000 && !m[x].getEliminado() && agent)
        {
             std::cout<<m[x].getIDAgente()<<std::endl;//parametro agregado para ver que registros se guardaron
            cont++;
             comp[x]=m[x].getIDAgente();
        }
       // array dinamico en el que se guardan los registros del agente que pasor por dicho lectura para compararlo en lasiguiente vuelta del for
    }


    std::cout<<"La cantidad de agentes distintos que realizaron multas de mas de $25000 es:"<<cont<<std::endl;


    delete [] m;
    delete [] comp;

}
void Punto4()
{
    Multa *m;
    int *comp;
    int cont=0,x,y;
    float mayorImporte;
    int idAgente;
    bool agent;

    MultaArchivo marchivo;
    m = new Multa [marchivo.getCantidadRegistros()];
    comp = new int [marchivo.getCantidadRegistros()]();

    marchivo.leer(m,marchivo.getCantidadRegistros());


}


