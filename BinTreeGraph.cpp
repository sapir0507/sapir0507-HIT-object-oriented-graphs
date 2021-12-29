#include "StdAfx.h"
#include "BinTreeGraph.h"
#include<math.h>

IMPLEMENT_SERIAL( BinTreeGraph, CObject, 1 )

BinTreeGraph::BinTreeGraph(void)
{
}

BinTreeGraph::BinTreeGraph(int size, COLORREF color, CPoint pos) : Graph(size, color, pos)
{
	setcenterp(pos);
}


BinTreeGraph::~BinTreeGraph(void)
{
}



void BinTreeGraph::buildgraph()
{
	int treeheight = ceil(Log2(getVsize()));
	setradius(treeheight*30);

	CPoint tempP1;
	CPoint tempP2;
	
	getvertices().RemoveAll();
	getedges().RemoveAll();


	AddVrtx(CPoint(getcenterp().x, getcenterp().y - getradius()));
	
	int j=0;
	int k = pow(double(2), j); 

	for(   ; j<treeheight ; j++, k = pow(double(2), j))
	{
		for(int i=0  ; i<k ; i++)
		{	
			
	
			tempP1.x = getvertices().GetAt(i+k-1).x - sin(double((45/(j+1))*Pi/180))*getradius()/(1+j);
			tempP1.y = getvertices().GetAt(i+k-1).y + cos(double(60*Pi/180))*getradius()/(1+j);
			AddVrtx(tempP1);
			AddEdge(Edge(getvertices().GetAt(i+k-1), tempP1));

			if((getvertices().GetSize()-1) < getVsize()-1)
			{
				tempP2.x = getvertices().GetAt(i+k-1).x + sin(double((45/(j+1))*Pi/180))*getradius()/(1+j);
				tempP2.y = getvertices().GetAt(i+k-1).y + cos(double(60*Pi/180))*getradius()/(1+j);
				AddVrtx(tempP2);
				AddEdge(Edge(getvertices().GetAt(i+k-1), tempP2));
			}
			
			
		}
	}
	setEsize(getVsize()-1);
}

double BinTreeGraph::Log2( double n )  
{  
    // log(n)/log(2) is log2.  
    return log( n ) / log( double(2) );  
} 




