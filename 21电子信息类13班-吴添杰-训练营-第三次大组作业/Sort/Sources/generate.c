#include "../Headers/sort.h"

/**
 * @brief : 按要求生成测试生成测试数据并保存到文件
 *
 */

#define Data_1 10000
#define Data_2 50000
#define Data_3 200000
#define Max 1000

void show()
{
    printf("\t******请选择生成测试程序******\n");
    printf("\t1.生成%d个0~%d的随机数\n", Data_1, Max);
    printf("\t2.生成%d个0~%d的随机数\n", Data_2, Max);
    printf("\t3.生成%d个0~%d的随机数\n", Data_3, Max);
    printf("\t请输入你的选择: ");
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
            num = rand() % Max;      // 产生随机数
            fprintf(fp, "%d ", num); // 输出到文件
        }
        fclose(fp);
        printf("\t已经成功在txt文件中生成%d个0~%d的随机数\n", Data_1, Max);

        break;

    case 2:
        fp = fopen("testData.txt", "w");
        for (int i = 1; i < Data_2; i++)
        {
            num = rand() % Max;      // 产生随机数
            fprintf(fp, "%d ", num); // 输出到文件
        }
        fclose(fp);
        printf("\t已经成功在txt文件中生成%d个0~%d的随机数\n", Data_2, Max);
        break;

    case 3:
        fp = fopen("testData.txt", "w");
        for (int i = 1; i < Data_3; i++)
        {
            num = rand() % Max;      // 产生随机数
            fprintf(fp, "%d ", num); // 输出到文件
        }
        fclose(fp);
        printf("\t已经成功在txt文件中生成%d个0~%d的随机数\n", Data_3, Max);
        break;

    default:
        printf("\t错误选项\n");
        break;
    }
}

int main()
{
    system("cls");
    /* 初始化随机数发生器 */
    srand((unsigned int)time(NULL));
    FILE *fp;
    int choice;
    show();
    scanf("%d", &choice);
    choiceWrite(choice, fp);
    printf("\t即将退出. . .\n\t");
    system("pause");

    return 0;
}
