#include <stdio.h>
#include <string.h>

#define ENG 26

int main() {
    int n;
    // printf();
    FILE *fp = NULL;
    scanf("%d", &n);
    char name[100];
    char content[100];
    while (n != -1) {
        if (n == 1) {
            scanf("%s", name);
            if ((fp = fopen(name, "r")) == NULL) {
                printf("n/a\n");
            } else {
                fseek(fp, 0, SEEK_END);
                long size = ftell(fp);
                fseek(fp, 0, SEEK_SET);
                if (size == 0) {
                    printf("n/a\n");
                }
                while (fscanf(fp, "%s", content) != EOF) {
                    printf("%s\n", content);
                }
            }
        } else if (n == 2) {
            if ((fp = fopen(name, "r+")) == NULL) {
                printf("n/a\n");
            } else {
                char print[100];
                fp = fopen(name, "r+");
                fseek(fp, 0, SEEK_END);
                scanf("%s", print);
                fprintf(fp, print);
            }
        } else if (n == 3) {
            FILE *fp1, *fp2;
            fp1 = fopen("m1.c", "r");
            fp2 = fopen("../src/ai_modules/m1.c", "r+");
            int flag;
            char c;
            int g;
            scanf("%d", &g);
            c = fgetc(fp1);
            while (!feof(fp1)) {
                flag = 0;
                if (c >= 'A' && c <= 'Z') {
                    c = c + (g % ENG);
                    if (c > 'Z') {
                        c = 'A' + (c - 'Z') - 1;
                    }
                    fprintf(fp2, "%c", c);
                    flag = 1;
                }
                if (c >= 'a' && c <= 'z') {
                    c = c + (g % ENG);
                    if (c > 'z') c = 'a' + (c - 'z') - 1;
                    fprintf(fp2, "%c", c);
                    flag = 1;
                }
                if (!flag) fprintf(fp2, "%c", c);
                c = getc(fp1);
            }
            fclose(fp1);
            fclose(fp2);
            FILE *fp3, *fp4;
            fp3 = fopen("m2.c", "r");
            fp4 = fopen("../src/ai_modules/m2.c", "r+");
            int flag1;
            char c1;
            c = fgetc(fp3);
            while (!feof(fp3)) {
                flag1 = 0;
                if (c1 >= 'A' && c1 <= 'Z') {
                    c1 = c1 + (g % ENG);
                    if (c1 > 'Z') {
                        c1 = 'A' + (c1 - 'Z') - 1;
                    }
                    fprintf(fp4, "%c", c1);
                    flag1 = 1;
                }
                if (c1 >= 'a' && c1 <= 'z') {
                    c1 = c1 + (g % ENG);
                    if (c1 > 'z') c1 = 'a' + (c1 - 'z') - 1;
                    fprintf(fp4, "%c", c1);
                    flag1 = 1;
                }
                if (!flag1) fprintf(fp4, "%c", c1);
                c1 = getc(fp3);
            }
            fclose(fp3);
            fclose(fp4);
        } else {
            printf("n/a\n");
            n = -1;
        }
        scanf("%d", &n);
    }
    if (n == -1) {
        return 0;
    }
    return 0;
}