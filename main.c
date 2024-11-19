/*Write a function in C that concatenates two strings without using any library functions such as strcat. 
The function should use pointers for both strings and dynamically allocate memory to hold the concatenated 
result. The function should be called concatenate(char *str1, char *str2) and return a pointer to the newly concatenated string
*/
#include <stdio.h>

char* concatenate(char *str1, char *str2) {
    int len1 = 0, len2 = 0;

    while (*(str1 + len1) != '\0') {
        len1++;
    }

    while (*(str2 + len2) != '\0') {
        len2++;
    }

    // allocate memory for the concatenated string
    char *result;
    result = (char*) malloc((len1 + len2 + 1) * sizeof(char)); // +1 for null terminator
    //copy str1 into result
    int i = 0;
    for (i = 0; i < len1; i++) {
        *(result + i) = *(str1 + i);
    }
    // append str2 to result
    for (int j = 0; j < len2; j++, i++) {
        *(result + i) = *(str2 + j);
    }
    //Null-terminate the concatenated string
    *(result + i) = '\0';

    return result;
}

int main() {
    char str1[] = "Darien ";
    char str2[] = "Gillins";

    // Call function
    char *concatenated = concatenate(str1, str2);

    // Print the string
    if (concatenated != NULL) {
        printf("Concatenated String: %s\n", concatenated);       
        // Free allocated memory 
        free(concatenated);
    }

    return 0;
}
