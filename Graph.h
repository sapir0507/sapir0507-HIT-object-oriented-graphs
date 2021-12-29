
#pragma once
#define Pi 3.14159265359
//Edges struct
struct Edge{
	CPoint v1;
	CPoint v2;
	
	Edge(){};
	Edge(CPoint v1_val, CPoint v2_val){v1 = v1_val; v2= v2_val;};
};



class Graph : public CObject
{
private:

	int Vsize;
	int Esize;
	COLORREF Vcolor;
	CPoint centerp;
	int radius;
	CArray<CPoint> vertices;
	CArray<Edge> edges;

public:
	DECLARE_SERIAL( Graph )

	Graph(void);
	Graph(int size, COLORREF color, CPoint pos);
	//Graph operator=(const Graph& g){};
	//Graph(const Graph& g){};
	virtual ~Graph(void);

	
	void setVcolor(COLORREF newcol){Vcolor = newcol;};
	void setVsize(int size){Vsize=size;};
	void setEsize(int size){Esize=size;};
	void setcenterp(const CPoint& coord){centerp=coord;};
	void setradius(int rad){radius = rad;};

	int getradius()const {return radius;};
	int getVsize()const {return Vsize;};
	int getEsize()const {return Esize;};
	COLORREF getVcolor()const{return Vcolor;};
	CArray<CPoint>& getvertices(){return vertices;};
	CArray<Edge>& getedges(){return edges;};
	CPoint getcenterp()const{return centerp;};

	void AddVrtx(const CPoint& vrtx){vertices.Add(vrtx);};
	void AddEdge(const Edge& e){edges.Add(e);};
	virtual void buildgraph(){};					//virtual function for polymorphism. cannot be pure virtual because of Serialization.
	void PrintGraph(CDC *dc)const;
	void MarkGraph(CDC *dc)const;
	bool isonaGraph(const CPoint& point);

	void Serialize(CArchive& arch);
};

