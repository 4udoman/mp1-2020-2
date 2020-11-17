/*����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� �����������/�������� �������.
������� ������:
    + ���� �� ����������, � ������� ���������� ������������� ����������.
    + ����� ����������.

�������� ������:
    + ��������������� ������ ���� ������ � ��������� �������.
    + ����� ����������.

��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������.
��������� ������ ������������� ������ � ������������� ����������� ����������, ������� ��������:
    + ����������� ����� ���� �� ��������� ��������;
    + ����������� ������ ������ ����������;
    + ����������� ��������� ���������������� ������ ������ � ��������� �������.

C����� ������� ����������: ���������, �������, ���������, ��������, �����, �����, ���������
*/

#define _CRT_SECURE_NO_WARNINGS

//����������� ���������
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  //�������� �� ������� ���� � ����� input output
#include <omp.h>  
#include <string.h>
#include <locale.h>
#include <Windows.h> //���������� ����� ��� ��������� �������� ����� (���� ����������, �� ��� ����, ����� ������������ ��� ������� ����� � �������� �������)

//��������, ���������� ���������� ����������
typedef struct finddata
{
    _fsize_t size;
    char name[FILENAME_MAX];
} structinf;

//���������� �������
int menu();
int getinform(); //����������� ��������� ���������� �� ������
char preobr(char* path); //��������������� ����, �������� �������������, � ����, ������� ����� ���������
void bubblesort(int count, structinf* c_file); //���������� ���������
void selectsort(int count, structinf* c_file); //���������� �������
void insertsort(int count, structinf* c_file); //���������� ���������
void mergesort(int left, int right, structinf* c_file); //���������� ��������
void merge(int lefte, int right, structinf* c_file);
void quicksort(structinf* c_file, int count); //�����=�������
int shellsort(long size, structinf* c_file);
int countingsort(int n, int k, structinf* c_file);
int choiceyoursort(int count, structinf* c_file);
void vozrastanie(int count, structinf* c_file); //���� ������������ ������ ���������� �� ��������, �� ��� ������� ���������� ������, ������� ��� ������������ �� ��������
void instruction(); // ���������� � ���������
void fullvivod(); //����� ���������� �� ���� �����������
void printgran(int type, int i); //������ �����
void polzsort(int i); //������� �� ����� ��������� ������������� ���������� (��� ������� � ������ �� ����� ����)

//////////////////////////////////////////////////////////////////////////////////////
void ClearScreen(int y); //����� �� ��������� https://stackoverrun.com/ru/q/1628655 //
//////////////////////////////////////////////////////////////////////////////////////


//���������� ���������� ����������
char lastpath[FILENAME_MAX]; //������ �������� ���� ��� ������ ����� �� ���� �� ����� ����������

void main()
{
    int vixod = -1;
    setlocale(LC_ALL, "Russian"); //��������� �������� �����
    SetConsoleCP(1251); //��������� �������� ����� (����� ���� ����� ���� ������� ���������)
    SetConsoleOutputCP(1251); //��������� �������� ����� (����� ���� ����� ���� ������� ���������)
    printf(" �����������! � - ���������, ��������� ��� ���������� ������.\n");
    while (vixod != 0)
    {
        vixod = menu();
    }
    printgran(1, 73);
    printf("| �� ��������� ��� ���������� ����� ���������, ������� �� ������������! |\n");
    printgran(1, 73);
    system("pause");
}

int menu()
{
    printgran(1, 61);
    printf("  ������ �� ���������� � ����. ��������, ��� ����� �������:\n\t(1) ������������� ����� � ����� �����\n\t(2) ������� ��� ����������, ���������� �� ����������\n\t(3) �������� ���������� �� ������ � ����������\n\t(0) ����� �� ���������\n");
    printgran(1, 61);
    int vibor = -1;
    char c;
    while ((vibor < 0) || (vibor > 3))
    {
        scanf_s("%d", &vibor);
        if ((vibor < 0) || (vibor > 3))
        {
            printf("������ ������� �� ������������� ����������. ������� ����� �� 0 �� 3.\n");
        }
    }
    ClearScreen(0);
    c = getc(stdin); //������� ������ �����
    switch (vibor)
    {
    case 1:
        getinform();
        break;
    case 2:
        fullvivod();
        break;
    case 3:
        instruction();
        break;
    case 0:
        return 0;
    default:
        printf("������, ��������� � ������� � ����");
        break;
    }
}

