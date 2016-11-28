#ifndef BYTECODE_H_INCLUDED
#define BYTECODE_H_INCLUDED
// bytecode.h

int init_byte_code(void); // init bytecode table

typedef struct _PRM
{
    // extend with other types and union
    int i[8];
    double d[8];

} PRM;

/*
typedef struct _PRM
{
        unsigned int p1;
        unsigned int p2;
        unsigned int p3;
        unsigned int p4; // ref, obj, float, etc. union
} PRM;
*/


typedef int (*virtual_func)(PRM*);
typedef int (*compile_func)(PRM*);
//typedef int (*funptr)(int,int);

typedef struct _BYTECODE_LUT
{
    unsigned short int n;
    virtual_func vf;
    char *mnem;
} BYTECODE_LUT;



// virtual processor model
typedef struct _VMPROC
{
    unsigned int pc;
    unsigned int sp;
    int i[8];           //
    double  d[8];


} VMPROC;





#endif
