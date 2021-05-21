%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    #include "ast.hpp"
    
    #define YYDEBUG 1
    #define YYINITDEPTH 10000
    int yylex(void);
    void yyerror(const char *);
    
    extern ASTNode* astRoot;
%}

%error-verbose

/* WRITEME: Copy your token and precedence specifiers from Project 3 here */
%token T_OPENBRACKET T_CLOSEBRACKET T_COMMA
%token T_OPENPAREN T_CLOSEPAREN T_SEMICOLON
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE
%token T_GREATER T_GREQ T_PERIOD T_LARROW
%token T_EQUALS T_AND T_OR 
%token T_PRINT T_RETURN T_ASSIGNMENT
%token T_IF T_ELSE T_WHILE T_NEW 
%token T_INT T_NONE T_TRUE T_FALSE
%token T_NOT T_BOOL T_EXTENDS T_DO
%token T_INTLITERAL T_NAME_IDENTIFIER

%left T_OR
%left T_AND
%left T_GREATER T_GREQ T_EQUALS
%left T_PLUS T_MINUS
%left T_DIVIDE T_MULTIPLY
/* UNSURE */

%right T_NOT 
/* WRITEME: Specify types for all nonterminals and necessary terminals here */
%type <program_ptr> Start
%type <class_ptr> ClassB
%type <class_list_ptr> Class
%type <type_ptr> Type ReturnType
%type <method_ptr> Method
%type <method_list_ptr> Methods
%type <declaration_ptr> Member
%type <parameter_list_ptr> Parameters ParametersB
%type <identifier_list_ptr> DeclarationB
%type <declaration_list_ptr> Declaration Members
%type <methodbody_ptr> Body
%type <returnstatement_ptr> Return
%type <statement_ptr> StatementB
%type <statement_list_ptr> Statement
%type <methodcall_ptr> MethodCall
%type <print_ptr> print
%type <ifelse_ptr> If
%type <while_ptr> While
%type <dowhile_ptr> DoWhile
%type <assignment_ptr> Assignment
%type <expression_ptr> Expression 
%type <expression_list_ptr> Arguments ArgumentsB
%type <base_int> T_INTLITERAL
%type <base_char_ptr> T_NAME_IDENTIFIER


%%

/* WRITEME: This rule is a placeholder. Replace it with your grammar
            rules from Project 3 */

Start : Class {$$ = new ProgramNode($1); astRoot=$$;}
      ;

Class : Class ClassB { $$=$1; $$->push_back($2);}
      | ClassB {$$ = new std::list<ClassNode*>();$$->push_back($1);}
      ;
      
ClassB : T_NAME_IDENTIFIER T_OPENBRACKET Members Methods T_CLOSEBRACKET {$$ = new ClassNode(new IdentifierNode($1),NULL,$3,$4);}
       | T_NAME_IDENTIFIER T_OPENBRACKET Members T_CLOSEBRACKET {$$ = new ClassNode(new IdentifierNode($1),NULL,$3,NULL);}
       | T_NAME_IDENTIFIER T_OPENBRACKET Methods T_CLOSEBRACKET {$$ = new ClassNode(new IdentifierNode($1),NULL,NULL,$3);}
       | T_NAME_IDENTIFIER T_OPENBRACKET T_CLOSEBRACKET {$$ = new ClassNode(new IdentifierNode($1),NULL,NULL,NULL);}
       | T_NAME_IDENTIFIER T_EXTENDS T_NAME_IDENTIFIER  T_OPENBRACKET Members Methods T_CLOSEBRACKET {$$ = new ClassNode(new IdentifierNode($1),new IdentifierNode($3),$5,$6);}
       | T_NAME_IDENTIFIER T_EXTENDS T_NAME_IDENTIFIER  T_OPENBRACKET Members T_CLOSEBRACKET {$$ = new ClassNode(new IdentifierNode($1),new IdentifierNode($3),$5,NULL);}
       | T_NAME_IDENTIFIER T_EXTENDS T_NAME_IDENTIFIER  T_OPENBRACKET Methods T_CLOSEBRACKET {$$ = new ClassNode(new IdentifierNode($1),new IdentifierNode($3),NULL,$5);}
       | T_NAME_IDENTIFIER T_EXTENDS T_NAME_IDENTIFIER  T_OPENBRACKET T_CLOSEBRACKET {$$ = new ClassNode(new IdentifierNode($1),new IdentifierNode($3),NULL,NULL);}
       | %empty {$$ = new ClassNode(NULL,NULL,NULL,NULL);}
       ;  

