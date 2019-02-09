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
int remove_one_node(dll_node_t** head,dll_node_t* to_be_removed)
{
    if(!head || !to_be_removed) 
        return -1;
    
    if(*head == to_be_removed){
        *head = to_be_removed->next;
        return 0;
    }
    if(to_be_removed->next != NULL){
        to_be_removed->next->prev = to_be_removed->prev; 
        if(to_be_removed->prev != NULL){
            to_be_removed->prev->next = to_be_removed->next;
        }
        free(to_be_removed);
        return 0;
    } 
    if(to_be_removed->prev != NULL){
        to_be_removed->prev->next = to_be_removed->next;
        free(to_be_removed);
        return 0;
    }
    return -1;
}
/*More functions*/
int  /*return 0 on success and -1 on failure*/
remove_data_from_dll_by_data_ptr (dll_t *dll, void *data)
{
    if(!dll || !data) return -1;
    dll_node_t *current = dll->head;
    while(current!=NULL){
        if(current->data == data){
            return remove_one_node(&dll->head,current);
        }
        else{
            current = current->next;
        }
    }
    return -1;
}

void
drain_dll (dll_t *dll)
{
    dll_node_t *current = dll->head;
    dll_node_t *next;
    while(current!=NULL){
        next = current->next;
        free(current);
        current = next;
    }
    dll->head = NULL;
}