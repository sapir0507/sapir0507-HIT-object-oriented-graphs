#pragma once
#include "afxtempl.h"
#include "Graph.h"
class CStack :
	public CTypedPtrList< CObList, Graph* >
{
public:
    // Add element to top of stack
    void Push( Graph* newG ){ AddHead( newG ); }

    // Peek at top element of stack
    Graph* Peek(){ return IsEmpty() ? NULL : GetHead(); }

    // Pop top element off stack
    Graph* Pop(){ return RemoveHead(); }
};