Type : T_NAME_IDENTIFIER {$$ = new ObjectTypeNode(new IdentifierNode($1));}
     | T_BOOL {$$ = new BooleanTypeNode();}
     | T_INT {$$ = new IntegerTypeNode();}
     ;

Members : Members Member {$$ = $1 ; $$->push_back($2);}
        | Member {$$ = new std::list<DeclarationNode*>() ; $$->push_back($1);}
        ;

Member : Type T_NAME_IDENTIFIER T_SEMICOLON 
         {std::list<IdentifierNode*>* t = new std::list<IdentifierNode*>();t->push_back(new IdentifierNode($2)); $$ = new DeclarationNode($1,t);}
       ;

ReturnType : Type {$$ = $1;}
     | T_NONE {$$ = new NoneNode();}
     ;

Methods : Methods Method  {$$ = $1; $$->push_back($2);}
        | Method {$$ = new std::list<MethodNode*>();$$->push_back($1);}
        ;

Method : T_NAME_IDENTIFIER T_OPENPAREN Parameters T_CLOSEPAREN T_LARROW ReturnType T_OPENBRACKET Body T_CLOSEBRACKET
         {$$ = new MethodNode(new IdentifierNode($1),$3,$6,$8);}
       ;

Parameters : ParametersB {$$ = $1;}
          | %empty {$$ = new std::list<ParameterNode*>();}
          ;

ParametersB : ParametersB T_COMMA Type T_NAME_IDENTIFIER {$$ = $1 ; $$->push_back(new ParameterNode($3,new IdentifierNode($4)));}
           | Type T_NAME_IDENTIFIER {$$ = new std::list<ParameterNode*>() ; $$->push_back(new ParameterNode($1,new IdentifierNode($2)));}
           ;

Body : Declaration Statement Return {$$ = new MethodBodyNode($1,$2,$3);}
     | Declaration Statement {$$ = new MethodBodyNode($1,$2,NULL);}
     | Declaration Return {$$ = new MethodBodyNode($1,NULL,$2);}
     | Statement Return {$$ = new MethodBodyNode(NULL,$1,$2);}
     | Declaration {$$ = new MethodBodyNode($1,NULL,NULL);}
     | Statement {$$ = new MethodBodyNode(NULL,$1,NULL);}
     | Return {$$ = new MethodBodyNode(NULL,NULL,$1);}
     | %empty {$$ = new MethodBodyNode(NULL,NULL,NULL);}
     ;

Declaration : Declaration Type DeclarationB T_SEMICOLON {$$=$1,$$->push_back(new DeclarationNode($2,$3));}
          | Type DeclarationB T_SEMICOLON {$$ = new std::list<DeclarationNode*>();$$->push_back(new DeclarationNode($1,$2));}
          ;

DeclarationB : DeclarationB T_COMMA T_NAME_IDENTIFIER {$$ = $1; $$->push_back(new IdentifierNode($3));}
           | T_NAME_IDENTIFIER {$$ = new std::list<IdentifierNode*>();$$->push_back(new IdentifierNode($1));}
           ;

Return : T_RETURN Expression T_SEMICOLON {$$ = new ReturnStatementNode($2);}
       ;

Statement : Statement StatementB {$$ = $1; $$->push_back($2);}
          | StatementB {$$ = new std::list<StatementNode*>();$$->push_back($1);}
          ;

StatementB : Assignment { $$ = $1; } 
           | If { $$ = $1; } 
           | MethodCall T_SEMICOLON {$$ = new CallNode($1);}
           | While { $$ = $1; } 
           | DoWhile { $$ = $1; } 
           | print { $$ = $1; } 
          ;

