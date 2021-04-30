// Find the offset of the first occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
#include<string.h>
int searchFirstOccurrence(char *pattern, char *text)
{
int m=strlen(pattern);
int n=strlen(text);
for(int i=0;i<(n-m+1);i++)
	{
		int j=0;
		while(j<m && pattern[j]==text[i+j])
		{
			j=j+1;
		}
	if(j==m)
	return i;
	}
return -1;
}

// Find the offset of the last occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchLastOccurrence(char *pattern, char *text)
{
int m=strlen(pattern);
int n=strlen(text);
for(int i=n-m; i>=0; i--)
	{
	int j=0;
	while(j<m && pattern[j]==text[i+j])
		{
			j=j+1;
		}
	if(j==m)
	return i;
	}
return -1;
}

// Find the number of occurrences of the pattern in the given text
int numOccurrences(char *pattern, char *text)
{
int c=0;
int m=strlen(pattern);
int n=strlen(text);
for(int i=0;i<(n-m+1);i++)
	{
		int j=0;
		while(j<m && pattern[j]==text[i+j])
		{
			j=j+1;
		}	
	if(j==m)
	c=c+1;
	}
return c;
}

// Find the length of longest prefix of the pattern that matches a substring of the pattern
int longestPrefix(char *pattern, char *text)
{
int c=0;
int m=strlen(pattern);
int n=strlen(text);
for(int i=0; i<(n-m+1); i++)
	{
		int j=0;
		while(j<m && pattern[j]==text[i+j])
		{
			j=j+1;
		}
	if(j>c)
		{
			c=j;
		}
	}	
	return c;
}

// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text)
{
int c=0;
int m=strlen(pattern);
int n=strlen(text);
for(int i=0; i<(n-m+1); i++)
	{
		int j=0;
		while(j<m && pattern[j]==text[i+j])
		{
			j=j+1;
		}
		if(j==m)
		c=c+m;
		else
		c=c+j+1;
	}
	return c;
}

