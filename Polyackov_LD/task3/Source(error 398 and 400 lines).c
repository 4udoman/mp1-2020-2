/*����������� ���������, ����������� ���� ����� � �������.
���������� (�������)

	������ ��� ������ (������� � ���������).
	����� �������� ����� ������������� ����� � n (�� 2 �� 5).
	��������� ����������� n-������� ����� � ���������������� �������.
	����� ������ ������� �������� ����� � ������ n-������� ����� � ���������������� �������.
	��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� ����� (�� ���� ���������� �����) �
	������� ������� ������ �� ������� � ���������� ����� (�� ���� ���������� �����).
	����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������.

������

	����� n = 4.
	����� �������� ����� �3219�.
	����� ���� ����� �2310�.
	���������: ��� �������� (��� �����: �2� � �3� � ������� �� �������� ��������) � ���� ���� (���� ����� �1� ������� ������ �� �������).*/

	//����������� ��������� 
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
//������ �������
#define ARRAY_SIZE 5
#define MAX_INT

/*��� �������� ������. ������������ ����� �������. ������� ��� ����, ����� ����� ���� �������� ������� � ���������
����������� ���������� �������� ��� MAX_POP = 9*9*8*7*6 = 27216. ������������� �� ��������� ������ ��������*/
#define MAX_POP1 128
#define MAX_POP2 64
#define MAX_POP3 32
#define MAX_POP4 16
#define MAX_POP5 8
#define MAX_POP6 4
#define MAX_MAX_POP 6 //������� ����� MAX_POP ����������
int arrayofmaxpop[MAX_MAX_POP] = { MAX_POP1, MAX_POP2 ,MAX_POP3, MAX_POP4 , MAX_POP5, MAX_POP6 }; //���� ���-������ ���������, �� ���� ����� ����������� ����������

/*�� ������: ����� ��� ����� ���� ��������� � { }.
��� ������� ��� ��������, ������ ��� ������ ��������� ��������� �������� ����������� �����
� ��������������� �������� ������ �� ���, ��� ����� ���-�� ���������/������ */

//������� ��� �������� ���������� �������
int maxpopitok(int sloz, int n)
{
	int attempt = 0;
	switch (n)
	{
	case 2:
		attempt = arrayofmaxpop[n + sloz - 2];
		break;
	case 3:
		attempt = arrayofmaxpop[n + sloz - 3];
		break;
	case 4:
		attempt = arrayofmaxpop[n + sloz - 5];
		break;
	case 5:
		attempt = arrayofmaxpop[n + sloz - 6];
		break;
	}
	return(attempt);
}

//������� ��� ������ ���������
int slozhnost(int sloz)
{
	printf("��������� ���������: ");
	switch (sloz)
	{
	case 1:
	{
		printf("����� ����� (+2 ���� � ������ ��������, -1 � ������ ���������)\n");
		break;
	}
	case 2:
	{
		printf("����� (+4 ���� � ������ ��������, -2 � ������ ���������)\n");
		break;
	}
	case 3:
	{
		printf("��������� (+8 ����� � ������ ��������, -4 � ������ ���������)\n");
		break;
	}
	case 4:
	{
		printf("������ (+16 ����� � ������ ��������, -8 � ������ ���������)\n");
		break;
	}
	case 5:
	{
		printf("����� ������ (+32 ���� � ������ ��������, -16 � ������ ���������)\n");
		break;
	}
	default:
	{
		printf("\n������, ������� ������� �� �����������\n"); //�������� ����������������� ����
		break;
	}
	}
	return (0);
}

//������� ��� ������ �������
int terms(int sloz, int n, int rezhim)
{
	printf("��������� ������� %d-������� �����\n", n);
	if (rezhim == 2)
	{
		slozhnost(sloz);
		printf("���������� �������: %d\n", maxpopitok(sloz, n));
	}
}

//����� ������
int rule(int n)
{
	if ((n < 2) || (n > 5)) //��� ������� ����� �����, ����� ��������� � ������ ������ ������ �������, � ����� �������� ������ ��� �������� ���� � ������
		printf("������� ����:\n������ ��� ������ (������� � ���������).\n����� �������� ����� ������������� ����� � n (�� 2 �� 5).\n��������� ���������� n - ������� ����� � ���������������� �������.\n����� ������ ������� �������� ����� � ������ n-������� ����� � ���������������� �������.\n��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����\n(�� ���� ���������� �����) � ������� ������� ������ �� ������� � ���������� �����\n(�� ���� ���������� �����).\n����� ������ �������, ���� �� �������� ��� ������������������ ��� �� ������� \n(���� �� ������� ���������� ��� ����).");
	else
		printf("������ - ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����\n��� - ������� ���� ������� � ����������� � �� ��������� � ���������� �����\n");
}

