typedef struct
{
    int firstOccurrence;
    int lastOccurrence;
    int numOccurrences;
    int charactersCompared;
} Result;


int *buildShiftTable(char *pattern);

Result *horspoolStringMatch(char *pattern, char *text);

void display(int*);
