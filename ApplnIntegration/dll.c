#include "dll.h"
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* Public Function Implementation to create and return
 * new empty doubly linked list*/

dll_t *
get_new_dll(){

    dll_t *dll = calloc(1, sizeof(dll_t));
    dll->head = NULL;
    return dll;
}

/* Public Function Implementation to add a new application
 *  * data to DLL */
int
add_data_to_dll (dll_t *dll, void *app_data){

    if(!dll || !app_data) return -1;
    
    dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
    dll_new_node->prev = NULL;
    dll_new_node->next = NULL;
    dll_new_node->data = app_data;

    /*Now add this to the front of DLL*/
    if(!dll->head){
        dll->head = dll_new_node;
        return 0;
    }
    dll_node_t *first_node = dll->head;
    dll_new_node->next = first_node;
    first_node->prev = dll_new_node;
    dll->head = dll_new_node;
    return 0;
}

/*More functions*/
