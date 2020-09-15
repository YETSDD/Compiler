%{
    int indicator = 0;
    char *addr_type = NULL;
%}
%option noyywrap

letter [0-9a-fA-F]
v4part [1][0-9]{0,2}|[2](([0-4]?[0-9]?)|([5]?[0-5]?))|[3-9][0-9]?|0
v6part {letter}{1,4}
v4 ^({v4part}\.){3,3}{v4part}$
v6 ^({v6part}\:){7,7}{v6part}$

%%
{v4} { indicator = 4; }
{v6} { indicator = 6; }
<<EOF>> {
    if(indicator == 4)
        addr_type = "IPv4";
    else if(indicator == 6)
        addr_type = "IPv6";
    else
        addr_type = "Neither";
    indicator = 0;
    return 0;
}
\n {}
. {}
%%
char *validIPAddress(char *IP){
    YY_BUFFER_STATE buf;
    buf = yy_scan_string(IP);
    yylex();
    yy_delete_buffer(buf);
    return addr_type;
}
