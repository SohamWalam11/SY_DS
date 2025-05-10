#include <stdio.h>
#include <conio.h>  // Turbo C uses this for getch()

#define TABLE_SIZE 7

int hashTable[TABLE_SIZE];
int currentSize = 0;

void initHashTable() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    if (currentSize >= TABLE_SIZE) {
        printf("Hash Table is full! Cannot insert %d\n", key);
        return;
    }

    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i) % TABLE_SIZE] != -1) {
        i++;
        if (i == TABLE_SIZE) {
            printf("No available slot found for key %d\n", key);
            return;
        }
    }

    hashTable[(index + i) % TABLE_SIZE] = key;
    currentSize++;
    printf("Inserted %d at index %d\n", key, (index + i) % TABLE_SIZE);
}

void search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int pos = (index + i) % TABLE_SIZE;

        if (hashTable[pos] == key) {
            printf("Key %d found at index %d\n", key, pos);
            return;
        }

        if (hashTable[pos] == -1) {
            break;
        }

        i++;
    }

    printf("Key %d not found\n", key);
}

void display() {
    int i;
    printf("Hash Table:\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

void main() {
    int choice, key;
    clrscr();  // Turbo C screen clear
    initHashTable();

    while (1) {
        printf("\n---- Hash Table Menu ----\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    getch();  // Hold screen in Turbo C
}
