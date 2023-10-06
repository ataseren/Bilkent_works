%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(char *);
%}

START_STMT 			\<\<\<
END_STMT         	\>\>\>
HASHTAG 			\#
VOID				void
TYPE                {REAL_TYPE}|{STRING_TYPE}|{CHAR_TYPE}|{BOOL_TYPE}|{DRONE_TYPE}
REAL_TYPE			real
STRING_TYPE			string
CHAR_TYPE			char
BOOL_TYPE			bool
CONST_IDENTIFIER	const
DRONE_TYPE			drone
IF_STMT				if
ELSE_STMT			else
ELSEIF_STMT			elseif
FOR_STMT			for
WHILE_STMT			while
DO_STMT				do
RETURN_STMT			return
ICARUSIN			icarusin
ICARUSOUT			icarusout
UNDERSCORE			\_

NEWLINE				\n
TRUE				true
FALSE				false
LINE_COMMENT_SYM	\<\>
COMMENT_START		\<\*\*\>
COMMENT_END			\<\*\>
LINE_COMMENT		{LINE_COMMENT_SYM}([^\n])*\n
DOC_COMMENT_START	{COMMENT_START}([^\<\*\>])*
DOC_COMMENT_END		{COMMENT_END}
DOC_COMMENT			{DOC_COMMENT_START}{DOC_COMMENT_END}

READ_HEADING_FCN	readHeading				 
READ_ALTITUDE_FCN	readAltitude
READ_TEMP_FCN		readTemperature
MOVEMENT			(up|down|left|right|front|back|stop)
SET_MOVE_FCN		setMove
SET_HEADING_FCN		setHeading
SET_NOZZLE_FCN		setNozzle
CONNECT_WIFI_FCN	connectWifi
DISCONNECT_WIFI_FCN	disconnectWifi

DIGIT				[0-9]
CAPITAL_LETTER		[A-Z]
LOWER_LETTER		[a-z]
LETTER				{CAPITAL_LETTER}|{LOWER_LETTER}
IDENTIFIER			{LOWER_LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*
TEXT				({LETTER}|{DIGIT}|{UNDERSCORE})* 
STRING_STMT 		\"(.)*\"
BOOL_STMT			{TRUE}|{FALSE}
REAL				[+-]?{DIGIT}*(\.)?{DIGIT}+
CHAR_STMT			\'[^\\\']\'
INCREMENT_STMT		\+\+
DECREMENT_STMT		\-\-

NOT					\!					
LP					\(				
RP					\)				
LB					\{				
RB					\}				
LSB					\[				
RSB					\]				
DOT					\.				
COMMA				\,				
SEMICOLON			\;				
ASSIGN_OP			\=				
EQUAL_CHECK			\=\=			
NOT_EQUAL_CHECK		\!\=				
STRING_IDENTIFIER	\"				
CHAR_IDENTIFIER		\'				
PLUS				\+				
MINUS				\-				
MULTIPLY			\*	
DIVIDE				\/
EXP					\^
GT					\>
LT					\<
LTE					\<\=
GTE					\>\=
AND					\&\&
OR					\|\|

%option yylineno
%%
{START_STMT}			return START_STMT;
{END_STMT}         		return END_STMT;
{NOT}					return NOT;
{LP}            		return LP;
{RP}            		return RP;
{LB}            		return LB;
{RB}            		return RB;
{LSB}            		return LSB;
{RSB}            		return RSB;
{DOT}            		return DOT;
{COMMA}            		return COMMA;
{SEMICOLON}            	return SEMICOLON;
{ASSIGN_OP}             return ASSIGN_OP;
{EQUAL_CHECK}			return EQUAL_CHECK;
{NOT_EQUAL_CHECK}		return NOT_EQUAL_CHECK;
{STRING_IDENTIFIER}     return STRING_IDENTIFIER;
{CHAR_IDENTIFIER}       return CHAR_IDENTIFIER;
{DIGIT}					return DIGIT;
{PLUS}        			return PLUS;
{MINUS}        			return MINUS;
{MULTIPLY}				return MULTIPLY;
{DIVIDE}				return DIVIDE;
{INCREMENT_STMT}		return INCREMENT;
{DECREMENT_STMT}		return DECREMENT;
{EXP}					return EXP;
{GT}					return GT;
{LT}					return LT;
{LTE}					return LTE;
{GTE}					return GTE;
{AND}					return AND;
{OR}					return OR;
{NEWLINE}       		;
{UNDERSCORE}			return UNDERSCORE;
{ICARUSIN}				return ICARUS_IN;
{ICARUSOUT}				return ICARUS_OUT;
{TYPE}					return TYPE;
{IF_STMT}				return IF;
{ELSE_STMT}				return ELSE;
{ELSEIF_STMT}			return ELSEIF;
{FOR_STMT}				return FOR;
{WHILE_STMT}			return WHILE;
{DO_STMT}				return DO;
{VOID}					return VOID;
{RETURN_STMT}			return RETURN_STMT;
{BOOL_STMT}				return BOOL_STMT;
{STRING_STMT} 			return STRING_STMT;
{CONST_IDENTIFIER}		return CONST;
{REAL}					return REAL;
{CHAR_STMT}				return CHAR_STMT;
{READ_HEADING_FCN}		return READ_HEADING;
{READ_ALTITUDE_FCN}		return READ_ALTITUDE;
{READ_TEMP_FCN}			return READ_TEMPERATURE;
{SET_MOVE_FCN}			return SET_MOVE;
{MOVEMENT}				return MOVEMENT;
{SET_HEADING_FCN}		return SET_HEADING;
{SET_NOZZLE_FCN}		return SET_NOZZLE;
{CONNECT_WIFI_FCN}		return CONNECT_WIFI;
{DISCONNECT_WIFI_FCN}	return DISCONNECT_WIFI;
{DOC_COMMENT_START}		return DOC_COMMENT_START;
{DOC_COMMENT_END}		return DOC_COMMENT_END;
{DOC_COMMENT}			return DOC_COMMENT;
{LINE_COMMENT}			return LINE_COMMENT;
{IDENTIFIER}			return IDENTIFIER;
{TEXT}					return TEXT;
[ \t] 	          		;
%%

int yywrap(void){
	return 1;
}
