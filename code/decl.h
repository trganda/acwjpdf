
// Function prototypes for all compiler files
// Copyright (c) 2019 Warren Toomey, GPL3
<<<<<<< HEAD
// scan.c
int scan(struct token *t);

// tree.c
=======
int scan(struct token *t);

>>>>>>> dbb1bd9c1f55a964abea3638f439ef50ef2d730e
struct ASTnode *mkastnode(int op, struct ASTnode *left,
			  struct ASTnode *right, int intvalue);
struct ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);
<<<<<<< HEAD

// gen.c
int genAST(struct ASTnode *n);
void genpreamble();
void genpostamble();
void genfreeregs();
void genprintint(int reg);

// cg.c
=======
struct ASTnode *binexpr(int ptp);

int interpretAST(struct ASTnode *n);
void generatecode(struct ASTnode *n);

>>>>>>> dbb1bd9c1f55a964abea3638f439ef50ef2d730e
void freeall_registers(void);
void cgpreamble();
void cgpostamble();
int cgload(int value);
int cgadd(int r1, int r2);
int cgsub(int r1, int r2);
int cgmul(int r1, int r2);
int cgdiv(int r1, int r2);
void cgprintint(int r);
<<<<<<< HEAD

// expr.c
struct ASTnode *binexpr(int ptp);

// stmt.c
void statements(void);

// misc.c
void match(int t, char *what);
void semi(void);
=======
>>>>>>> dbb1bd9c1f55a964abea3638f439ef50ef2d730e
