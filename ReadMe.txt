for(int j =0 ; j<Gsize ; j++)
	{
		for(int i=0 ; i<GRAPHS.GetAt(j)->getVsize() ; i++ )
		{
			tempoint = GRAPHS.GetAt(j)->getvertices().GetAt(i).getpoint();
			temprgn.CreateEllipticRgn(tempoint.x+10, tempoint.y+10, tempoint.x-11, tempoint.y-11);
		
			if(temprgn.PtInRegion(point) && !temprgn.PtInRegion(vrtx1.getpoint()) && numofvrtx < 2)
			{
				dc.FillRgn(&temprgn, &a);
				numofvrtx++;
			
				if(numofvrtx==1)
					vrtx1.setpoint(tempoint);
				else if(numofvrtx==2)
				{
					vrtx2.setpoint(tempoint);
					vrtx1.setneighbor(vrtx2);
					//vrtx2.setdeg();
					dc.FillRgn(&temprgn, &a);
					GRAPHS.GetAt(j)->AddEdge(&vrtx1, &vrtx2);
					GRAPHS.GetAt(j)->getvertices().GetAt(i).setneighbor(vrtx1);

					numofvrtx=0;
					Invalidate();
				}
			}
			temprgn.DeleteObject();
		}	

	}
	CDialogEx::OnRButtonDown(nFlags, point);
}
