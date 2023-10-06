start_stmt 			\<\<\<
end_stmt         	\>\>\>
block_start			\<\<
block_end			\>\>
hashtag 			\#
void_return			void
int_type			int
string_type			string
char_type			char
bool_type			bool
float_type			float
const_identifier	const
drone_type			drone
type				bool_type|char_type|string_type|int_type
if_stmt				if
else_stmt			else
for_stmt			for
while_stmt			while
do_stmt				do
return_stmt			return
icarusin			icarusin
icarusout			icarusout
underscore			\_

newline				\n
true				true
false				false
line_comment_sym	\<\>
comment_start		\<\*\*\>
comment_end			\<\*\>
line_comment		{line_comment_sym}([^\n])*\n
comment				{comment_start}([^\<\*\>])*{comment_end}

heading_fcn			{text}\.direction\[\]
altitude_fcn		{text}\.altitude\[\]
temp_fcn			{text}\.temperature\[\]
movement			(up|down|left|right|front|back|stop)
move_fcn			{text}\.move\[
movement_type		({movement}\,[ \t]*{int_unsigned}\]|{movement}\])
set_heading_fcn		{text}\.setHeading\[{int_unsigned}\]
set_nozzle_fcn		{text}\.setNozzle\[{bool_stmt}\]
connect_wifi_fcn	{text}\.connectWifi\[\]
disconnect_wifi_fcn	{text}\.disconnectWifi\[\]
parameter			{type}[ \t]*{text}
method_dec			{return_type}[ \t]+{text}\[({type}[ \t]+{text})*\]
method_call			({text}\.{text}\[({text}|{digit}*)\]|{text}\[({text}|{digit}*)\])

return_type			{void_return}|{type}

digit				[0-9]
capital_letter		[A-Z]
lower_letter		[a-z]
letter				{capital_letter}|{lower_letter}
text				{lower_letter}({letter}|{digit}|{underscore})*
string_stmt 		\"(.)*\"
bool_stmt			{true}|{false}
int_unsigned		{digit}+
int_signed			[+-]?{digit}+
float_unsigned 		{digit}*(\.)?{digit}+
float_signed 		[+-]?{digit}*(\.)?{digit}+
char_stmt			\'[^\\\']\'
increment_stmt		{text}+\+\+
decrement_stmt		{text}+\-\-


%%
{start_stmt}			printf("START_STMT ");
{end_stmt}         	printf("END_STMT ");
{block_start}			printf("BLOCK_START ");
{block_end}			printf("BLOCK_END ");
\!			printf("NOT ");
\(            		printf("LP ");
\)            		printf("RP ");
\{            		printf("LB ");
\}            		printf("RB ");
\[            		printf("LSB ");
\]            		printf("RSB ");
\.            		printf("DOT ");
\,            		printf("COMMA ");
\;            		printf("SEMICOLON ");
\=             		printf("ASSIGN_OP ");
\=\=			printf("EQUAL_CHECK ");
\!\=			printf("NOT_EQUAL_CHECK ");
\"            		printf("STRING_IDENTIFIER ");
\'            		printf("CHAR_IDENTIFIER ");
\+        			printf("PLUS ");
\-        			printf("MINUS ");
\*			printf("MULTIPLY ");
{increment_stmt}		printf("INCREMENT ");
{decrement_stmt}		printf("DECREMENT ");
\^			printf("EXP ");
\>			printf("GT ");
\<			printf("LT ");
\<\=			printf("LTE ");
\>\=			printf("GTE ");
\&\&			printf("AND ");
\|\|			printf("OR ");
{newline}       		printf("NEW_LINE \n");
{underscore}		printf("UNDERSCORE ");
{icarusin}		printf("ICARUS_IN ");
{icarusout}		printf("ICARUS_OUT ");
{int_type}		printf("INT ");
{string_type}		printf("STRING ");
{char_type}		printf("CHAR ");
{bool_type}		printf("BOOL ");
{drone_type}	printf("DRONE ");
{if_stmt}		printf("IF ");
{else_stmt}		printf("ELSE ");
{for_stmt}		printf("FOR ");
{while_stmt}		printf("WHILE ");
{do_stmt}		printf("DO ");
{void_return}		printf("VOID ");
{return_stmt}		printf("RETURN ");
{true}		printf("TRUE ");
{false}		printf("FALSE ");
{string_stmt} 		printf("STRING_STMT ");
{const_identifier}	printf("CONST ");
{int_unsigned}		printf("INT_UNSIGNED ");
{int_signed}		printf("INT_SIGNED ");
{float_unsigned}	printf("FLOAT_UNSIGNED ");
{float_signed}		printf("FLOAT_SIGNED ");
{char_stmt}		printf("CHAR_STMT ");
{movement_type}			printf("MOVE_TYPE ");
{return_type}			printf("RETURN_TYPE ");
{text}		printf("IDENTIFIER ");
{heading_fcn}			printf("HEADING_FCN ");
{altitude_fcn}			printf("ALTITIUDE_FCN ");
{temp_fcn}			printf("TEMPERATURE_FCN ");
{move_fcn}			printf("MOVE_FCN ");
{set_heading_fcn}	printf("SET_HEADING_FCN ");
{set_nozzle_fcn}		printf("SET_NOZZLE_FCN ");
{connect_wifi_fcn}	printf("CONNECT_WIFI_FCN ");
{disconnect_wifi_fcn}	printf("DISCONNECT_WIFI_FCN ");
{method_dec}		printf("METHOD_DECLARATION ");
{method_call}		printf("METHOD_CALL ");
{comment}		printf("COMMENT ");
{line_comment}	printf("LINE_COMMENT ");
.	          		;

%%
int yywrap(void) {
	return 1;
}

int main(void) {
	yylex();
	return 0;
}

