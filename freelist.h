#ifndef _FREELIST_H_
#define _FREELIST_H_

#define SOLT_NUM 256

typedef struct Freelist_n
{
	int count;
	void *slot[SOLT_NUM];
	struct Freelist_n *next;
} Freelist_n;

typedef struct Freelist_m
{
	Freelist_n *node;
} Freelist_m;

typedef struct InnerList
{
	Freelist_m *inner8;
	Freelist_m *inner16;
} InnerList;

typedef struct TempList
{
	Freelist_n *fnlist8;
	Freelist_n *fnlist16;
} TempList;

typedef struct Freelist
{
	InnerList innerlist;
	TempList fulllist;
	TempList emptylist;

} Freelist;

void Freelist_init(Freelist **freelist); // 初始化内存池
void *Freelist_pop();					 // 取出结点
void Freelist_push();					 // 存入结点
void Freelist_fini();					 // 释放资源
#endif
