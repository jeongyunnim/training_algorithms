#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    char c;
    struct s_node *prev;
    struct s_node *next;
}node;

typedef struct s_list {
    node head;
    node tail;
    int size;
}dlist;

int M;
char input[100001];

void insert_before(dlist *list, node *it, char c) {
    node *cur;

    cur = malloc(sizeof(node));
    cur->c = c;
    cur->prev = it->prev;
    cur->next = it;
    it->prev->next = cur;
    it->prev = cur;
}

void erase_before(dlist *list, node *it) {
    node *target;

    if (it == list->head.next)
        return ;
    target = it->prev;
    target->prev->next = it;
    it->prev = target->prev;
    free(target);
}

void move_cursor(dlist *list, node **cursor, int dir) {
    if (dir == -1) {
        if (*cursor == list->head.next) {
            return ;
        }
        *cursor = (*cursor)->prev;
    } else if (dir == 1) {
        if (*cursor == &list->tail) {
            return ;
        }
        *cursor = (*cursor)->next;
    }
}

void push_back(dlist *list, char c) {
    node *cur = calloc(1, sizeof(node));
    cur->c = c;
    cur->prev = list->tail.prev;
    cur->next = &list->tail;
    list->tail.prev->next = cur;
    list->tail.prev = cur;
    list->size += 1;
}

void print_list(dlist *list) {
    node *cur = list->head.next;

    while (cur != &list->tail) {
        printf("%c", cur->c);
        cur = cur->next;
    }
    printf("\n");
}

void init(dlist* list, node **cursor) {
    char *offset = input;

    list->head.next = &list->tail;
    list->tail.prev = &list->head;
    while (*offset) {
        push_back(list, *offset);
        offset += 1;
    }
    *cursor = &list->tail;
}

int main() {
    dlist L = {0};
    node *cursor = 0;
    char op = 0, target = 0;

    scanf("%s", input);
    scanf("%d ", &M);
    init(&L, &cursor);
    for (int i = 0; i < M; ++i) {
        scanf(" %c", &op);
        if (op == 'L') {
            move_cursor(&L, &cursor, -1);
        } else if (op == 'D') {
            move_cursor(&L, &cursor, 1);
        } else if (op == 'B') {
            erase_before(&L, cursor);
        } else {
            scanf (" %c", &target);
            insert_before(&L, cursor, target);
        }
    }
    print_list(&L);
}

