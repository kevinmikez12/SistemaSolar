#include "Vertice.h"
#include <armadillo>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

		Vertice::Vertice(float a,float b,float c) {
		x=a;
		y=b;
		z=c;
		}
		
		Vertice::Vertice() {
		}
		
	 void Vertice::setValue(arma::fcolvec trans){
			matriz = trans;
			x = trans.at(0);
			y = trans.at(1);
			z = trans.at(2);
	}
	
	arma::frowvec Vertice::getValue(){
	    arma::frowvec ren;
		ren[0] = x;
		ren[1] = y;
		ren[2] = z;
		ren[3] = 1;
		return (ren);
	}
	
	arma::fcolvec Vertice::h(){
			arma::fcolvec vh = {	  {x},
											  {y},
											  {z},
											  {1}};
											  return (vh);
	}