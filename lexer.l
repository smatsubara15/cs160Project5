%option yylineno
%pointer

%{
    #include <stdlib.h>
    #include <errno.h>
    #include <limits.h>
    #include "ast.hpp"
    #include "parser.hpp"
    void yyerror(const char *);
%}

/* WRITEME: Copy any definitions and start conditions from Project 3 here */
digit [0-9]
lowercase [a-z]
uppercase [A-Z]

%x comment
%%

  /* WRITEME: Copy your Flex rules from Project 3 here */
"("                 {return T_OPENPAREN;}
")"                 {return T_CLOSEPAREN;}
","                 {return T_COMMA;}
"{"                 {return T_OPENBRACKET;}
"}"                 {return T_CLOSEBRACKET;}
";"                 {return T_SEMICOLON;}
"="                 {return T_ASSIGNMENT;}
"+"                 {return T_PLUS;}
"-"                 {return T_MINUS;}
"*"                 {return T_MULTIPLY;}
"/"                 {return T_DIVIDE;}
">"                 {return T_GREATER;}
">="                {return T_GREQ;}
"."                 {return T_PERIOD;}
"->"                {return T_LARROW;}

equals            {return T_EQUALS;}
and               {return T_AND;}
or                {return T_OR;}
print             {return T_PRINT;}
return            {return T_RETURN;}
if                {return T_IF;}
else              {return T_ELSE;}
while             {return T_WHILE;}
new               {return T_NEW;}

integer           {return T_INT;}
boolean           {return T_BOOL;}
none              {return T_NONE;}

not               {return T_NOT;}
true              {return T_TRUE;}
false             {return T_FALSE;}
extends           {return T_EXTENDS;}
do                {return T_DO;}

[0]                 {yylval.base_int = std::atoi(yytext) ; return T_INTLITERAL;}
[1-9]{digit}*     {yylval.base_int = std::atoi(yytext) ; return T_INTLITERAL;} 

({uppercase}|{lowercase})({uppercase}|{lowercase}|{digit})*     {yylval.base_char_ptr = strdup(yytext); return T_NAME_IDENTIFIER;}

\n                {}
"/*"              {BEGIN(comment);}
<comment>"*/"     { BEGIN(INITIAL); }
<comment>\n       {}
<comment>.        {}
<comment><<EOF>>  { yyerror("Dangling comment"); }
[ \t\n]+          ;
.                 { yyerror("invalid character"); }

%%

int yywrap(void) {
  return 1;
}