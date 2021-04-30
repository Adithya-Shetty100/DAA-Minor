#include <stdlib.h>
#include <string.h>
#include "session11_horspools.h"

int *horspools_strmatch_patterns(char *text, char **patterns, int t)
{
	int *value_table=(int*)malloc(t*sizeof(int*)); //position table for each pattern
	
	for(int i=0;i<t;i++)
	{
		value_table[i]=horspools_strmatch_pattern(text, patterns[i]);
			
	}  
	
	return value_table;   
}

int horspools_strmatch_pattern(char *text, char *pattern)
{
	//to build shift table
	int len=strlen(pattern);
	int *table=(int*)malloc(sizeof(int)*256);
	
	for(int i=0;i<256;i++)
		table[i]=len;
	for(int i=0;i<len-1;i++)
	{
		int pos=(int)pattern[i];
		int offset= len-1-i;
		table[pos]=offset;
	}
	
	//find first occurrence
	int first=-1;
	int n = strlen(text);
    	int i = len-1;
    	int k;
    	
    	while(i<n)
    	{
    		k=0;
    		while((k<len) && (pattern[len-1-k]==text[i-k]))
    			k++;
    			
    		if(k==len)
    		{
    			first=i-k+1;
    			break;
    		}
    		else
		{
			i=i+table[(int)text[i]];
		}
    		    	
    	}
    	
    	free(table);
    	return first;
	
}


