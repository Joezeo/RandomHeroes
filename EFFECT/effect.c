/*
+
-             ���ߣ�Joezeo < joezeo@outlook.com >
+
-             ����ʱ�䣺2017.12.29 / 17��34
+
-             �޸�ʱ�䣺2017.12.29 / 17��34
+
-             �ļ����ƣ�effect.c
+
-             ģ�飺��Чģ�飬��Ч��ع���
+
-             ���ܣ���Чģ��ͷ�ļ���������������
+
*/

#include "effect.h"

/*
+
-			��������
+
*/

PCAPEFF
InitCoordSize() {

	PCAPEFF _pcapeff = (PCAPEFF)malloc(sizeof(CAPTURE_EFFECT));
	if (!_pcapeff)
		exit(OVERFLOW);

	FILE * _file = NULL;
	if (!fopen_s(&_file, "effect.txt", "r"))
		exit(FAILD);

	char _buf[16];
	int  n;

	for (int i = 0; i < 10; i++) {

		fgets(_buf, 16, (FILE *)_file);

		n = 100;
		for (int j = 0; j < 3; j++) {
		
			_pcapeff->m_bmpCoord[i].x += (*(_buf+ j) - 48) * n;
			n /= 10;

		}
		n = 100;
		for (int j = 4; j < 7; j++) {

			_pcapeff->m_bmpCoord[i].y += (*(_buf + j) - 48) * n;
			n /= 10;

		}
		n = 100;
		for (int j = 8; j < 11; j++) {

			_pcapeff->m_bmpSize[i].cx += (*(_buf + j) - 48) * n;
			n /= 10;

		}
		n = 100;
		for (int j = 12; j < 15; j++) {

			_pcapeff->m_bmpSize[i].cy += (*(_buf + j) - 48) * n;
			n /= 10;

		}

	}

	fclose(_file);

	return _pcapeff;

}
// CAPTURE_EFFECT�ص�������������ЧͼƬ��ȡ���꣬�ߴ����