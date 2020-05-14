#include <vector>//biblioteca para el  uso de listas en el programa
#include <GL/glu.h>//esta biblioteca nos permite utilizar las funciones para crear los objetos (triangulos,cuadrados,colores,etc)
#include "CargaText.h"//biblioteca para la carga de archivo y creacion de objetos
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include "Face.h"
#include "Vertice.h"

using namespace std;

void Load::loadObject(const char* filename)
{
       
	    std::vector<std::string*> coord;   //lista donde se guardara el contenido de cada linea
        Load:: v;	//lista donde se guardaran todos los vertices del archivo
        Load:: f; //lista donde se guardaran todos las caras
        std::ifstream in(filename);     //cariable que utilizaremos para leer el archivo .obj
        if(!in.is_open())       //si no es abierto regresa un menos 1
        {
                std::cout << "Error al Abrir." << std::endl;
        }
        char buf[256]; //creamos el buffer que guardara el contenido de cada linea en el archivo .obj
        /**ciclo de lectura del archivo**/
        while(!in.eof())
        {
                in.getline(buf,256);//se guardan las lineas con su respectivo valor en la lista
                coord.push_back(new std::string(buf));//coord es el que guarda el contenido de buf antes de actualizar.
        }
        /**ciclo donde se hace la indentificacion de tipo de valores en el archivo**/
        for(int i=0;i<coord.size();i++)
        {
                if(coord[i]->c_str()[0]=='#')   //es un comentario(si su primer caracter es #)
                        continue;       //si es asi continuamos con la lectura ya que no nos interesa los comentarios en estos momentos
                else if(coord[i]->c_str()[0]=='v' && coord[i]->c_str()[1]==' ') //condicional si es un vector 
                {
                        float tmpx,tmpy,tmpz;
                        sscanf(coord[i]->c_str(),"v %f %f %f",&tmpx,&tmpy,&tmpz);       //se leen los tres flotantes de de coord y se almacenan en tmpx,tmpy,tmpz
                        v.push_back(new Vertice(tmpx,tmpy,tmpz));       //al obtener los valores de los flotantes los guardamos en la lista de vectores
                }
                else if(coord[i]->c_str()[0]=='f')     //si es una cara
                {
                        int a,b,c,d,e;
                        if(count(coord[i]->begin(),coord[i]->end(),' ')==3)     //condicion si es una cara tipo triangulo (ya que se pueden identificar por sus 3 espacios)
                        {
                  sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
				  //sscanf(coord[i]->c_str(),"f %d %d %d ",&a,&b,&c);
                                f.push_back(new Face(b,a,c,d));     //se leen de coord y se almacenan en las variables temporales, y despues se guardan en la lista de tipo cara
                        }else{
                                sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
                                f.push_back(new Face(b,a,c,d,e));   //se hace el mismo proceso que triangulo solo que se llama a un constructor distinto y se acomodan los datos de distinta manera.
                        }
                }
        }
		
		for(int i =0; i<f.size();i++){
			printf("        Face %d :    \n",i+1);
			f[i]->imprime();
		}
}

vector <Vertice*> Load::get_faces_verts(){
	return v;
}