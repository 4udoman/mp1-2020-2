/*����� ������� ����� ��������� ����������� ������� �����.
������ �����:

    -��������� ������ ������ �� ��� ������� h �� 180 �� 220 ��, ������� w �� 80 �� 120 �� � �������� 5 ��,
    -��� �������� �� ��� ������� h, �������� d �� 50 �� 90 �� � �������� 15 ��,
    -��������� ������� � ������ ������ �� ��� ������� w, �������� d � �������� 15 ��,
    -��� ��������� ����� �� ������ ������� h, ����� ������� w � �������� 1 ��,
    -���������� ����� � ����� ����� ������ 40 �� �� ��� - 15 ��.

������, ��� �������� ��������� ���, ��� � ������, ����� ����� ����� � �����������.*/

#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "Russian");
	const float p1 = 820; //��������� ��� � ��/�^3
    const float p2 = 720; //��������� ��� � ��/�^3
    const float p3 = 810; //��������� ������ � ��/�^3
    const float th1 = 0.005; //������� ��������� ������ ������ � ������
    const float th2 = 0.015; //������� ������� � ������
    const float th3 = 0.015; //������� ������� � ������ ������ � ������
    const float th4 = 0.01; //������� ������ � ������
    const float th5 = 0.015; //������� ����� � ������
    const float l = 0.4;

    int k; //���������� �����
    float v1; //����� ��������� ������ ������ (� ������ ����������) �� ���
    float v2; //����� ������� (� ������ ����������)
    float v3; //����� ������� � ������ ������ (� ������ ����������)
    float v4; //����� ������ (� ������ ����������)
    float v5; //����� ����� (� ������ ����������)
    float m;  //����� ����� � �����
    float h; //������ �����
    float w; //������ �����
    float d; //������� �����

    h = 0;
    w = 0;
    d = 0;
   
 //���� ������
    
    printf("��������! ���� ������� ����� ������������ � �������������� �������. ��������: 1,45\n");
    printf("������� �������� h (������ ����� �� 180 �� 220 ��)\n");
    while ((h < 180) || (h > 220)) //h (�� 180 �� 220 ��)
    {
        scanf_s("%f", &h);
        if ((h < 180) || (h > 220))
        {
            printf("������, �� ��������� ������� 180<=h<=220\n");
            continue;
        }
    }
    printf("������� �������� w (������ ����� �� 80 �� 120 ��)\n");
    while ((w < 80) || (w > 120)) //w (�� 80 �� 120 ��)
    {
        scanf_s("%f", &w);
        if ((w < 80) || (w > 120))
        {
            printf("������, �� ��������� ������� 80<=w<=120\n");
            continue;
        }
    }
    printf("������� �������� d (������� ����� �� 50 �� 90 ��)\n");
    while ((d < 50) || (d > 90)) //d (�� 50 �� 90 ��)
    {
        scanf_s("%f", &d);
        if ((d < 50) || (d > 90))
        {
            printf("������, �� ��������� ������� 50<=d<=90\n");
            continue;
        }
    }
    
 //����� ������ ���������� 1 �����
    system("cls");
    printf("������ ����� = %f", h);
    printf(" ��");
    printf("\n������ ����� = %f", w);
    printf(" ��");
    printf("\n������� ����� = %f", d);
    printf(" ��");

 //������� � �����
    
    h = h / 100; //������� �� � �����
    w = w / 100; //������� �� � �����
    d = d / 100; //������� �� � �����
    
 //������ ������� ����� � �����
 /*� ����� ��������� ����� ���-�� �����, ��� ��� ����� ����� �� ������� �������� ������,
 � ������� ��� ����� ���������, �� ���������� ����� ����� �������, ���������� � �������� ����� */
    k = (h - 2*th3) / (l + th5); 

 //���������� ������ 
 //����� = ������ * ������ * �������

    v1 = h * w * th1; //����� ��������� ������ ������
    //������ ����� - h. ������ ������� ����� ������ �� �������� 2*th3, ��� ��� �������� �� ������� ����������� � ����.
    v2 = 2 * ((h - 2 * th3) * d * th2); //����� ����� ���� ������� (���������� ��������)
    v3 = 2 * d * w * th3; //����� ����� ���� ������ (���������� ��������)
    v4 = h * w * th4; //����� ����� ���� ������ (���������� ��������)
    //������� � ����� ������� ����������, � ��� ������ ����������� �� �������� 2*th2, ��� ��� ����� �� ������� ����������� � ����.
    v5 = k*d*(w-2*th2)*th5; //����� ����� k ���� �����

 //��������� ������������ �����
 //m=p*v
 //m = m1 + m2 + m3 + m4 + m5
 //��� (p1): ��������� ������ ������ (v1)
 //��� (p2): ��� �������� (v2), ��������� ������� � ������ ������ (v3), ���������� ����� � ����� (v5)
 //������ (p3): ��� ��������� ����� (v4)
    m = p1 * v1 + p2 * v2 + p2 * v3 + p2 * v5 + p3 * v4;

//����� ������ ���������� 2 �����
    printf("\n���������� ����� = %d", k);
    if (k == 4)
    {
        printf(" �����");
    }
    else
    {
        printf(" ����");
    } //��� ��� ��������� � ���� ������ � ��� ����� ���� ���-�� ����� ������ 4 ��� 5, �� � ��������� ����� printf ��� ������������� ��/�� �����
    printf("\n����� ����� = %f", m);
    printf(" ��");

    printf("\n\n��������� ��������� ���� ������.\n");
    system("pause");

}
