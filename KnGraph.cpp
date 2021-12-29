#include "StdAfx.h"
#include "KnGraph.h"
#include <math.h>

IMPLEMENT_SERIAL( KnGraph, CObject, 1 )

KnGraph::KnGraph(void) 
{
}

KnGraph::KnGraph(int Vsize, COLORREF Vcolor, CPoint pos) : CnGraph(Vsize, Vcolor ,pos) 
{
	setcenterp(pos);
}

KnGraph::~KnGraph(void)
{
}

void KnGraph::buildgraph()
{
	setradius ( (getVsize()*50)/(2*Pi) );
	CPoint tempP;
	
	getvertices().RemoveAll();
	getedges().RemoveAll();


	for(int i=0; i<getVsize() ;i++)
	{
		tempP.x = getcenterp().x + sin(double(i*(360/getVsize())*(Pi/180)))*getradius();
		tempP.y = getcenterp().y - cos(double(i*(360/getVsize())*(Pi/180)))*getradius();
		AddVrtx(tempP);
	}
	
	for(int j=1; j<=getVsize() ; j++)
	{
		for(int i=1; i<(getVsize()) ;i++)
		{
			AddEdge(Edge(getvertices().GetAt(j-1), getvertices().GetAt(i)));
		}
			
	}
	setEsize((getVsize()*(getVsize()-1)));
}