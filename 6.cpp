#include<bits/stdc++.h>
using namespace std;

struct P{
    int x;
    int y;
};

//判断点是否在线上，在返回1，不在返回0
int onSegement(P p1,P p2,P Q)
{
    double maxx,minx,maxy,miny;

    maxx = p1.x >p2.x ?p1.x :p2.x ;    //矩形的右边长
    minx = p1.x >p2.x ?p2.x :p1.x ;     //矩形的左边长
    maxy = p1.y >p2.y ?p1.y :p2.y ;    //矩形的上边长
    miny = p1.y >p2.y ?p2.y :p1.y ;     //矩形的下边长

    if( ((Q.x -p1.x )*(p2.y -p1.y) == (p2.x -p1.x) *(Q.y -p1.y)) && ( Q.x >= minx && Q.x <= maxx ) && ( Q.y >= miny && Q.y <= maxy))
        return 1;
    else
        return 0;
}

//  The function will return YES if the point x,y is inside the polygon, or
//  NO if it is not.  If the point is exactly on the edge of the polygon,
//  then the function may return YES or NO.
bool IsPointInPolygon(vector<P> poly,P pt)
{
    int i,j;
    bool c = false;
    bool onSeg = false;
    for (i = 0,j = poly.size() - 1;i < poly.size();j = i++)
    {
        
        if (((poly[i].y <= pt.y) && (pt.y < poly[j].y)) || ((poly[j].y <= pt.y) && (pt.y < poly[i].y))){
        	if (((pt.x - poly[i].x) * (poly[j].y - poly[i].y) - (poly[j].x - poly[i].x) * (pt.y - poly[i].y) < 0) && ((poly[j].y>poly[i].y))){
        		c = !c;
			}else if (((pt.x - poly[i].x) * (poly[j].y - poly[i].y) - (poly[j].x - poly[i].x) * (pt.y - poly[i].y) > 0) && ((poly[j].y<poly[i].y))){
				c = !c;
			}
		}   
        
        if (onSegement(poly[i],poly[j],pt)){
        	onSeg=true;
		}
    }
    if (onSeg){
    	c=true;
	}
    return c;
}

vector<P>points,polygon;

int main(){
	ifstream in;
	in.open("input_question_6_points");
	int x,y;
	while(in>>x>>y){
		points.push_back(P{x,y});
	}
	in.close();
	
	in.open("input_question_6_polygon");
	
	while(in>>x>>y){
		polygon.push_back(P{x,y});
		
	}
	
	ofstream out;
	out.open("6.txt");
	
	for (auto p:points){
		out<<p.x<<" "<<p.y<<" ";
		if (IsPointInPolygon(polygon,p)){
			out<<"inside"<<endl;
		}else{
			out<<"outside"<<endl;
		}
	}
	
	out.close();
}

/*
points
7 11
10 14
11 4
12 21
16 3
16 10
17 4
18 7
18 17
20 7

*/

/*
polygon
4 3
2 6
3 12
2 17
5 20
9 21
14 19
20 14
18 3
11 7

*/

/*
7 11 inside
10 14 inside
11 4 outside
12 21 outside
16 3 outside
16 10 inside
17 4 inside
18 7 inside
18 17 outside
20 7 outside

*/
