int cnt = 0;
	Pos origin(0, 0);
	Pos LW(0, 0);
	Pos temp(0, 0);

	vector <Pos> bound;//UDLW 上下左右
	vector <Pos> dot;

	cout << "輸入幾組座標\n";
	cin >> cnt;

	
	for (int i = 0; i < cnt; i++)
	{
		temp.setPos();
		dot.push_back(temp);
		bound.push_back(temp);
	}

	for (int i = 0; i < dot.size(); i++)
	{
		cout << i + 1 << "." << "(" << dot[i].getx() << "," << dot[i].gety() << ")\n";
	}
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
	cout << "最高" << bound[0].gety() << endl;
	cout << "最低" << bound[1].gety() << endl;
	cout << "最左" << bound[2].getx() << endl;
	cout << "最右" << bound[3].getx() << endl;
	
	origin.x = bound[2].x;//標記新原點
	origin.y = bound[1].y;
	cout <<"Origin" << "(" << origin.getx() << "," << origin.gety() << ")\n";

	LW.x = bound[3].x - bound[2].x;
	LW.y = bound[0].y - bound[1].y;
	cout << "(長,寬)" << "(" << LW.getx() << "," << LW.gety() << ")\n";
