#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "freelist.h"

void Freelist_m_init(Freelist_m **freelist_m)
{
	Freelist_m *m_freelist_m = (Freelist_m *)malloc(sizeof(*m_freelist_m));
	m_freelist_m->node = (Freelist_n *)malloc(sizeof(*m_freelist_m->node));
	m_freelist_m->node->count = 0;
	m_freelist_m->node->next = NULL;
	*freelist_m = m_freelist_m;
}

void InnerList_init(InnerList *innerlist)
{
	// Freelist *m_freelist = (Freelist *)malloc(sizeof(**freelist));
	Freelist_m_init(innerlist->inner8);
	Freelist_m_init(innerlist->inner16);
}

void Freelist_init(Freelist **freelist)
{
	Freelist *m_freelist = (Freelist *)malloc(sizeof(**freelist));
	InnerList_init(&m_freelist->innerlist);
	*freelist = m_freelist;
}
