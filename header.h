#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[100];
typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;

typedef struct DataChild{
	string a;
	int b;
}DataChild;

typedef struct DataParent{
	string a;
	int b;
}DataParent;

typedef struct Child{
	DataChild datachild;
	AddressChild next;
}NodeChild;

typedef struct Parent{
	DataParent dataparent;
	AddressParent next;
	
	AddressChild firstChild;
}NodeParent;

typedef struct {
	AddressParent firstParent;
}Multilist;