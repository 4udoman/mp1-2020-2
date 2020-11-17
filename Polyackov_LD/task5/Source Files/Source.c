/*����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� �����������/�������� �������.
������� ������:
    ���� �� ����������, � ������� ���������� ������������� ����������.
    ����� ����������.

�������� ������:
    ��������������� ������ ���� ������ � ��������� �������.
    ����� ����������.

��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������.
��������� ������ ������������� ������ � ������������� ����������� ����������, ������� ��������:
    ����������� ����� ���� �� ��������� ��������;
    ����������� ������ ������ ����������;
    ����������� ��������� ���������������� ������ ������ � ��������� �������.

C����� ������� ����������: ���������, �������, ���������, ��������, �����, �����, ���������
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  //�������� �� ������� ���� � ����� input output
#include <time.h>  
#include <string.h>
#include <locale.h>
#include <Windows.h> //���������� ����� ��� ��������� �������� ����� (���� ����������, �� ��� ����, ����� ������������ ��� ������� ����� � �������� �������)


#define SIZEOFARR 10000
#define SIZEOFPATH 256

//���������� �������
void menu();
int getinform(); //����������� ��������� ���������� �� ������
char preobr(char* path); //��������������� ����, �������� �������������, � ����, ������� ����� ���������
void bubblesort(int count); //���������� ���������
void selectsort(int count); //���������� �������
void insertsort(int count); //���������� ���������
void mergesort(int left, int right); //���������� ��������
void merge(int lefte, int right); 
void quicksort(int count); //�����=�������
int shellsort(long size);
int countingsort(int n, int k);
int choiceyoursort(int count);

void vozrastanie(int count); //���� ������������ ������ ���������� �� ��������, �� ��� ������� ���������� ������, ������� ��� ������������ �� ��������

//���������� ��������
struct finddata
{
    _fsize_t size;
    char name[FILENAME_MAX];
};

struct timer
{
    long long start; //����� ������ ����������
    double work; //����� ���������� 
};
        
//���������� ���������� ����������
struct  finddata c_file[SIZEOFARR]; //� ���� ������� ��������� ��� � ������ ��� ��������� �����
char realpath[SIZEOFPATH]; //������ �������� ���� ��� ������ ����� �� ���� �� ����� ����������
//struct  finddata dop_file[SIZEOFARR]; //�������������� ������

void main()
{
    setlocale(LC_ALL, "Russian"); //��������� �������� �����
    SetConsoleCP(1251); //��������� �������� ����� (����� ���� ����� ���� ������� ���������)
    SetConsoleOutputCP(1251); //��������� �������� ����� (����� ���� ����� ���� ������� ���������)
    menu();
    system("pause");
}//����������� ����� ���� ������ � ���� �������

void menu()
{
    printf("�����������! � - ���������, ��������� ��� ���������� ������. ��� ����������:\n(1) ������� ����������\n(2) �������� ���������� �� ������ � ����������\n(3) ������� ��� ����������, ���������� �� ����������\n(0) ����� �� ���������\n");
    int vibor = -1;
    char c;
    while ((vibor < 0) || (vibor > 3))
    {
        scanf_s("%d",&vibor);
        if ((vibor < 0) || (vibor > 3))
        {
            printf("������ ������� �� ������������� ����������. ������� ����� �� 0 �� 3.\n");
        }
    }
    c = getc(stdin);
    switch (vibor)
    {
    case 0:
        //����� �� ���������
        break;
    case 1:
        getinform();
        break;
    case 2:
        //�������� ���������� �� ������ � ����������
        break;
    case 3:
        //������� ��� ����������, ���������� �� ����������
        break;
    default:
        printf("������, ��������� � ������� � ����");
        break;
    }
}

int getinform()
{
    
    struct _finddata_t inf_file; //� ��� ��������� ����������� ��� ���������� �� ���������� �����
    intptr_t hFile;
    char path[SIZEOFPATH]; //����, ������� ��� ������������
    int count = 0; //������� ���������� ������

    printf("\n������� ���� � ����� � �������:\n");
    fgets(path, SIZEOFPATH, stdin); //scanf_s � ������ ������ ����� ��������� ������
    preobr(path); //�������������� ��� ���������
    //printf("��� �������� �������������. �������� ������ ������������� � %s\n", path); //��� �������� �������������

    if ((hFile = _findfirst(path, &inf_file)) == -1L) //��� ����� ���������� ����� ���� � ����� �������, � �� ����� � ����� ��� ������, ������ ��� � ����� ����� ���� ��� ����� . � ..
    {
        printf("�������� ���� ������� �����������!\n");
        getinform(); //������� ����� ��� ��������� ���������� �� ������, ������� ����� ���������� ������ ������ �� ��� ���, ���� �� ������ ������ ������
    }
    else //�������� �����, ���������� �� � ������ � ��������� ������ ������ �� ��������    
    {
        do {
            if (count > 1) //�.�. 0 � 1 ���� . � ..
            {
                c_file[count-2].size = inf_file.size;
                strcpy(c_file[count-2].name, inf_file.name);
            }
            count++;
        } while ((_findnext(hFile, &inf_file) == 0)&&(count<SIZEOFARR)); //���� ����� � ����� �� ��������
        _findclose(hFile);
        strcpy(realpath, path);
        count -= 2; //��� ��� � ����� ����� ���������� ������� ��� ����� . � ..
        if (count == 0)
        {
            printf("�� ����� ���� �� ������� �� ������ �����!\n"); //�� ������ ������������� �����, �� ������������ �� ����������, ��� � ����� ���������� ������� �����
            getinform(); //������� ����� ��� ��������� ���������� �� ������, ������� ����� ���������� ������ ������ �� ��� ���, ���� �� ������ ������ ������
        }
        else
        {
            choiceyoursort(count);
        }
    }
}

int choiceyoursort(int count)
{
    int vibor1 = 0, vibor2=0;
    int rezhim = 0;
    struct timer t;
    printf("�� ������ ������� �������� ����������:\n(1) �� �����������\n(2) �� ��������\n");
    while ((vibor1 < 1) || (vibor1 > 2))
    {
        scanf_s("%d", &vibor1);
        if ((vibor1 < 1) || (vibor1 > 2))
        {
            printf("������ �������� ���������� �� ������������ ����������. ������� ����� �� 1 �� 2.\n");
        }
    }
    printf("�� ������� ���������� �� ");
    if (vibor1 == 1)
    {
        printf("�����������\n");
    }
    else
    {
        printf("��������\n");
    }
    printf("�� ������ ������� ���� �� 7 ����������:\n(1) ���������\n(2) �������\n(3) ���������\n(4) ��������\n(5) �����\n(6) �����\n(7) ���������\n");
    while ((vibor2 < 1) || (vibor2 > 7))
    {
        scanf_s("%d", &vibor2);
        if ((vibor2 < 1) || (vibor2 > 7))
        {
            printf("������ ���������� �� ������������� ����������. ������� ����� �� 1 �� 7.\n");
        }
    }
    switch (vibor2)
    {
    case 1:
        t.start = clock(); //������ ������ ����������
        bubblesort(count);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //����� ������ ����������
        break;
    case 2:
        t.start = clock(); //������ ������ ����������
        selectsort(count);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //����� ������ ����������
        break;
    case 3:
        t.start = clock(); //������ ������ ����������
        insertsort(count);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //����� ������ ����������
        break;
    case 4:
        t.start = clock(); //������ ������ ����������
        mergesort(0, count-1);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //����� ������ ����������
        break;
    case 5:
        t.start = clock(); //������ ������ ����������
        quicksort(count);
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //����� ������ ����������
        break;
    case 6:
        t.start = clock(); //������ ������ ����������
        //
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //����� ������ ����������
        break;
    case 7:
        t.start = clock(); //������ ������ ����������
        //
        t.work = 1.0 * (clock() - t.start) / CLK_TCK; //����� ������ ����������
        break;
    }
    if (vibor1 == 1)
    {
        vozrastanie(count);
    }
    system("cls");
    printf("\n%23c������ ������\n\n����%50c������\n----%50c------\n", ' ', ' ', ' ');
    for (int i = 0; i < count; i++) //. � .. �������� 0 � 1 �������, ������� �������� �� ������� �������
    {
        printf("%-40s %14lu ����\n", c_file[i].name, c_file[i].size);
    }
    printf("\n\t����� ������: %d\n\t", count);
    if (t.work == 0)
        printf("���������� ��������� ������� ������, ������ ��� � ������ ���������� ����� ���� ������\n");
    else
    {
        printf("����� ����������: %f (���)\n\n", t.work);
    }
}

/*����������*/

