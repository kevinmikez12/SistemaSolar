#include "Face.h"
#include "Vertice.h"
#ifndef CARGARTEXT__H //definimos nuestra biblioteca 
#define CARGARTEXT_H

using namespace std;//hacemos mencion del espacio que estemos creando

struct Load{//creamos estructura de tipo load para poder utilizar la el metodo loadObject
	public:
	    void loadObject(const char* filename);//hacemos referencia en el metodo contenido en la estructura
		std::vector<Vertice*> v;	//lista donde se guardaran todos los vertices del archivo
        std::vector<Face*> f; 
		vector <Vertice*> get_faces_verts();
};

#endif //cerramos nuestra biblioteca