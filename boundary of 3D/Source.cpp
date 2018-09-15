#include <iostream>
#define pi 3.14159265358979323846
#include <cmath> 
#include <vector>
using namespace std;

class Dot
{
public:
	double x;
	double y;
	Dot()
	{
		x = 0;
		y = 0;
	}
	Dot(double a, double b)
	{
		x = a;
		y = b;
	}
	void setDot()
	{
		cout << "請輸入X Y: ";
		cin >> x;
		cin >> y;
	}
	void setDot(double a, double b)
	{
		x = a;
		y = b;
	}
	double getx()
	{
		return x;
	}
	double gety()
	{
		return y;
	}

};

class XYboundCal
{
public:

	double U, D, L, R, origin_x, origin_y, BL, BW;
	vector <Dot> bound;//UDLW 上下左右
	vector <Dot> dot;

	XYboundCal()
	{

	}
	void pushXY(Dot temp)
	{
		dot.push_back(temp);
		if (bound.size()<4)
			bound.push_back(temp);
	}
	void getBound()
	{
		for (int i = 0; i < dot.size(); i++)
		{
			if (dot[i].y > bound[0].y)
				bound[0].y = dot[i].y;
			if (dot[i].y < bound[1].y)
				bound[1].y = dot[i].y;
			if (dot[i].x < bound[2].x)
				bound[2].x = dot[i].x;
			if (dot[i].x > bound[3].x)
				bound[3].x = dot[i].x;
		}
		U = bound[0].gety();//上
		D = bound[1].gety();//下
		L = bound[2].getx();//左
		R = bound[3].getx();//右
		origin_x = bound[2].x;//標記新原點
		origin_y = bound[1].y;
		BL = bound[3].x - bound[2].x;;
		BW = bound[0].y - bound[1].y;
	}
	void print_bound()
	{
		cout << " ( " << origin_x << "," << origin_y << " )  , " << BL << "," << BW << endl;
	}
};
class Test
{
public:

	void Test_XYboundCal()
	{
		XYboundCal WORK;
		Dot a(1, 1);
		Dot b(2, 2);
		Dot c(2, 5);
		Dot d(3, 9);
		Dot e(4, 0.5);


		WORK.pushXY(a);
		WORK.pushXY(b);
		WORK.pushXY(c);
		WORK.pushXY(d);
		WORK.pushXY(e);

		WORK.getBound();
		WORK.print_bound();
	}
};

class camView
{
public:
	double Hor_W, Hor_FOV, Hor_H, Hor_S, point_Horizontal_Angle;
	double point_Vertical_Angle;
	struct point
	{
		double x;
		double y;
		double z;
	}point;
	struct dot
	{
		double x;
		double y;
	}dot;
	camView()
	{

	}
	camView(double hor_w, double hor_fov)
	{
		Hor_W = hor_w;
		Hor_FOV = (hor_fov * pi) / 180;
		Hor_H = (cos(Hor_FOV / 2) / sin(Hor_FOV / 2)* Hor_W / 2);// Hor_H 為 CAM水平 到屏幕直線距離
		Hor_S = Hor_H / cos(Hor_FOV / 2);

		
	}
	
	void point_To_Angle(double X, double Y,double Z)
	{
		point.x = X;
		point.y = Y;
		point.z = Z;
		point_Horizontal_Angle = 124.7;// atan(point.y / point.x);
		point_Vertical_Angle = acos(point.z / sqrt(point.x*point.x+ point.y*point.y+ point.z+ point.z));
		//修正水平角度, 因 -M_PI_2 <= atan <= M_PI_2  >> 
		if (point.x < 0.0)
		{
			if (point.y < 0.0)
			{
				point_Horizontal_Angle -= pi;
			}
			else
			{
				point_Horizontal_Angle += pi;
			}
		}
		if (point_Horizontal_Angle > pi / 2)
		{
			point_Horizontal_Angle = point_Horizontal_Angle - pi / 2;
			dot.x = Hor_W / 2 - tan(point_Horizontal_Angle)*Hor_H;
		}
		else
		{
			if (point_Horizontal_Angle < pi / 2)
			{
				point_Horizontal_Angle=pi/2-point_Horizontal_Angle - (pi/2- Hor_FOV / 2);
				dot.x = Hor_W / 2 + tan(point_Horizontal_Angle)*Hor_H;

			}
		}
		cout << Hor_H << endl;
		cout << dot.x << endl << endl;
	}
	
};

int main()
{

	camView T1(1280, 80);
	cout << "1,1" << endl;
	T1.point_To_Angle(1, 1,0);
	cout <<"-1,1"<< endl;
	T1.point_To_Angle(-1, 1,0);


	system("pause");
	return 0;
}