//�������� ������� � ����� while � ������, ����� ��� ������� ����� � �����
int dostup(int pop, int maxpop, int rezhim)
{
	int dostup;
	if (rezhim == 1)
		dostup = 1; // ��� ��� ����������� ����� �������
	if ((rezhim == 2) && (pop < maxpop))
		dostup = 1; //��� ��� ��� ������� ������ ���������� ����������� �� ��������
	if ((rezhim == 2) && (pop >= maxpop))
		dostup = 0; //��� ��� ���������� ������� �������� ������������� ��������
	return(dostup);
}

//������� �������
void notmain()
{
	setlocale(LC_ALL, "Russian");

	//���������� ����������

	int rezhim; //������������� ������: �������/� �����������
	int sloz; // ����� ���������, ����� ������������ ���������� �������
	int score = 0; // ����������, ������� ����� ��������� ����� // ����� ����������� ����� ����, ����� ����� ���� ���������� ��� ���� �� ������ ����������, �� ����������� �� ����� ����� ��������
	int n; // ����� ������������� �����
	int mas[ARRAY_SIZE] = { 0 }; // ������ ��� �������� �����
	int polznum; //�����, �������� �������������
	int kolvopolzcifr; // ����� �����, ��������� �������������
	int polzmas[ARRAY_SIZE] = { 0 }; //���������������� ������ ����
	int maspop[MAX_INT] = { 0 }; //������ ���� �����, �������� ������������� (���� ��������� ����� ���� �� ����� � ��������, �� ���������� MAX_POP1)
	int popcow[MAX_INT] = { 0 }; //���������� ����� � ����� ��� ������ �� ������� (���� ��������� ����� ���� �� ����� � ��������, �� ���������� MAX_POP1)
	int popbik[MAX_INT] = { 0 };
	int i, j; //���������� ��� �����
	int bik; //���������� �����
	int cow; //���������� �����
	int pop; //���������� ������� �� ������ ������
	int maxpop; //������������ ���������� ������� ��� ��������� ���������
	int konec = 0; //���������� ��� ��������� ����� ��������� ����
	int vibor; //���������� ��� ������� ������� ������������

	while (konec != 333) //��� ��� ������ - 333
	{
		//������������� ���������
		{
			printf("� ���, � ������� ����� �������� � ���� \"���� � ������\"!\n");
			vibor = 0;
			n = 0;
			while ((vibor < 1) || (vibor > 3))
			{
				printf("�� ������:\n1.������� � ���� \"���� � ������\"\n2.������ ������� ����\n3.����� �� ����\n");
				scanf_s("%d", &vibor);
				if ((vibor < 1) || (vibor > 3))
				{
					printf("������ ������� �����������\n");
					continue;
				}
				if (vibor == 3)
				{
					konec = 1;
					polznum = 0;
					break;
				}
				if (vibor == 2)
				{
					rule(0);
					vibor = 0; //����� ����� ������� � ����� while 
					continue;
				}
				if (vibor == 1)
				{
					printf("������, ������� ��������� � ����\n");
					printf("��� ������ �������� ������:\n\t1.�����������\n\t2.� �������� ��������� � ������\n");
					/*��� ��������� ����� ���, ������ ��� � � ��������� ������ �������� ������� � �����, ��� ���������� �������
					������ ���� ������������ (���������� �������), ��� ��� ��� ����� ���� �������, ���� �� ������� ������� 2 ����� ���, ����� ��
					��������� �����, � �����. ������� ��� �����, ����� ��������� ���������� � �� ������� ��� ����� :)*/
					rezhim = 0;
					while ((rezhim < 1) || (rezhim > 2))
					{
						scanf_s("%d", &rezhim);
						if ((rezhim < 1) || (rezhim > 2))
						{
							printf("������ ����� �� ������������ ����������, ����������, ��������� �������\n");
							continue;
						}
					}
				}
			}

		}

		//����� �������� ��������� ���� � ����� ������������� ����� � n (�� 2 �� 5).
		{
			sloz = 0;
			n = 0;
			vibor = 0;
			if (konec != 1)
			{
				while (vibor != 1)
				{
					vibor = 0; //����� �������� ��� ����������, ����� ���� ������ ������� � �������
					while ((n < 2) || (n > ARRAY_SIZE))
					{
						printf("�������� ����� ������������� ����� (�� 2 �� 5)\n");
						scanf_s("%d", &n);
						if ((n < 2) || (n > ARRAY_SIZE))
							printf("������ ������� �����������\n");
					}
					system("cls");
					if (rezhim == 2)
					{
						while ((sloz < 1) || (sloz > 5))
						{
							printf("�������� ������� ���������:\n\t1.����� �����     (�������: %d, +2 ���� � ������ ��������, -1 � ������ ���������)\n\t2.�����           (�������: %d, +4 ���� � ������ ��������, -2 � ������ ���������)\n\t3.���������       (�������: %d, +8 ����� � ������ ��������, -4 � ������ ���������)\n\t4.������          (�������: %d, +16 ����� � ������ ��������, -8 � ������ ���������)\n\t5.����� ������    (�������: %d, +32 ���� � ������ ��������, -16 � ������ ���������)\n", maxpopitok(1, n), maxpopitok(2, n), maxpopitok(3, n), maxpopitok(4, n), maxpopitok(5, n));
							//����� ���� ����������� ����� �������, ����� ����� � ����� ���������� ����� ��, �� � ��������� �� ���� ���� ��-�� ����, ��� ����� � �������� � ��� ��������, � ������ ������������ �� �����
							scanf_s("%d", &sloz);
							if ((sloz < 1) || (sloz > 5))
							{
								system("cls");
								printf("������ ������� �����������\n");
								continue;
							}
							system("cls");
							//printf("%d\n", sloz);//�������� ����������������� ����
						}
					}
					while ((vibor < 1) || (vibor > 3))
					{
						if (rezhim == 1)
						{
							vibor = 1;
							system("cls");
							printf("����, ���� ���������:\n");
							terms(sloz, n, rezhim);
							break;
						}
						terms(sloz, n, rezhim);
						printf("\n�� �������� ��������� �������������?\n\t1.��, �� ����� ������ ������\n\t2.���, � �� ����� �������� ���������� ���� � �����\n\t3.���, � �� ����� �������� ���������\n");
						scanf_s("%d", &vibor);
						if ((vibor < 1) || (vibor > 3))
						{
							system("cls");
							printf("������ ������� �����������\n");
							continue;
						}
						if (vibor == 2)
						{
							n = ARRAY_SIZE + 1; //���������� ��������, ����� ������ ����� � ���� while ��� ������ ���������� ����
							system("cls");
							printf("������\n");
							continue;
						}
						if (vibor == 3)
						{
							sloz = 10; //���������� ��������, ����� ������ ����� � ���� while ��� ���������
							system("cls");
							printf("������\n");
							continue;
						}
						if (vibor == 1)
						{
							system("cls");
							printf("����, ���� ���������:\n");
							terms(sloz, n, rezhim);
						}
					}
				}
			}
		}

		//��������� ����������� n-������� ����� � ���������������� �������.
		{
			if (konec != 1)
			{
				srand(time(NULL));
				for (i = 0; i < n; i++)
				{
					if (i != 0)
					{
						mas[i] = rand() % 10; //�������� �����, ��������� ����� ������
					}
					else
					{
						mas[i] = rand() % 9 + 1; //�������� ������ ����� � ��������� �� 1 �� 9, ��� ����� ����� ����� �� ���������� � "0"
					}

					//printf("����� %d: %d\n", i+1, mas[i]); //�������� ����������������� ����

					for (j = 0; j < i; j++)
					{
						if (mas[i] == mas[j])
						{
							i--; //� ����� � ��� ����������� i++, ��� ������� �������� �������� i ���������� ��� ����� ���������
							break;
						}
					}
				}
			}
		}


		//��� ������������
		{
			if (konec != 1)
			{
				printf("��������� ������� �����: ");
				for (i = 0; i < n; i++)
					printf("%d", mas[i]);
				printf("\n");
			}
		}

		//����� ������ ������� �������� ����� � ������ n - ������� ����� � ���������������� �������. + ������� ����� � �����
		{
			if (konec != 1)
			{
				bik = 0;
				pop = 0;
				maxpop = maxpopitok(sloz, n);
				while ((bik != n) && (dostup(pop, maxpop, rezhim) == 1) && (konec != 1))
				{
					polznum = 0;
					while ((polznum < 1) || (polznum > 99999))
					{
						printf("������� ");
						if (pop != 0)
						{
							printf("����� ");
						}
						printf("%d-������� ����� ����� � ���������������� ������� (����� �������, ������� 1): ", n);
						scanf_s("%d", &polznum);
						if ((polznum < 1) || (polznum > 99999))
							printf("������ ������� �����������\n");
					}
					if (polznum == 1)
					{
						konec = 1;
						break;
					}
					maspop[pop] = polznum;
					//������ ������ �� ������, �������� �������������
					i = n - 1;
					kolvopolzcifr = 0;
					while (polznum > 0)
					{
						polzmas[i] = polznum % 10;
						//printf("����� %d: %d\n", i+1, polzmas[i]); //�������� ����������������� ����
						polznum = polznum / 10;
						//printf("���� �����: %d\n", polznum); //�������� ����������������� ����
						i--;
						kolvopolzcifr++;
					}
					if (kolvopolzcifr != n)
					{
						printf("�� ����� %d-������� ����� - ��� �� �������� %d-�������\n", kolvopolzcifr, n);
						continue;
					}
					bik = 0;
					cow = 0;
					for (i = 0; i < n; i++)
					{
						for (j = 0; j < n; j++)
						{
							if (mas[i] == polzmas[j])
							{
								if (i == j)
									bik++;
								else
									cow++;
							}
						}
					}
					//printf("���������� �����: %d\n", cow);//�������� ����������������� ����
					popcow[pop] = cow;     //������ � ���� ����������. ����� ������� - ������� ������� ������ ���������� �� ���, ��� �����
					//printf("���������� �����: %d\n", bik);//�������� ����������������� ����
					popbik[pop] = bik; //����� �������� � �� ����� ������� �������, �������� ����� ���� ��������� ��� (����� ����, �� ��� �������� ������� �����������, ��� � �� ������� ���������, ������� ��������� �������� ������� �����), ������� � ������ �������� ��� � ����� ����� ������� (��, ��-�� ����, ��� �� ���� ����������� ����� ������ �� ����� � ���� ������� - ��� �� ���� ��� ������������)
					pop++;
					system("cls"); //����� ���� ����������� ����� ������� � ���� ������� ���� �� ������� ������������, �� (����������� � ����������� ����), ������� ��� ������� �� ��� ��������
					terms(sloz, n, rezhim);
					rule(n);
					printf("\t���� �������:\n"); //� �� ���� ��������� � ������� ��������� ������ (������� ����� �������� �������������� �� ��� �������), ������� �� ���������� �������� ������� � ������� �������
					printf(" �������  ��������  �����  ����� \n");
					for (int i = 0; i < pop; i++)
					{
						printf("%5d %10d %6d %6d\n", i + 1, maspop[i], popcow[i], popbik[i]);
					}
				}
				if (bik == n)
				{
					printf("����������, �� �������� ���������� �����!\n");
					printf("����������� ����� �������: %d �� %d\n", pop, maxpop);
					printf("\t���� �������:\n"); //����� ��������� � �������, �� ��� ����� ����� �������� ��������� ������
					printf(" �������  ��������  �����  ����� \n");
					for (int i = 0; i < pop; i++)
					{
						printf("%5d %10d %6d %6d\n", i + 1, maspop[i], popcow[i], popbik[i]);
					}
					if (rezhim == 2)
					{
						switch (sloz)
						{
						case 1:
							score += 2;
							break;
						case 2:
							score += 4;
							break;
						case 3:
							score += 8;
							break;
						case 4:
							score += 16;
							break;
						case 5:
							score += 32;
							break;
						}
						printf("���������� ����� �� ������: %d", score);
						int maspop[MAX_INT] = { 0 };
						int popcowbik[MAX_INT][1] = { 0 };
					}
				}
				if (dostup(pop, maxpop, rezhim) == 1)
				{
					system("cls");
					if (rezhim != 1)
						printf("�� �������� ���������� ���������� ������� (%d) ��� ��������� (%d)!\n", maxpop, sloz);
					printf("��������� ������� �����: ");
					for (i = 0; i < n; i++)
						printf("%d", mas[i]);
					printf("\n");
					if (pop != 0)
					{
						printf("\t���� �������:\n"); //����� ��������� � �������, �� ��� ����� ����� �������� ��������� ������
						printf(" �������  ��������  �����  ����� \n");
						for (int i = 0; i < pop; i++)
						{
							printf("%5d %10d %6d %6d\n", i + 1, maspop[i], popcow[i], popbik[i]);
						}
					}
					printf("�� ���������������! � ��������� ��� � ��� ����� ���������!\n");
					if (rezhim != 1)
					{
						switch (sloz)
						{
						case 1:
							score -= 1;
							break;
						case 2:
							score -= 2;
							break;
						case 3:
							score -= 4;
							break;
						case 4:
							score -= 8;
							break;
						case 5:
							score -= 16;
							break;
						}
						printf("���������� ����� �� ������: %d\n", score);
					}

				}
			}
		}
		if ((konec == 1) && (polznum != 1))
		{
			printf("����� ����, ���� �� ���������� ������������ ����� ���������!\n");
			konec = 333; //��� ��� ������ �� ����������
		}
		else
		{
			vibor = 0;
			polznum = 0;//�� �������
			int maspop[MAX_INT] = { 0 }; //�� �������
			int popcowbik[MAX_INT][1] = { 0 }; //�� �������
			while ((vibor < 1) || (vibor > 2))
			{
				printf("�� ������ �������:\n\t1.�e������� � ����\n\t2.��������� ������ ����������\n");
				scanf_s("%d", &vibor);
				if ((vibor < 1) || (vibor > 2))
				{
					printf("������ ������� �����������\n");
					continue;
				}
				if (vibor == 1)
					konec = 0;
				if (vibor == 2)
					konec = 333; //��� ��� ������ �� ���������
			}
		}
	}
	system("pause");
}
