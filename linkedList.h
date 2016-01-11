typedef struct ele{
	void *value;
	// struct ele *previous;
	struct ele *next;
} Element ;

typedef struct {
	Element *first;
	Element *last;
	int length;
} LinkedList;

typedef void(*ElementProcessor)(void *);

LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList list, ElementProcessor e);