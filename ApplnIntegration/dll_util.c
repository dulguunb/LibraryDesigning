#include "dll.h"
#include <stdlib.h>
#include <memory.h>

/*More functions*/

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

  /*return 0 on success and -1 on failure*/
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

/*return 0 if empty, -1 if not empty*/
int
is_dll_empty (dll_t *dll){
    if( dll->head != NULL ) return 0;
    return -1;
}

/* delete all nodes from a dll, but do not free appln data*/

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

