/*Header file for Doubly Linked List*/

typedef struct dll_node_{
    void *data;
    struct dll_node_ *prev;
    struct dll_node_ *next;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
} dll_t;


/* Public Function declaration to create and return
 * a new empty doubly linked list*/
dll_t *
get_new_dll();

/*  Public Function declaration to add the appication
 *  data to DLL*/
int
add_data_to_dll(dll_t *dll, void *appn_data);
/* removes one node */
int remove_one_node(dll_node_t **,dll_node_t*);
/*More functions*/
int  /*return 0 on success and -1 on failure*/
remove_data_from_dll_by_data_ptr (dll_t *dll, void *data);

/*return 0 if empty, -1 if not empty*/
int 
is_dll_empty (dll_t *dll); 

/* delete all nodes from a dll, but do not free appln data*/
void
drain_dll (dll_t *dll);
