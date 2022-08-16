/*
* đọc, ghi, thêm, ghép tập tin
*/

#include <stdio.h>
#include <stdlib.h>


int TaoTT(char* tentt) {
	FILE* fp;
	fp = fopen(tentt, "wt");
	if (fp != NULL) {
		fprintf(fp, "que huong la chum khe ngot\n");
		fprintf(fp, "cho con treo hai moi ngay\n");
		fclose(fp);
		return 1;
	}
	return 0;
}

int DocTT(char* tentt) {
	FILE *fp;
	char s[256];
	//int ret;
	fp = fopen(tentt,"rt");
	if (fp != NULL) {
		while (!feof(fp)) {
			if (fgets(s, 256, fp) != NULL)
				printf("%s", s);
		}
		fclose(fp);
		return 1;
	}
	return 0;
}

int ThemTT(char* tentt) {
	FILE* fp;
	char s[255];
	fp = fopen(tentt, "at");
	if (fp != NULL) {
		printf("\ninput data you want to add\n");
		for (int i = 0; i < 2; i++) {
			gets_s(s);
			fprintf(fp, "%s\n", s);
		}
		fclose(fp);
		return 1;
	}
	else
		return 0;
}

int GhepTapTin(char* tentt1, char* tentt2) {
	FILE* fp1, * fp2;
	char s[256];
	fp1 = fopen(tentt1, "at");
	fp2 = fopen(tentt2, "rt");
	if (fp1 == NULL && fp2 == NULL)
		return -2;//2 file lỗi
	else if (fp1 == NULL)
		return -1;//file 1 lỗi
	else if (fp2 == NULL)
		return -2;//file 2 lỗi
	else {
		while (!feof(fp2)) {
			if (fgets(s, 256, fp2) != NULL) {
				fprintf(fp1, "%s", s);
			}
		}
		fclose(fp1); fclose(fp2);
		return 1;
	}
}

void main() {
	char tenTapTin[255] = "test2.txt";
	char tenTapTin2[255] = "test1.txt";
	//tạo tập tin
	printf("\n-------Tao tap tin\n");
	int kp1 = TaoTT(tenTapTin);
	if (kp1 == 0)
		printf("khong tao duoc tap tin\n");
	else if (kp1 == 1)
		printf("tao duoc tap tin\n");

	//đọc tập tin đã tạo
	printf("\n-------Doc tap tin\n");
	int kp2 = DocTT(tenTapTin);
	if (kp2 == 0)
		printf("tap tin khong ton tai");

	//ghép tập tin 1, 2
	printf("\n-------Ghep tap tin\n");
	int kp3 = GhepTapTin(tenTapTin, tenTapTin2);
	if (kp3 == 1)
		printf("tap tin duoc ghep\n");

	//đọc lại tập tin sau ghép
	printf("\n-------Doc lai tap tin sau ghep\n");
	kp2 = DocTT(tenTapTin);
	if (kp2 == 0)
		printf("tap tin khong ton tai\n");

	//thêm vào tập tin
	printf("\n-------Them vao tap tin\n");
	ThemTT(tenTapTin);

	//đọc lại tập tin sau them
	printf("\n-------Doc lai tap tin sau them\n");
	kp2 = DocTT(tenTapTin);
	if (kp2 == 0)
		printf("tap tin khong ton tai\n");
}