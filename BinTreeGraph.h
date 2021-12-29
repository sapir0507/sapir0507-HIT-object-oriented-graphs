#pragma once
#include "graph.h"
class BinTreeGraph : public Graph
{

	
public:
	DECLARE_SERIAL( BinTreeGraph )

	BinTreeGraph(void);
	BinTreeGraph(int size, COLORREF color, CPoint pos);
	virtual ~BinTreeGraph(void);

	virtual void buildgraph();
	double Log2( double n ) ;						//for calculating the tree height

};

