%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char* s);
extern int yylineno;
%}

//tokens
%token START_STMT
%token END_STMT
%token NOT
%token LP
%token RP
%token LB
%token RB
%token LSB
%token RSB
%token DOT
%token COMMA
%token SEMICOLON
%token ASSIGN_OP
%token EQUAL_CHECK
%token NOT_EQUAL_CHECK
%token STRING_IDENTIFIER
%token CHAR_IDENTIFIER
%token DIGIT
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token INCREMENT
%token DECREMENT
%token EXP
%token GT
%token LT
%token LTE
%token GTE
%token AND
%token OR
%token UNDERSCORE
%token ICARUS_IN
%token ICARUS_OUT
%token TYPE 
%token IF
%token ELSE
%token ELSEIF
%token FOR
%token WHILE
%token DO
%token VOID
%token RETURN_STMT
%token BOOL_STMT
%token STRING_STMT
%token CONST
%token REAL
%token CHAR_STMT
%token READ_HEADING
%token READ_ALTITUDE
%token READ_TEMPERATURE
%token SET_MOVE
%token MOVEMENT
%token SET_HEADING
%token SET_NOZZLE
%token CONNECT_WIFI
%token DISCONNECT_WIFI
%token DOC_COMMENT_START
%token DOC_COMMENT_END
%token DOC_COMMENT
%token LINE_COMMENT
%token IDENTIFIER
%token TEXT

%start program
%right ASSIGN_OP

%%

program:
	main {printf("Input program is valid\n"); return 0;}

main:
	START_STMT statements END_STMT

statements: 
	statement|statements statement

statement:
	comment|expr SEMICOLON|loops|method_dec|conditional

comment:
	LINE_COMMENT|DOC_COMMENT

expr:
	assignment_expr
	|IDENTIFIER DOT builtIn_method
	|method_dec_call
	|inout_expr

assignment_expr:
	var_declaration|general_expr|real_expr|bool_expr
	|string_expr|char_expr|input_expr|method_expr

var_declaration:
	TYPE IDENTIFIER

general_expr:
	IDENTIFIER ASSIGN_OP IDENTIFIER|IDENTIFIER ASSIGN_OP STRING_STMT
	|IDENTIFIER ASSIGN_OP CHAR_STMT|IDENTIFIER ASSIGN_OP BOOL_STMT
	|IDENTIFIER ASSIGN_OP REAL

real_expr:
	TYPE IDENTIFIER ASSIGN_OP operation

operation:
	operation addition term|term

term:
	term multiplication factor|factor

factor:
	LP operation RP|IDENTIFIER|REAL|ICARUS_IN LSB RSB

addition:
	PLUS|MINUS

multiplication:
	MULTIPLY|DIVIDE

bool_expr:
	TYPE IDENTIFIER ASSIGN_OP BOOL_STMT

string_expr:
	TYPE IDENTIFIER ASSIGN_OP STRING_STMT

char_expr:
	TYPE IDENTIFIER ASSIGN_OP CHAR_STMT

input_expr:
	IDENTIFIER ASSIGN_OP ICARUS_IN LSB RSB

method_expr: 
	TYPE IDENTIFIER ASSIGN_OP IDENTIFIER DOT builtIn_method
	|IDENTIFIER ASSIGN_OP IDENTIFIER DOT builtIn_method

builtIn_method:
	READ_HEADING LSB RSB|READ_ALTITUDE LSB RSB|READ_TEMPERATURE LSB RSB|SET_MOVE LSB MOVEMENT RSB
	|SET_MOVE LSB MOVEMENT COMMA operation RSB|SET_HEADING LSB operation RSB
	|SET_NOZZLE LSB BOOL_STMT RSB|SET_NOZZLE LSB IDENTIFIER RSB
	|CONNECT_WIFI LSB RSB|DISCONNECT_WIFI LSB RSB

method_dec_call:
	IDENTIFIER DOT IDENTIFIER LSB parameters RSB 

parameters:
	IDENTIFIER|IDENTIFIER COMMA parameters

inout_expr:
	ICARUS_IN LSB RSB|ICARUS_OUT LSB output RSB

output:
	IDENTIFIER|STRING_STMT

loops:
	while_stmt|for_stmt|doWhile_stmt

while_stmt:
	WHILE LSB logicalExpr RSB LB statements RB

logicalExpr:
	logicalParam logicalOperator logicalParam

logicalParam:
	method_dec_call|BOOL_STMT|IDENTIFIER|REAL
	|NOT method_dec_call|NOT BOOL_STMT|NOT IDENTIFIER

logicalOperator:
	EQUAL_CHECK|NOT_EQUAL_CHECK|GT|GTE|LT|LTE|AND|OR

for_stmt:
	FOR LSB initialization SEMICOLON logicalExpr SEMICOLON incDec RSB LB statements RB

initialization:
	assignment_expr|

incDec:
	IDENTIFIER INCREMENT|IDENTIFIER DECREMENT

doWhile_stmt:
	DO LB statements RB WHILE LSB logicalExpr RSB

method_dec:
	VOID IDENTIFIER LSB method_dec_parameters RSB LB statements RB
	|TYPE IDENTIFIER LSB method_dec_parameters RSB LB statements RB

method_dec_parameters:
	TYPE IDENTIFIER COMMA method_dec_parameters|TYPE IDENTIFIER|

conditional:
	if_stmt

if_stmt:
	IF LSB logicalExpr RSB LB statements RB else_stmt
	|IF LSB logicalExpr RSB LB statements RB elseif_stmt else_stmt

else_stmt:
	ELSE LB statements RB

elseif_stmt:
	ELSEIF LSB logicalExpr RSB LB statements RB

%%
void yyerror(char *s) {
	fprintf(stdout, "line %d: %s\n", yylineno,s);
}
int main(void){
 yyparse();
if(yynerrs < 1){
		printf("Parsing successful!\n");
	}
 return 0;
}

