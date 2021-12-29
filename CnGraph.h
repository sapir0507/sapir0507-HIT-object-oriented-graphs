#pragma once
#include "graph.h"
class CnGraph : public Graph
{

public:
	DECLARE_SERIAL( CnGraph )

	CnGraph(void);
	CnGraph(int Vsize, COLORREF Vcolor, CPoint pos);
	virtual ~CnGraph(void);
	
	virtual void buildgraph();
};

