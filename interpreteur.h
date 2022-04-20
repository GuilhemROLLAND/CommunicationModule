#include "struct_allocation.h"
#ifndef _INTERPRETEUR_H
#define _INTERPRETEUR_H

    // Fonctions
    /**
     * @brief process the TC and activate the corresponding process, write ack to buffer
     * 
     * @param main_s main structure 
     * @param bufferMsg buffer to store ack
     * @return int -1 if memory allocation failed
     */
    int interpreteur(mainStruct *main_s, char *bufferMsg);


#endif