//1. ���������
void bubblesort(int count)
{
    struct finddata dop_file; //�������������� ���������� ��� ������������

    for (int i = 0; i < count; i++) //. � .. �������� 0 � 1 �������, ������� �������� �� ������� �������
    {
        for (int j = count - 1; j > i; j--)
        {
            if (c_file[j - 1].size < c_file[j].size)
            {
                dop_file = c_file[j - 1];
                c_file[j - 1] = c_file[j];
                c_file[j] = dop_file;
            }
        }
    }
}

//2. �������
void selectsort(int count)
{
    struct finddata dop_file; //�������������� ���������� ��� ������������
    int i, j; //���������� ��� �����
    int k; //�������������� ���������� ��� ������������
    for (i = 0; i < count; i++)
    {
        k = i;
        dop_file = c_file[i];
        for (j = i + 1; j < count; j++)
        {
            if (c_file[j].size > dop_file.size)
            {
                k = j;
                dop_file = c_file[j];
            }
        }
        c_file[k] = c_file[i];
        c_file[i] = dop_file;
    }
}

//3. ���������
void insertsort(int count)
{
    struct finddata dop_file; //�������������� ���������� ��� ������������
    int j;
    for (int i = 0; i < count; i++)
    {
        dop_file = c_file[i];
        for (j = i - 1; (j >= 0) && (c_file[j].size < dop_file.size); j--)
        {
            c_file[j + 1] = c_file[j];
        }
        c_file[j + 1] = dop_file;
    }
} 