int getinform()
{
    structinf* c_file; //� ���� ������� ��������� ��� � ������ ��� ��������� �����
    struct _finddata_t inf_file; //� ��� ��������� ����������� ��� ���������� �� ���������� �����
    intptr_t hFile;
    char path[FILENAME_MAX]; //����, ������� ��� ������������
    int count = 0; //������� ���������� ������

    printf("\n ������� ���� � ����� � �������:\n");
    fgets(path, FILENAME_MAX, stdin); //scanf_s � ������ ������ ����� ��������� ������
    ClearScreen(0);
    printf("\n �� ����� ����: %s\n", path);
    preobr(path); //�������������� ��� ���������
    //printf("��� �������� �������������. �������� ������ ������������� � %s\n", path); //��� �������� �������������
    if ((hFile = _findfirst(path, &inf_file)) == -1L) //��� ����� ���������� ����� ���� � ����� �������, � �� ����� � ����� ��� ������, ������ ��� � ����� ����� ���� ��� ����� . � ..
    {
        printf(" �������� ���� ������� �����������!\n");
        getinform(); //������� ����� ��� ��������� ���������� �� ������, ������� ����� ���������� ������ ������ �� ��� ���, ���� �� ������ ������ ������
    }
    else //�������� ������� ������ � ����������, ����� �������� ������ ���������� ������ ��� ����� � �������    
    {
        do
        {
            count++;
        } while (_findnext(hFile, &inf_file) == 0); //���� ����� � ����� �� ��������
        _findclose(hFile);
    }
    count -= 2;
    c_file = (structinf*)malloc(count * sizeof(structinf));
    if (c_file == NULL)
    {
        printf(" ������� ����� ������ � ����������! ���������� �������� ������ ���������� ������ ��� �������� ����������.\n");
        getinform();
    }
    count = 0;
    hFile = _findfirst(path, &inf_file);
    do
    {
        if (count > 1) //�.�. 0 � 1 ���� . � ..
        {
            c_file[count - 2].size = inf_file.size;
            strcpy(c_file[count - 2].name, inf_file.name);
        }
        count++;
    } while (_findnext(hFile, &inf_file) == 0); //���� ����� � ����� �� ��������
    _findclose(hFile);
    strcpy(lastpath, path);
    count -= 2; //��� ��� � ����� ����� ���������� ������� ��� ����� . � ..
    if (count == 0)
    {
        printf(" �� ����� ���� �� ������� �� ������ �����!\n"); //�� ������ ������������� �����, �� ������������ �� ����������, ��� � ����� ���������� ������� �����
        getinform(); //������� ����� ��� ��������� ���������� �� ������, ������� ����� ���������� ������ ������ �� ��� ���, ���� �� ������ ������ ������
    }
    else
    {
        choiceyoursort(count, c_file);
    }
}

