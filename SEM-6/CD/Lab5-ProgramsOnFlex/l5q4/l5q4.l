/*Given a input C file, replace all scanf with READ and printf with WRITE statements also find the number
of scanf and printf in the file.*/
%{
int sf=0,pf=0;
%}

%%
"scanf"	{ sf++; fprintf(yyout,"READ");}  
"printf" { pf++; fprintf(yyout,"WRITE");} 
%%

int main()
{
	yyin=fopen("readfile.c","r"); 
	yyout=fopen("writefile.c","w");  
	yylex();
	printf("Number of scanfs=%d\nNumber of Printf's=%d\n",sf,pf);
    return 0;
}
int yywrap(){ return 1; }