//4. ��������
void mergesort(int left, int right)
{
    int mid = (left + right) / 2;
    if (left == right)
    {
        return;
    }
    mergesort(left, mid);
    mergesort(mid + 1, right);
    merge(left, right);
}

void merge(int left, int right)
{
    //����� ���������� ���
    
}

//5. ����� = ������� ����������
void quicksort(int count)
{
    int i = 0, j = count - 1;
    struct finddata dop_file, midelem; //�������������� ���������� ��� ������������ � ������� �� ��������
    midelem = c_file[count >> 1];
    do
    {
        while (c_file[i].size < midelem.size)
        {
            i++;
        }
        while (c_file[j].size > midelem.size)
        {
            j--;
        }
        if (i <= j) 
        {
            dop_file = c_file[i]; 
            c_file[i] = c_file[j]; 
            c_file[j] = dop_file;
            i++; 
            j--;
        }
    } while (i <= j);
    if (j > 0) 
        quicksort(j);
    if (count > i) 
        quicksort(c_file + i, count - i);
}

//6. ���������� �����
int increment(long inc[], long size) 
{
    /*
    int p1, p2, p3, s;

    p1 = p2 = p3 = 1;
    s = -1;
    do {
        if (++s % 2) {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc[s] < size);

    return s > 0 ? --s : 0;
    */
}

//template<class T>
shellsort(long size) 
{
    /*
    long inc, i, j, seq[40];
    int s;

    // ���������� ������������������ ����������
    s = increment(seq, size);
    while (s >= 0) {
        // ���������� ��������� � ������������ inc[] 
        inc = seq[s--];

        for (i = inc; i < size; i++) {
            T temp = a[i];
            for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
                a[j + inc] = a[j];
            a[j + inc] = temp;
        }
    }
    */
}

//7. ���������� ���������
countingsort(int n, int k) 
{
    /* 
    int c[k + 1] = { 0 };
    for (int i = 0; i < n; i++) 
    {
        c[array[i]] = c[array[i]] + 1;
    }

    int b = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < c[i]; j++) 
        {
            array[b] = i;
            b = b + 1;
        }
    }
    */
}

//8. ���������� � �������� �������
void vozrastanie(int count)
{
    int n = count / 2; //����������, ������������ ������� ��������� � 1/2 ����� ����� �������
    struct finddata dop_file; //�������������� ���������� ��� ������������
    for (int i = 0; i < n; i++)
    {
        dop_file = c_file[i];
        c_file[i] = c_file[count - i - 1];
        c_file[count - i - 1] = dop_file;
    }
}

//9. �������������� 
char preobr(char* path)
{
    int size = 0; //������ ����
    size = strlen(path);
    if (size < 3)
    {
        printf("������� �������� ����!\n");
        getinform(); //������ ��� ����� ���� ������ ���������� ������� � ������ ������ �������� c:'\0'
    }
    if (path[size - 3] != '\\') //������� � ������ '/' ��� ���������
    {
        size++;
        path[size - 2] = '\\';
    }
    if (path[size - 2] != '*') //������� � ������ *, ����� � ���� ����� ��������� ��� �����
    {
        size++;
        path[size - 2] = '*';
    }
    path[size - 1] = '\0'; //�������� ������
    for (int i = 0; i < size; i++)
    {
        if (path[i] == '\\') //������ ������� '/' ('//') ��� ���������
        {
            i++; //����� ���������� ����������� '/'
            if (path[i] == path[i - 1]) //���� ��� ���������� ������� '/', �� ������ ����������� �� �����, ��������� �� ��������� ������
                continue;
            size++;
            for (int j = size - 1; j > i - 1; j--) //����� ��������� '/' ������� ��� ������� �� 1 ������, ��� ���� ����������� �������������� ������� �� ��������� '/'
            {
                path[j] = path[j - 1];
                //printf("%s\n", path); //��� �������� �������������
            }
        }
    }
}
