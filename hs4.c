#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101  // 해시 테이블 크기 (소수로 선택)

typedef struct HashNode {
    char *key;
    struct HashNode *next;
} HashNode;

HashNode* hashTable[TABLE_SIZE];

// DJB2 해싱 함수
unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % TABLE_SIZE;
}

// 새로운 노드를 생성하는 함수
HashNode* createNode(const char *key) {
    HashNode *newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->next = NULL;
    return newNode;
}

// 해시 테이블에 삽입하는 함수
void insert(const char *key) {
    unsigned int index = hash(key);
    HashNode *newNode = createNode(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
    printf("인덱스 %u번에 저장되었음\n", index);
}

// 해시 테이블에서 키를 탐색하는 함수
void search(const char *key) {
    unsigned int index = hash(key);
    HashNode *node = hashTable[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            printf("%s은 해쉬 테이블 %u 인덱스에 있음!\n", key, index);
            return;
        }
        node = node->next;
    }
    printf("%s은 해쉬 테이블에 존재하지 않음!\n", key);
}

// 해시 테이블에서 키를 삭제하는 함수
void delete(const char *key) {
    unsigned int index = hash(key);
    HashNode *node = hashTable[index];
    HashNode *prev = NULL;

    while (node != NULL && strcmp(node->key, key) != 0) {
        prev = node;
        node = node->next;
    }

    if (node == NULL) {
        printf("%s은 해쉬 테이블에 존재하지 않음!\n", key);
        return;
    }

    if (prev == NULL) {
        hashTable[index] = node->next;
    } else {
        prev->next = node->next;
    }

    free(node->key);
    free(node);
    printf("%s이 해쉬 테이블에서 삭제되었음!\n", key);
}

// 해시 테이블을 초기화하는 함수
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int main() {
    char choice;
    char key[50];

    initHashTable();

    while (1) {
        printf("삽입(i), 탐색(s), 삭제(d), 종료(q) : ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'i':
                printf("동물의 이름: ");
                scanf("%s", key);
                insert(key);
                break;
            case 's':
                printf("동물의 이름: ");
                scanf("%s", key);
                search(key);
                break;
            case 'd':
                printf("동물의 이름: ");
                scanf("%s", key);
                delete(key);
                break;
            case 'q':
                exit(0);
            default:
                printf("잘못된 입력입니다!\n");
        }
    }

    return 0;
}
