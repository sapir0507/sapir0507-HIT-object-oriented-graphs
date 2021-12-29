
#include "stdafx.h"
#include "MFC_PRJ_FINAL.h"
#include "Graph.h"


IMPLEMENT_SERIAL( Graph, CObject, 1 )

Graph::Graph(void)
{
}

Graph::Graph(int size, COLORREF color, CPoint pos)
{
	Vsize = size;
	Vcolor = color;
	centerp = pos;
}


Graph::~Graph(void)
{
}

void Graph::PrintGraph(CDC *dc)const
{
	CPoint tempv;
	CRgn temprgn; 
	CBrush b(Vcolor);
	
		
	for(int i=0 ; i<Esize ; i++ )
	{		
		dc->MoveTo(edges.GetAt(i).v1);
		dc->LineTo(edges.GetAt(i).v2);
	}
	
	for(int i=0 ; i<Vsize ; i++ )
	{
		tempv = vertices.GetAt(i);
		temprgn.CreateEllipticRgn(tempv.x+5, tempv.y+5, tempv.x-6, tempv.y-6);
		dc->FillRgn(&temprgn, &b);
		temprgn.DeleteObject();
	}


}


void Graph::Serialize(CArchive& arch)
{
	vertices.Serialize(arch);
	edges.Serialize(arch);
	
	CObject::Serialize(arch);
    if (arch.IsStoring())
    {
        arch << centerp;
        arch << Vsize;
		arch << Esize;
		arch << Vcolor;
		arch << radius;
    }
    else
    {
        arch >> centerp;
        arch >> Vsize;
		arch >> Esize;
		arch >> Vcolor;
		arch >> radius;
    }
}


bool Graph::isonaGraph(const CPoint& point) {
	

	CRgn temprgn;

	temprgn.CreateEllipticRgn(centerp.x+radius, centerp.y+radius, centerp.x-radius, centerp.y-radius);
	
	if(temprgn.PtInRegion(point))
	{
		return true;
	}
	temprgn.DeleteObject();
		
	
	return false;
 }


void Graph::MarkGraph(CDC *dc)const
{
	CPoint tempv;
	CRgn temprgn; 
	CBrush b(Vcolor);
	
		
	for(int i=0 ; i<Esize ; i++ )
	{		
		dc->MoveTo(edges.GetAt(i).v1);
		dc->LineTo(edges.GetAt(i).v2);
	}
	
	for(int i=0 ; i<Vsize ; i++ )
	{
		tempv = vertices.GetAt(i);
		temprgn.CreateEllipticRgn(tempv.x+10, tempv.y+10, tempv.x-11, tempv.y-11);
		dc->SetROP2(R2_XORPEN);
		dc->FillRgn(&temprgn, &b);
		temprgn.DeleteObject();
	}




}