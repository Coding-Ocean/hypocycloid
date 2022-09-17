#include<vector>
#include"libOne.h"
void gmain()
{
	window(1920, 1080, full);
	//原点の位置
	float ox = width / 2;
	float oy = height / 2;
	//１とするドット数
	float unit = 50;
	//大きな円の半径
	float R = 6;
	//小さな円の半径と位置
	float r = R / 2.5f;
	float x = 0;
	float y = 0;
	//円を回す角度とスピード
	int T = 0;
	int S = 2;
	//円周上の１点
	float px = 0;
	float py = 0;
	//円を転がす角度
	float t = 0;
	//px,pyの履歴配列
	std::vector<float>apx;
	std::vector<float>apy;
	angleMode(DEGREES);
	while (notQuit)
	{
		//円の中心点を回す
		x = (R - r) * Cos(T);
		y = (R - r) * Sin(T);
		//円を転がした時の点の位置
		t = T * R / r;
		px = x+r * Cos(T - t);
		py = y+r * Sin(T - t);
		apx.push_back(px);
		apy.push_back(py);
		//中心点を回す角度の更新
		T += S;
		//pxが元の位置に戻ってきたらリセット
		if (T > 360 && R == px) {
			T = 0;
			apx.clear();
			apy.clear();
		}
		//ここから描画
		clear(200);
		mathAxis(ox, oy, unit, 200);
		//円と線
		fill(200);
		stroke(0);
		strokeWeight(3);
		mathCircle(0, 0, R * 2);
		mathCircle(x, y, r * 2);
		mathLine(0, 0, x, y);
		mathLine(x, y, px, py);
		//ハイポサイクロイド
		for (int i = 0; i < (int)apx.size() - 1; i++) {
			mathLine(apx[i], apy[i], apx[i + 1], apy[i + 1]);
		}
		//点
		strokeWeight(20);
		mathPoint(0, 0);
		mathPoint(x, y);
		mathPoint(px, py);
	}
}