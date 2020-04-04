%{
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <ctype.h>
#include <getopt.h>

#include "defs.h"
#include "common.h"

#include "y.tab.h"

#define YELLOW "\x1b[93m"
#define RED "\x1b[91m"
#define GREEN "\x1b[92m"
#define BLUE "\x1b[96m"
#define RESET "\x1b[0m"

int bflag = 0;
char* ovalue = NULL;
char* tvalue = NULL;
char* rvalue = NULL;
int sflag = 0;
int vflag = 0;
int hflag = 0;
int opt;

void yyerror(char *);
int yyparse(void);
int fileno(FILE * stream);
char* infile = "test.c";

%}

%option yylineno

LETTRE [A-Za-z]
CHIFFRE [0-9]
IDF {LETTRE}({LETTRE}|{CHIFFRE}|_)*
CHIFFRE_NON_NUL [1-9]
ENTIER_DEC 0|{CHIFFRE_NON_NUL}{CHIFFRE}*
LETTRE_HEXA [a-fA-F]
ENTIER_HEXA 0x({CHIFFRE}|{LETTRE_HEXA})+
SIGNE -?
ENTIER {SIGNE}({ENTIER_DEC}|{ENTIER_HEXA})
CARACTERE [\x20-\x21\x23-\x5B\x5D-\x7E]
CHAINE \"({CARACTERE}|\\\"|\\\\|\\n)*\"
COMMENTAIRE \/\/.*\n

%%

"void"          return TOK_VOID;
"int"			return TOK_INT;
"bool"			return TOK_BOOL;
"true"			return TOK_TRUE;
"false"			return TOK_FALSE;
"if"			return TOK_IF;
"else"			return TOK_ELSE;
"while"			return TOK_WHILE;
"for"			return TOK_FOR;
"do"			return TOK_DO;
"print"			return TOK_PRINT;

"+"				return TOK_PLUS;
"-"				return TOK_MINUS;
"*"				return TOK_MUL;
"/"				return TOK_DIV;
"%"				return TOK_MOD;
">"				return TOK_GT;
"<"				return TOK_LT;
"!"				return TOK_NOT;
"~"				return TOK_BNOT;
"&"				return TOK_BAND;
"|"				return TOK_BOR;
"^"				return TOK_BXOR;
"="				return TOK_AFFECT;
";"				return TOK_SEMICOL;
","				return TOK_COMMA;
"("				return TOK_LPAR;
")"				return TOK_RPAR;
"{"				return TOK_LACC;
"}"				return TOK_RACC;
">>"			return TOK_SRA;
">>>"			return TOK_SRL;
"<<"			return TOK_SLL;
">="			return TOK_GE;
"<="			return TOK_LE;
"=="			return TOK_EQ;
"!="			return TOK_NE;
"&&"			return TOK_AND;
"||"			return TOK_OR;

{IDF} 			{
                	yylval.strval = strdup(yytext);
                	return TOK_IDENT;
				}

{CHAINE} 		{
					yylval.strval = strdup(yytext);
					return TOK_STRING;
				}

{ENTIER} 		{
					yylval.intval = atoi(yytext);
					return TOK_INTVAL;
				}

{COMMENTAIRE}

[ \t\n]+

. 				{
                	fprintf(stderr, "Lexical Error line %d: Lexical error\n", yylineno);
                	exit(1);
				}
