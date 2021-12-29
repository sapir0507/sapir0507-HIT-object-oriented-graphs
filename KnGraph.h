#pragma once
#include "cngraph.h"
class KnGraph : public CnGraph
{

public:
	DECLARE_SERIAL( KnGraph )

	KnGraph(void);
	KnGraph(int Vsize, COLORREF Vcolor, CPoint pos);
	virtual ~KnGraph(void);

	void buildgraph();
};

