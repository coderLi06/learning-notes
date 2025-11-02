//
// Created by ASUS on 25-5-30.
//

#ifndef SEQ_LIST_H
#define SEQ_LIST_H
//定义一个数据空间存储类型
typedef int Element_t;//_t结尾一般认为是重定义后的数据类型
//定义匿名结构体并创建变量
typedef struct {
    Element_t *data;//存储表中数据的首地址
    int pos;//指向数据空间的待插入位置，也表示数据里空间个数
    int capacity;//表中目前最大的存储容量
}SEQTable_t;
SEQTable_t *createSEQTable(int n);//创建表头，在堆区?开辟空间，先初始化表头数据
void releaseSEQTable(SEQTable_t *table);//释放表头及内部的存储空间
int pushbackSEQTable(SEQTable_t *table, Element_t value);
int insertSEQTable(SEQTable_t *table, int index, Element_t value);
int deleteSEQTable(SEQTable_t *table, Element_t value);//按值删除
int findSEQTable(const SEQTable_t *table, Element_t value);
void showSeqTable(const SEQTable_t *table);
#endif //SEQ_LIST_H
