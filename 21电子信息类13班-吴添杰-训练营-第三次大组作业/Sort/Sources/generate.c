#include "../Headers/sort.h"

/**
 * @brief : ��Ҫ�����ɲ������ɲ������ݲ����浽�ļ�
 *
 */

#define Data_1 10000
#define Data_2 50000
#define Data_3 200000
#define Max 1000

void show()
{
    printf("\t******��ѡ�����ɲ��Գ���******\n");
    printf("\t1.����%d��0~%d�������\n", Data_1, Max);
    printf("\t2.����%d��0~%d�������\n", Data_2, Max);
    printf("\t3.����%d��0~%d�������\n", Data_3, Max);
    printf("\t���������ѡ��: ");
}

void choiceWrite(int c, FILE *fp)
{
    int num;
    switch (c)
    {
    case 1:
        fp = fopen("testData.txt", "w");
        for (int i = 1; i < Data_1; i++)
        {
            num = rand() % Max;      // ���������
            fprintf(fp, "%d ", num); // ������ļ�
        }
        fclose(fp);
        printf("\t�Ѿ��ɹ���txt�ļ�������%d��0~%d�������\n", Data_1, Max);

        break;

    case 2:
        fp = fopen("testData.txt", "w");
        for (int i = 1; i < Data_2; i++)
        {
            num = rand() % Max;      // ���������
            fprintf(fp, "%d ", num); // ������ļ�
        }
        fclose(fp);
        printf("\t�Ѿ��ɹ���txt�ļ�������%d��0~%d�������\n", Data_2, Max);
        break;

    case 3:
        fp = fopen("testData.txt", "w");
        for (int i = 1; i < Data_3; i++)
        {
            num = rand() % Max;      // ���������
            fprintf(fp, "%d ", num); // ������ļ�
        }
        fclose(fp);
        printf("\t�Ѿ��ɹ���txt�ļ�������%d��0~%d�������\n", Data_3, Max);
        break;

    default:
        printf("\t����ѡ��\n");
        break;
    }
}

int main()
{
    system("cls");
    /* ��ʼ������������� */
    srand((unsigned int)time(NULL));
    FILE *fp;
    int choice;
    show();
    scanf("%d", &choice);
    choiceWrite(choice, fp);
    printf("\t�����˳�. . .\n\t");
    system("pause");

    return 0;
}