%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char** argv)
{
    while((opt = getopt (argc, argv, "bo:t:r:svh")) != -1)
    {
        switch(opt)
        {
        case 'b':
            bflag = 1;
            break;
        case 'o':
            ovalue = optarg;
            break;
        case 't':
            tvalue = optarg;
            break;
        case 'r':
            rvalue = optarg;
            break;
        case 's':
            sflag = 1;
            break;
        case 'v':
            vflag = 1;
            break;
        case 'h':
            hflag = 1;
            break;
        case '?':
            if(optopt == 'o' || optopt == 't' || optopt == 'r' )
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            else if(isprint (optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            exit(1);
        default:
            exit(1);
        }
    }

    //printf("bflag = %d\n, ovalue = %s\n, tvalue = %s\n, rvalue = %s\n, sflag = %d\n, vflag = %d\n, hflag = %d\n", bflag, ovalue, tvalue, rvalue, sflag, vflag, hflag);

    if(bflag == 1)
    {
        printf(YELLOW);
        printf("              _       _          \n");
        printf("        /\\/\\ (_)_ __ (_) ___ ___ \n");
        printf("       /    \\| | '_ \\| |/ __/ __|\n");
        printf("      / /\\/\\ \\ | | | | | (_| (__ \n");
        printf("      \\/    \\/_|_| |_|_|\\___\\___|\n");
        printf("\n");
        printf("+----------------------------------------+\n");
        printf("|                                        |\n");
        printf("|            %sCompilateur minicc%s          |\n", RED, YELLOW);
        printf("|                   par                  |\n");
        printf("|   %sBenjamin Bihanic%s et %sVictor Dubois%s    |\n", GREEN, YELLOW, GREEN, YELLOW);
        printf("|                  %sEI-SE4%s                |\n", BLUE, YELLOW);
        printf("|                                        |\n");
        printf("+----------------------------------------+\n");
        printf(RESET);
        return 0;
    }

    if(hflag == 1 || argc == 1)
    {
        printf(YELLOW);
        printf("              _       _          \n");
        printf("        /\\/\\ (_)_ __ (_) ___ ___ \n");
        printf("       /    \\| | '_ \\| |/ __/ __|\n");
        printf("      / /\\/\\ \\ | | | | | (_| (__ \n");
        printf("      \\/    \\/_|_| |_|_|\\___\\___|\n");
        printf("\n");
        printf("+-------------------------------------------------------+\n");
        printf("|                                                       |\n");
        printf("| %sListe des options :%s                                   |\n", RED, YELLOW);
        printf("|                                                       |\n");
        printf("| %s-b :%s                                                  |\n", RED, YELLOW);
        printf("|   Affiche une bannière indiquant le nom du            |\n");
        printf("|   compilateur et des membres du binôme.               |\n");
        printf("| %s-o <filename> :%s                                       |\n", RED, YELLOW);
        printf("|   Définit le nom du fichier assembleur produit        |\n");
        printf("|   (défaut : out.s).                                   |\n");
        printf("| %s-t <int> :%s                                            |\n", RED, YELLOW);
        printf("|   Définit le niveau de trace à utiliser entre 0 et 5  |\n");
        printf("|   (0 = pas de trace, 5 = toutes les traces,           |\n");
        printf("|   défaut = 0).                                        |\n");
        printf("| %s-r <int> :%s                                            |\n", RED, YELLOW);
        printf("|   Définit le nombre maximum de registres à utiliser,  |\n");
        printf("|   entre 4 et 8 (défaut : 8).                          |\n");
        printf("| %s-s :%s                                                  |\n", RED, YELLOW);
        printf("|   Arrête la compilation après l'analyse syntaxique    |\n");
        printf("|   (0 = non, 1 = oui, défaut : non).                   |\n");
        printf("| %s-v :%s                                                  |\n", RED, YELLOW);
        printf("|   Arrête la compilation après la passe de             |\n");
        printf("|   vérification (0 = non, 1 = oui, défaut : non).      |\n");
        printf("| %s-h :%s                                                  |\n", RED, YELLOW);
        printf("|    Affiche la liste des options (fonction d'usage).   |\n");
        printf("|                                                       |\n");
        printf("+-------------------------------------------------------+\n");
        printf(RESET);
        return 0;
    }

    if(sflag && vflag)
    {
        fprintf(stderr, "Les options '-s' et '-v' sont incompatibles.\n");
        exit(1);
    }

    yyin = fopen(argv[optind], "r");
    yyparse();
    fclose(yyin);
    yylex_destroy();
    return 0;
}
