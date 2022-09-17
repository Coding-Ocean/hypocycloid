#include<vector>
#include"libOne.h"
void gmain()
{
	window(1920, 1080, full);
	//���_�̈ʒu
	float ox = width / 2;
	float oy = height / 2;
	//�P�Ƃ���h�b�g��
	float unit = 50;
	//�傫�ȉ~�̔��a
	float R = 6;
	//�����ȉ~�̔��a�ƈʒu
	float r = R / 2.5f;
	float x = 0;
	float y = 0;
	//�~���񂷊p�x�ƃX�s�[�h
	int T = 0;
	int S = 2;
	//�~����̂P�_
	float px = 0;
	float py = 0;
	//�~��]�����p�x
	float t = 0;
	//px,py�̗���z��
	std::vector<float>apx;
	std::vector<float>apy;
	angleMode(DEGREES);
	while (notQuit)
	{
		//�~�̒��S�_����
		x = (R - r) * Cos(T);
		y = (R - r) * Sin(T);
		//�~��]���������̓_�̈ʒu
		t = T * R / r;
		px = x+r * Cos(T - t);
		py = y+r * Sin(T - t);
		apx.push_back(px);
		apy.push_back(py);
		//���S�_���񂷊p�x�̍X�V
		T += S;
		//px�����̈ʒu�ɖ߂��Ă����烊�Z�b�g
		if (T > 360 && R == px) {
			T = 0;
			apx.clear();
			apy.clear();
		}
		//��������`��
		clear(200);
		mathAxis(ox, oy, unit, 200);
		//�~�Ɛ�
		fill(200);
		stroke(0);
		strokeWeight(3);
		mathCircle(0, 0, R * 2);
		mathCircle(x, y, r * 2);
		mathLine(0, 0, x, y);
		mathLine(x, y, px, py);
		//�n�C�|�T�C�N���C�h
		for (int i = 0; i < (int)apx.size() - 1; i++) {
			mathLine(apx[i], apy[i], apx[i + 1], apy[i + 1]);
		}
		//�_
		strokeWeight(20);
		mathPoint(0, 0);
		mathPoint(x, y);
		mathPoint(px, py);
	}
}