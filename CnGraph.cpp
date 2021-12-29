#include "StdAfx.h"
#include "CnGraph.h"
#include<math.h>

IMPLEMENT_SERIAL( CnGraph, CObject, 1 )

CnGraph::CnGraph(void) 
{
	
}

CnGraph::CnGraph(int Vsize, COLORREF Vcolor, CPoint pos) : Graph(Vsize, Vcolor, pos) 
{
	setcenterp(pos);
}


CnGraph::~CnGraph(void)
{
}

void CnGraph:: buildgraph(){

	setradius( (getVsize()*50)/(2*Pi) );
	CPoint tempP;
	
	getvertices().RemoveAll();
	getedges().RemoveAll();

	
	setEsize(getVsize());
	
	for(int i=0; i<getVsize() ;i++)
	{
		tempP.x = getcenterp().x + sin(double(i*(360/getVsize())*(Pi/180)))*getradius();
		tempP.y = getcenterp().y - cos(double(i*(360/getVsize())*(Pi/180)))*getradius();
		AddVrtx(tempP);
	}
		
	for(int i=1; i<getVsize() ;i++)
	{
		
		AddEdge(Edge(getvertices().GetAt(i-1), getvertices().GetAt(i)));
	}
	if(getVsize()>0)
		AddEdge(Edge(getvertices().GetAt(getVsize()-1), getvertices().GetAt(0)));
}




