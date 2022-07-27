/*
  １．学籍番号：2001015569
  ２．氏    名：堀越 豪
  ３．先生へのメッセージ：改良した点、工夫した点など
	  - 意味のあるまとまりは関数として切り出して見通しをよくした（行目、〜行目）
		- ファイルの読み込みを行う際、ファイルが見つからない場合は再度メニューに戻るようにした。また、エラーであることと間違っている可能性のある部分を案内するようにした
		- define 文によって最大データ件数を変数で定義した。1箇所のみ書き換えることで最大データ件数を変更できる
		- 全データの表示を行う際、BMI も表示されるようにした。BMI の算出に math.h と pow 関数を使用した
		- 全データの表示を行う際、平均値に加えて最大値とその値をもつ人の名前を出力するようにした
		- 全データの表示を行う際、平均値に加えて最小値とその値をもつ人の名前を出力するようにした
*/

#include <stdio.h>
#include <math.h>

// 構造体定義の宣言
typedef struct Body
{
	char name[32];
	int age;
	double height;
	double weight;
} Body;

// 関数のプロトタイプ宣言
int print_bodydata(const Body *pData);
int input_bodydata(Body *pData);
FILE *open_file(char mode[]);
int navigate_operation_menu();

// 定数の宣言
#define MAX_FILE_NUM 100

int main(void)
{
	// 変数の宣言
	int i, rc = 0, cnt = 0;
	Body Data[MAX_FILE_NUM];
	FILE *fp;

	double sum_age = 0;
	double sum_height = 0;
	double sum_weight = 0;
	int max_age = 0;
	double max_height = 0;
	double max_weight = 0;
	char *max_age_name, *max_height_name, *max_weight_name;
	int min_age = 9999;
	double min_height = 9999;
	double min_weight = 9999;
	char *min_age_name, *min_height_name, *min_weight_name;

	while (1)
	{
		int menu = navigate_operation_menu();

		switch (menu)
		{
		case 1:
			// ファイルを開き 構造体配列に読み込む
			printf("\n=== ファイル読み込み ===\n");
			fp = open_file("r");
			if (fp == NULL)
			{
				printf("エラー: ファイルが見つかりません。入力されたファイル名に間違いがないか、ファイルが存在するか確認してください。\n");
				break;
			}
			for (i = 0; i < MAX_FILE_NUM; i++)
			{
				rc = fscanf(fp, "%s\t%d\t%lf\t%lf\r\n",
										Data[i].name, &Data[i].age, &Data[i].height, &Data[i].weight);
				if (rc == EOF)
					break;
			}

			cnt = i;
			printf("%d件のデータを読み込みました\n", cnt);
			fclose(fp);
			printf("ファイルを閉じました\n");

			break;
		case 2:
			printf("\n=== 全データ表示 ===\n");
			printf("名前\t\t年齢\t身長\t 体重\tBMI\n");
			// 構造体配列の内容を1件１行として画面に表示
			for (i = 0; i < cnt; i++)
			{
				print_bodydata(&Data[i]);

				// 平均値を算出するため、値を合計してもっておく
				sum_age += Data[i].age;
				sum_height += Data[i].height;
				sum_weight += Data[i].weight;

				//最大値を保持する
				if (max_age < Data[i].age)
				{
					max_age = Data[i].age;
					max_age_name = Data[i].name;
				}
				if (max_height < Data[i].height)
				{
					max_height = Data[i].height;
					max_height_name = Data[i].name;
				}
				if (max_weight < Data[i].weight)
				{
					max_weight = Data[i].weight;
					max_weight_name = Data[i].name;
				}

				//最小値を保持する
				if (min_age > Data[i].age)
				{
					min_age = Data[i].age;
					min_age_name = Data[i].name;
				}
				if (min_height > Data[i].height)
				{
					min_height = Data[i].height;
					min_height_name = Data[i].name;
				}
				if (min_weight > Data[i].weight)
				{
					min_weight = Data[i].weight;
					min_weight_name = Data[i].name;
				}
			}

			// データ件数と、それぞれの項目についての全件の平均値を表示
			printf("データの件数: %d\n", cnt);
			printf("年齢の平均: %.1f才\n", sum_age / cnt);
			printf("身長の平均: %.1fcm\n", sum_height / cnt);
			printf("体重の平均: %.1fkg\n", sum_weight / cnt);

			printf("年齢の最大: %d才 名前: %s\n", max_age, max_age_name);
			printf("身長の最大: %.1fcm 名前: %s\n", max_height, max_height_name);
			printf("体重の最大: %.1fkg 名前: %s\n", max_weight, max_weight_name);

			printf("年齢の最小: %d才 名前: %s\n", min_age, min_age_name);
			printf("身長の最小: %.1fcm 名前: %s\n", min_height, min_height_name);
			printf("体重の最小: %.1fkg 名前: %s\n", min_weight, min_weight_name);

			// 初期化
			sum_age = 0;
			sum_height = 0;
			sum_weight = 0;

			break;
		case 3:
			// 構造体配列に新データを追加する
			printf("\n=== 新データ入力 ===\n");
			if (cnt == MAX_FILE_NUM)
			{
				printf("最大件数（%d件）のため、データ入力できません\n\n", cnt);
				return -1;
			}
			input_bodydata(&Data[cnt]);
			printf("名前\t年齢\t身長\t 体重\n");
			print_bodydata(&Data[cnt]);
			cnt++;

			break;
		case 4:
			//  構造体配列の内容をファイルに書き出す
			printf("\n=== ファイル書き出し ===\n");
			fp = open_file("w");
			if (fp == NULL)
				return -1;
			for (i = 0; i < cnt; i++)
			{
				fprintf(fp, "%s\t%d\t%f\t%f\r\n", Data[i].name, Data[i].age,
								Data[i].height, Data[i].weight);
			}
			printf("%d件のデータをファイルへ書き出しました\n", cnt);
			fclose(fp);
			printf("ファイルを閉じました\n");

			break;
		default:
			// プログラムを終了
			return 0;
		}
	}
	return 0;
}

// 関 数 の 定義
FILE *open_file(char mode[])
{
	FILE *fp;
	char filename[32];
	printf("ファイル名を指定:");
	scanf("%s", filename);
	fp = fopen(filename, mode);
	if (fp == NULL)
	{
		printf("ファイルを開けませんでした\n");
		return NULL;
	}
	printf("ファイルを開きました\n");
	return fp;
}

int print_bodydata(const Body *pData)
{
	printf("%s\t", pData->name);
	printf("%d才\t", pData->age);
	printf("%.1fcm\t", pData->height);
	printf("%.1fkg\t", pData->weight);
	printf("%.1f\n", pData->weight / pow(pData->height / 100, 2));
	return 0;
}

int input_bodydata(Body *pData)
{
	printf("名前:");
	scanf("%s", pData->name);
	printf("年齢:");
	scanf("%d", &pData->age);
	printf("身長:");
	scanf("%lf", &pData->height);
	printf("体重:");
	scanf("%lf", &pData->weight);
	printf("\n");
	return 0;
}

int navigate_operation_menu()
{
	int menu;

	printf("\n=== 操作メニュー ===\n");
	printf("１：ファイル読み込み\n");
	printf("２：全データ表示\n");
	printf("３：新データ入力\n");
	printf("４：ファイル書き出し\n");
	printf("１～４以外：終了\n\n");

	printf("操作No の入力：");
	scanf("%d", &menu);
	printf("\n");

	return menu;
}