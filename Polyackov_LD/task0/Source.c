//����������, ������ �������� ������������ ���� ����������� �� ��������� � ��������� ������������ ������� � ���������. 
//�������� ������ ������ ��������� �������������. ��������� ��������� ������ �������� �� �����.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void main()
{
	//����������� ����� ������ ����������
	float xone, yone, rone, xtwo, ytwo, rtwo;//x1, y1 - ���������� ������ ���������� 1; x2, y2 - ���������� ������ ���������� 2; r1 � r2 - ������� ��������������� �����������;
	printf("Enter the coordinates of the center (x1;y1) of the first circle\n\t");
	scanf("%f %f",&xone,&yone);
	printf("Enter the radius of the first circle (necessarily >=0)\n\t");
	scanf("%f",&rone);
	printf("Enter the coordinates of the center (x2;y2) of the second circle\n\t");
	scanf("%f %f",&xtwo,&ytwo);
	printf("Enter the radius of the se�ond circle (necessarily >=0)\n\t");
	scanf("%f",&rtwo);

	//��������� ���������� ����������
	
	//0 ���� - ������ ���������� �����������
	if ((xone==xtwo)&&(yone==ytwo)&&(rone==rtwo))
		{
		printf("Both circles are equal");
		goto l;
		}
	//1 ���� - �������� �� ���������� �������
	if ((rone+rtwo)==sqrt((xone-xtwo)* (xone - xtwo)+(yone - ytwo)(yone - ytwo)))
	//2 ���� - ���� ������� ����, �� �������� �� ������������ ���������� � ������ ���������� / �������� �� ������������ � ������ ������ ������������ ���� �����

	//3 ���� - ���� ������� ����, �� �������� �������� � ����������� �������

	//4 ���� - ���� ������� ���, �� ���������� ������ ������������
l:	scanf("%f",&xone);
}