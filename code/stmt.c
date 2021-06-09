#include "defs.h"
#include "data.h"
#include "decl.h"

// Parsing of statements
// Copyright (c) 2019 Warren Toomey, GPL3

// statements: statement
//      | statement statements
//      ;
//
// statement: 'print' expression ';'
//      |     'int'   identifier ';'
//      |     identifier '=' expression ';'
//      ;
//
// identifier: T_IDENT
//      ;

// Parse print statement
void print_statement(void) {
  struct ASTnode *tree;
  int reg;

  while (1) {
    // Match a 'print' as the first token
    match(T_PRINT, "print");

    // Parse the following expression and
    // generate the assembly code
    tree = binexpr(0);
    reg = genAST(tree, -1);
    genprintint(reg);
    genfreeregs();

    // Match the following semicolon
    // and stop if we are at EOF
    semi();
    if (Token.token == T_EOF)
      return;
  }
}

// Parse variable declaration statement
void var_delcaration(void) {
  // Ensure we have an 'int' token followed by an identifier
  // and a semicolon. Text now has the identifier's name.
  // Add it as a known identifier
  match(T_INT, "int");
  ident();
  addglob(Text);
  genglobsym(Text);
  semi();
}

// Parse assignment statement
void assignment_statement(void) {
  struct ASTnode *left, *right, *tree;
  int id;

  ident();
  if ((id = findglob(Text)) == -1) {
    fatals("Undeclared variable", Text);
  }
  right = mkastleaf(A_LVIDENT, id);

  match(T_EQUALS, "=");

  left = binexpr(0);
  tree = mkastnode(A_ASSIGN, left, right, 0);

  genAST(tree, -1);
  genfreeregs();

  semi();
}

// Parse one or more statements
void statements(void) {
  while(1) {
    switch (Token.token) {
    case T_PRINT:
      print_statement();
      break;
    case T_INT:
      var_delcaration();
      break;
    case T_IDENT:
      assignment_statement();
      break;
    case T_EOF:
      return;
    default:
      fatald("Syntax error, token", Token.token);
    }
  }
}