Assignment : T_NAME_IDENTIFIER T_ASSIGNMENT Expression T_SEMICOLON {$$ = new AssignmentNode(new IdentifierNode($1),NULL,$3);}
           | T_NAME_IDENTIFIER T_PERIOD T_NAME_IDENTIFIER T_ASSIGNMENT Expression T_SEMICOLON {$$ = new AssignmentNode(new IdentifierNode($1),new IdentifierNode($3),$5);}
           ;

If : T_IF Expression T_OPENBRACKET Statement T_CLOSEBRACKET T_ELSE T_OPENBRACKET Statement T_CLOSEBRACKET { $$ = new  IfElseNode($2,$4,$8);}
   | T_IF Expression T_OPENBRACKET Statement T_CLOSEBRACKET { $$ = new  IfElseNode($2,$4,NULL);}
   ;

While : T_WHILE Expression T_OPENBRACKET Statement T_CLOSEBRACKET { $$ = new  WhileNode($2,$4);}
      ;

DoWhile : T_DO T_OPENBRACKET Statement T_CLOSEBRACKET T_WHILE T_OPENPAREN Expression T_CLOSEPAREN T_SEMICOLON
          {$$ = new DoWhileNode($3,$7);}
        ;

print : T_PRINT Expression T_SEMICOLON {$$ = new PrintNode($2);}
      ;
     
Expression : Expression T_PLUS Expression {$$ = new PlusNode($1,$3);}
           | Expression T_MINUS Expression {$$ = new MinusNode($1,$3);}
           | Expression T_MULTIPLY Expression {$$ = new TimesNode($1,$3);}
           | Expression T_DIVIDE Expression {$$ = new DivideNode($1,$3);}
           | Expression T_GREATER Expression {$$ = new GreaterNode($1,$3);}
           | Expression T_GREQ Expression {$$ = new GreaterEqualNode($1,$3);}
           | Expression T_EQUALS Expression {$$ = new EqualNode($1,$3);}
           | Expression T_AND Expression {$$ = new AndNode($1,$3);}
           | Expression T_OR Expression {$$ = new OrNode($1,$3);}
           | T_NOT Expression {$$ = new NotNode($2);}
           | T_MINUS Expression %prec T_NOT {$$ = new NegationNode($2);}
           | T_NAME_IDENTIFIER {$$ = new VariableNode(new IdentifierNode($1));}
           | T_NAME_IDENTIFIER T_PERIOD T_NAME_IDENTIFIER {$$ =  new MemberAccessNode(new IdentifierNode($1),new IdentifierNode($3));}
           | MethodCall {$$ = $1;}
           | T_OPENPAREN Expression T_CLOSEPAREN {$$ = $2;}
           | T_INTLITERAL {$$ = new IntegerLiteralNode(new IntegerNode($1));}
           | T_TRUE {$$ = new BooleanLiteralNode(new IntegerNode(1));}
           | T_FALSE {$$ = new BooleanLiteralNode(new IntegerNode(0));}
           | T_NEW T_NAME_IDENTIFIER {$$ = new NewNode(new IdentifierNode($2),NULL);}
           | T_NEW T_NAME_IDENTIFIER T_OPENPAREN Arguments T_CLOSEPAREN  {$$ = new NewNode(new IdentifierNode($2),$4);}
           ;

MethodCall : T_NAME_IDENTIFIER T_OPENPAREN Arguments T_CLOSEPAREN {$$ = new MethodCallNode(new IdentifierNode($1),NULL,$3);}
           | T_NAME_IDENTIFIER T_PERIOD T_NAME_IDENTIFIER T_OPENPAREN Arguments T_CLOSEPAREN {$$ = new MethodCallNode(new IdentifierNode($1),new IdentifierNode($3),$5);}
           ; 

Arguments : ArgumentsB {$$ = $1;}
          | %empty {$$ = new std::list<ExpressionNode*>();}
          ;

ArgumentsB : ArgumentsB T_COMMA Expression {$$ = $1; $$->push_back($3);}
           | Expression {$$ = new std::list<ExpressionNode*>();$$->push_back($1);}
           ;
%%

extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}
