#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqList.h"
SEQTable_t *createSeqTable(int n) {
    SEQTable_t * table = NULL;
    table = malloc(sizeof(SEQTable_t));//结构体变量的尺寸？
    if (table == NULL) {
        fprintf(stderr,"Table malloc failed!\n");
        return NULL;
    }
    table->data = malloc(sizeof(Element_t) * n);
    if (table->data == NULL) {
        fprintf(stderr,"Table data malloc failed!\n");
        return NULL;
    }
    table->pos = 0;
    table->capacity = n;
    return table;
}
void releaseSEQTable(SEQTable_t *table) {
    free(table->data);
    free(table);//注意要单独释放结构体内的动态分配内存
}

static int enlarger(SEQTable_t *table) {
    //申请新空间，初始化新空间
    if (table == NULL) {
        printf("Enlarger malloc failed!\n");
        return -1;
    }
    Element_t *tmp = malloc(sizeof(Element_t) * table->capacity *2);//二倍扩容
    if (tmp == NULL) {
        printf("Enlarger malloc failed!\n");
        return -1;
    }
    //拷贝老内容到新空间
    memcpy(tmp,table->data,sizeof(Element_t) * table->pos);
    //更新表头，释放老空间
    table->capacity *= 2;
    table->data = tmp;
    free(table->data);//pos时隔数字，代表现有元素的数量，可以不更新
    return 0;
}

int pushbackSEQTable(SEQTable_t *table, Element_t value) {//尾插法，从末尾插入
    if (table == NULL) {
        fprintf(stderr,"Table is NULL!\n");
        return -1;
    }
    //顺序表没有多余的位置，进行扩容
    if (table->pos >= table->capacity && enlarger(table)) {
        return -1;
    }
    table->data[table->pos] = value;
    ++table->pos;
    return 0;
}

int insertSEQTable(SEQTable_t *table, int index, Element_t value) {
    //空间有效性的判断
    if (index >= table->pos || index < 0) {
        fprintf(stderr,"Index out of range!\n");
        return -1;
    }
    //空间扩容
    if (table->pos >= table->capacity && enlarger(table)) {
        return -1;
    }
    //搬移数据为新数据预留位置
    //从后往前搬运数据
    for (int i = table->pos; i >= index; i--) {
        table->data[i+1] = table->data[i];
    }
    table->data[index] = value;
    ++table->pos;
    return 0;
}

int deleteSEQTable(SEQTable_t *table, Element_t value) {
    //查找值在表中的位索引置
int index = findSEQTable(table, value);
    if (index == -1) {
        fprintf(stderr, "Index not find!\n");
        return -1;
    }
    //删除这个元素，把[index, pos)往前搬
    for (int i = index + 1; i < table->pos; i++) {
        table->data[i-1] = table->data[i];
    }
    --table->pos;
    return 0;
}

int findSEQTable(const SEQTable_t *table, Element_t value) {
    for (int i = 0; i < table->pos; i++) {
        if (table->data[i] == value) {
            return i;
        }
    }
    return -1;
}

void showSeqTable(const SEQTable_t *table) {
    if (table == NULL) return;
    for (int i = 0; i < table->pos; ++i) {
        printf("%d\t", table->data[i]);
    }
    printf("\n");
}
