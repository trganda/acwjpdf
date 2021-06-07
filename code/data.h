#ifndef extern_
<<<<<<< HEAD
#define extern_ extern
=======
 #define extern_ extern
>>>>>>> dbb1bd9c1f55a964abea3638f439ef50ef2d730e
#endif

// Global variables
// Copyright (c) 2019 Warren Toomey, GPL3

<<<<<<< HEAD
extern_ int Line;			// Current line number
extern_ int Putback;			// Character put back by scanner
extern_ FILE *Infile;			// Input and output files
extern_ FILE *Outfile;
extern_ struct token Token;		// Last token scanned
extern_ char Text[TEXTLEN + 1];		// Last identifier scanned
=======
extern_ int     	Line;
extern_ int		Putback;
extern_ FILE		*Infile;
extern_ FILE		*Outfile;
extern_ struct token	Token;
>>>>>>> dbb1bd9c1f55a964abea3638f439ef50ef2d730e
