#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Structure and enum definitions
// Copyright (c) 2019 Warren Toomey, GPL3

#define TEXTLEN		512	// Length of symbols in input
#define NSYMBOLS    1024    // Number of symbol table entries

// Token types
enum {
  T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT, T_SEMI, T_PRINT,
  T_EQUALS, T_INT, T_IDENT
};

// Token structure
struct token {
  int token;			// Token type, from the enum list above
  int intvalue;			// For T_INTLIT, the integer value
};

// AST node types
enum {
  A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT, A_IDENT, A_ASSIGN,
  A_LVIDENT
};

// Abstract Syntax Tree structure
struct ASTnode {
  int op;			// "Operation" to be performed on this tree
  struct ASTnode *left;		// Left and right child trees
  struct ASTnode *right;
  union {
    int intvalue;			// For A_INTLIT, the integer value
    int id;           // For A_IDENT,  the symbol slot number of identifier
  } v;
};

// Symbol table structure
struct symtable {
  char *name;     // Name of a symbol
};