int choiceyoursort(int count, structinf* c_file)
{
    int vibor[3] = { 0 };
    long double t[2] = { 0 };
    printf(" �� ������ ������� �������� ����������:\n\t(1) �� �����������\n\t(2) �� ��������\n");
    while ((vibor[0] < 1) || (vibor[0] > 2))
    {
        scanf_s("%d", &vibor[0]);
        if ((vibor[0] < 1) || (vibor[0] > 2))
        {
            printf(" ������ �������� ���������� �� ������������ ����������. ������� ����� �� 1 �� 2.\n");
        }
    }
    ClearScreen(3);
    printf(" �� ������� ���������� �� ");
    if (vibor[0] == 1)
    {
        printf("�����������\n");
    }
    else
    {
        printf("��������\n");
    }
    printf("\n �� ������ ������� ���� �� 7 ����������:\n\t(1) ���������\n\t(2) �������\n\t(3) ���������\n\t(4) ��������\n\t(5) �����\n\t(6) �����\n\t(7) ���������\n");
    while ((vibor[1] < 1) || (vibor[1] > 7))
    {
        scanf_s("%d", &vibor[1]);
        if ((vibor[1] < 1) || (vibor[1] > 7))
        {
            printf(" ������ ���������� �� ������������� ����������. ������� ����� �� 1 �� 7.\n");
        }
    }
    ClearScreen(5);
    printf(" ��������� ����������: \"");
    polzsort(vibor[1]);
    printf("\"\n");
    switch (vibor[1])
    {
    case 1:
        t[0] = omp_get_wtime();
        bubblesort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 2:
        t[0] = omp_get_wtime();
        selectsort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 3:
        t[0] = omp_get_wtime();
        insertsort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 4:
        t[0] = omp_get_wtime();
        mergesort(0, count - 1, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 5:
        t[0] = omp_get_wtime();
        quicksort(count, c_file);
        t[1] = omp_get_wtime() - t[0];
        break;
    case 6:
        t[0] = omp_get_wtime();
        //
        t[1] = omp_get_wtime() - t[0];
        break;
    case 7:
        t[0] = omp_get_wtime();
        //
        t[1] = omp_get_wtime() - t[0];
        break;
    default:
        printf(" ������, ��������� � ������� � ����������\n");
        break;
    }
    if (vibor[0] == 1)
    {
        vozrastanie(count, c_file);
    }
    printf("\n ����� ������: %d\n\n", count);
    if (t[1] == 0)
        printf(" ���������� ��������� ������� ������, ������ ��� � ������ ���������� ����� ���� ������\n");
    else
    {
        printf(" ����� ����������: %.7lf (���)\n\n", t[1]);
    }
    printf(" ��� ����� �������?\n\t(1)������� ��������������� �����\n\t(2)��������� � ����\n");
    while ((vibor[2] < 1) || (vibor[2] > 7))
    {
        scanf_s("%d", &vibor[2]);
        if ((vibor[2] < 1) || (vibor[2] > 7))
        {
            printf(" ������ ����� �� ������������ ����������. ������� 1 ��� 2.\n");
        }
    }
    ClearScreen(11);
    if (vibor[2] == 1)
    {
        printgran(1, 60);
        printf("%23c������ ������\n", ' ');
        printgran(1, 60);
        printf("����%50c������\n", ' ');
        printgran(1, 60);
        for (int i = 0; i < count; i++) //. � .. �������� 0 � 1 �������, ������� �������� �� ������� �������
        {
            printf("%-40s %14lu ����\n", c_file[i].name, c_file[i].size);
        }
    }
    printf("� ������� ����� �������� ����������� ����� ���������\n");//�� ������
    system("pause");
    free(c_file);
    system("cls");
}

/*����������*/

//1. ���������
void bubblesort(int count, structinf* c_file)
{
    structinf dop_file; //�������������� ���������� ��� ������������

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
void selectsort(int count, structinf* c_file)
{
    structinf dop_file; //�������������� ���������� ��� ������������
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
void insertsort(int count, structinf* c_file)
{
    structinf dop_file; //�������������� ���������� ��� ������������
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
void mergesort(int left, int right, structinf* c_file)
{
    int mid = (left + right) / 2;
    if (left == right)
    {
        return;
    }
    mergesort(left, mid, c_file);
    mergesort(mid + 1, right, c_file);
    merge(left, right, c_file);
}

void merge(int left, int right, structinf* c_file)
{
    //����� ���������� ���
    int mid = (left + right) / 2;
    int i = 0, k = 0; //��������
    int j = mid + 1; //�������
    structinf* dop_file; //�������������� ���������� ��� ������������
    dop_file = (structinf*)malloc(right*sizeof(structinf));
    for (k = left; k <= right; k++)
    {
        if ((i < mid) && (j < right))
        {
            if (c_file[i].size <= c_file[j].size)
            {
                dop_file[k] = c_file[i];
                i++;
            }
            else
            {
                dop_file[k] = c_file[j];
                j++;
            }
        }
        else
        {
            if (i == mid)
            {
                for (; j < right; j++, k++)
                {
                    dop_file[k] = c_file[j];
                }
            }
            else
            {
                for (; i < mid; i++, k++)
                {
                    dop_file[k] = c_file[i];
                }
            }
        }
    }
    for (k = left; k <= right; k++)
    {
        c_file[k] = dop_file[k];
    }
    free(dop_file);
}

//5. ����� = ������� ����������
void quicksort(structinf* c_file, int count)
{
    int i = 0, j = count - 1;
    structinf dop_file, midelem; //�������������� ���������� ��� ������������ � ������� �� ��������
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
        quicksort(c_file, j);
    if (count > i)
        quicksort(c_file + i, count - i);
}

//6. ���������� �����
int increment(long inc[], long size, structinf* c_file)
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

shellsort(long size, structinf* c_file)
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
countingsort(int n, int k, structinf* c_file)
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
void vozrastanie(int count, structinf* c_file)
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

//������������� ���� ��� ���������
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

// ���������� � ���������
void instruction() 
{
    printf("����� � ���������.\n");
}

//����� ���������� �� ���� �����������
void fullvivod()
{
    printf("����� � ���������.\n");
}

//������ �����
void printgran(int type, int i)
{
    if (type == 1)
    {
        for (int j = 0; j < i; j++)
            printf("-");
    }
    printf("\n");
}

//���������� ��������� ����������
void polzsort(int i)
{
    switch (i)
    {
    case 1:
        printf("���������");
        break;
    case 2:
        //
        printf("�������");
        break;
    case 3:
        //
        printf("���������");
        break;
    case 4:
        //
        printf("��������");
        break;
    case 5:
        //
        printf("�����");
        break;
    case 6:
        //
        printf("�����");
        break;
    case 7:
        //
        printf("���������");
        break;
    default:
        printf("����� ���������� ���\n");
        break;
    }
}

void ClearScreen(int y)
{
    //����� �� ���������
    //https://stackoverrun.com/ru/q/1628655

    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = { 0, y };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}