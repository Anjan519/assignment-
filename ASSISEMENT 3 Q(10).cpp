#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LEN 100

int compareNames(char name1[], char name2[], char order) {
    if (order == 'A') {
        return strcmp(name1, name2);
    } else {
        return strcmp(name2, name1);
    }
}
int main() {
    char names[MAX_NAMES][MAX_NAME_LEN];
    char temp[MAX_NAME_LEN];
    int numNames, i, j;
    char order;

    printf("Enter the number of names: ");
    scanf("%d", &numNames);

    printf("Enter the names:\n");
    for (i = 0; i < numNames; i++) {
        scanf("%s", names[i]);
    }

    printf("Enter the sorting order (A/D): ");
    scanf(" %c", &order);

    for (i = 0; i < numNames-1; i++) {
for (j = 0; j < numNames-i-1; j++) {
            if (compareNames(names[j], names[j+1], order) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }

    printf("Sorted names:\n");
    for (i = 0; i < numNames; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}

