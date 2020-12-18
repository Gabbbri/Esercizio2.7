#include <iostream>
#include "media.hpp"

using namespace std;

int media(int array[], int dim) {

    long somma=0;
    int media;

    for (int i=0; i<dim; ++i) {
        
        somma+= array[i];
    }

    media = somma/dim;

    return media;


}