#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // String Declaration and Initialization
    char str1[20] = "Hello";
    char str2[20] = " World";

    // String Output
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    // String Length
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("Length of String 1: %d\n", len1);
    printf("Length of String 2: %d\n", len2);

    // String Copy
    strcpy(str1, str2);
    printf("After copying String 2 to String 1: %s\n", str1);

    // String Concatenation
    strcat(str1, str2);
    printf("After concatenation: %s\n", str1);

    // String Comparison
    int result = strcmp(str1, str2);
    printf("Comparison result: %d\n", result);

    // Substring Extraction
    char substring[10];
    strncpy(substring, str1 + 6, 5);
    printf("Substring: %s\n", substring);

    // Substring Search
    char *ptr = strstr(str1, "World");
    printf("Substring found at position: %ld\n", ptr - str1);

    // String to Integer Conversion
    char numStr[] = "123";
    int num = atoi(numStr);
    printf("Integer value: %d\n", num);

    // Integer to String Conversion
    char intStr[10];
    sprintf(intStr, "%d", num);
    printf("Converted to String: %s\n", intStr);

    // String Tokenization
    char sentence[] = "This is a sentence. \n hello smit \n patel";
    char *token = strtok(sentence, "\n");
    while (token != NULL)
    {
        printf("Token: %s\n", token);
        token = strtok(NULL, "\n");
    }

    // String Formatting
    int x = 42;
    sprintf(str1, "Value of x is %d", x);
    printf("%s\n", str1);

    // String Comparison (Case Insensitive)
    int resultIgnoreCase = strcasecmp(str1, str2);
    printf("Case-insensitive comparison result: %d\n", resultIgnoreCase);

    // String Character Replacement
    char *charPtr = strchr(str1, 'o');
    printf("dfsd :- %s\n", charPtr);
    if (charPtr != NULL)
    {
        *charPtr = 'X';
    }
    printf("After replacing 'o' with 'X': %s\n", str1);

    // String Trimming (Removing Leading and Trailing Spaces): Custom implementation may be needed.

    return 0;
}
