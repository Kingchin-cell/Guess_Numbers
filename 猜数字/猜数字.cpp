#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
int all_score = 0;
int left1 = 1, right1 = 100;
int zuo = 1, you = 100;
int select = 0, target;
void getScore()
{
	ifstream fr("积分.txt");
	if (fr)
	{
		fr >> all_score;
	}
	fr.close();
}
void putScore()
{
	ofstream fw("积分.txt");
	fw << all_score;
	fw.close();
}
void menu()
{
	system("cls");
	cout << "欢迎来到猜数字游戏，本游戏由柒开发" << endl;
	cout << "猜的次数越少积分越多，单次最多10积分，最少1积分" << endl;
	cout << "一次猜对获得10积分，两次猜对获得9积分，以此类推" << endl;
	cout << "当前拥有" << all_score << "积分" << endl;
	cout << "------------------------------------------" << endl;
}
void game()
{
	int count = 0;
	target = rand() % (you - zuo + 1) + zuo;
	while (1)
	{
		cout << "请输入" << zuo << "-" << you << "的数" << endl;
		int answer = 0;
		cin >> answer;

		if (answer > zuo && answer < target)
		{
			zuo = answer;
			cout << "在" << zuo << "到" << you << "之间" << endl;
			count++;
		}
		else if (answer > target && answer < you)
		{
			you = answer;
			cout << "在" << zuo << "到" << you << "之间" << endl;
			count++;
		}
		else if (answer == target)
		{
			cout << "猜对了,你猜了" << count << "次" << endl;
			int add = 10 - count + 1;
			if (add < 1) add = 1;
			all_score += add;
			cout << "本局获得" << add << "积分" << endl;
			putScore();
			int tmp = 0;
			while (tmp != 2)
			{
				cout << "要再来一次吗？" << endl;
				cout << "1.确认" << endl;
				cout << "2.取消并退出" << endl;
				cout << "3.查看当前积分" << endl;
				cin >> tmp;
				if (tmp == 1)
				{
					zuo = left1;
					you = right1;
					menu();
					game();
				}
				else if (tmp == 2)
				{
					exit(0);
				}	
				else if (tmp == 3)
				{
					cout << "当前拥有" << all_score << "积分" << endl;
					system("pause");
				}
				system("cls");
			}
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
			system("pause");
		}
		system("cls");
	}
}
int main()
{
	getScore();
	srand((unsigned)time(0));
	menu();
	cout << "1.开始游戏" << endl;
	cout << "2.高级设置" << endl;
	cout << "按下数字键并回车以执行对应操作" << endl;
	cin >> select;
	if (select == 1)
	{
		game();
	}
	else if (select == 2)
	{
		cout << "请输入猜数字游戏最小值(不可是负数哦）" << endl;
		cin >> left1;

		while (left1 < 0)
		{
			cout << "乱输入是吧？再给你一次机会" << endl;
			cout << "请输入最小值" << endl;
			cin >> left1;
			system("cls");
		}
		zuo = left1;
		cout << "请输入猜数字游戏最大值" << endl;
		cin >> right1;
		you = right1;
		menu();
		game();
	}
	else
	{
		cout << "输入有误,游戏结束" << endl;
	}
	return 0;
}
