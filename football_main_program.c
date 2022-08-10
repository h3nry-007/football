#include <stdio.h>
#include <stdlib.h>
#include "mydata.c"
int buyfa();
int main(){
    extern int x;
    int type=0, admcode=0, spasscode=0, Upassword=0, inNum=0, i=0;
    int Uid=0, Buycode=0, Buymoney=0, BuyPress=0;
    long long unsigned int coin, Pprice;
    char Pname[100];
    char readmode;
    //char a[100]="60000", b[100]="70000";


    printf("^^^WELCOME TO OUR SPORTS CLUB^^^\n\n");
    printf("<Please choose your login type>\n\n");
    printf("[1]Admin type:\n[2]User Type:\n\n");
    printf("[WISI] Please input type no:::");
    scanf("%d",&type);

    //for admin login //
    if(type==1){ //for admin login://
        system("cls");
        printf("##You are logged in as admin##\n\n");
        printf("[WISI] Pleas enter your admin code:");
        scanf("%d",&admcode);
        printf("[WISI] Please enter the site passcode:");
        scanf("%d",&spasscode);

        if(admcode!=0000 && spasscode == 5005){ //admin info right//
            system("cls");
            printf(">Yor can edit now<\n\n");
            printf("[WISI] enter player amount:");
            scanf("%d",&inNum);

            FILE *firstFile;
            firstFile= fopen("mydata.c","w+");
            if(firstFile==NULL){ //file open loop
                printf("!!ERROR!!");
            }else{
                int Pcode = 1;
                fprintf(firstFile, "int x = %d;\n", inNum);
                for(i=0; i<inNum; i++){ //file input loop
                    printf("For player[%d]\nInput the player name:",i+1); //FILE ERROR//
                    scanf("%s",Pname);
                    printf("Input the player price:");
                    scanf("%llu",&Pprice);
                    fprintf(firstFile, "char p%d[] = \"%s\";\nunsigned long long int pr%d = %llu;\nint pc%d = %d;\n\n", Pcode,Pname, Pcode, Pprice, Pcode, Pcode);
                    Pcode++;

                }
                fprintf(firstFile, "void text(){\n");
                for(i=1; i<inNum+1; i++){
                    fprintf(firstFile, "    printf(\"Player: %cs%cn\", p%d);\n", 37, 92, i);
                    fprintf(firstFile, "    printf(\"Price: %cu%cn\", pr%d);\n", 37, 92, i);
                    fprintf(firstFile, "    printf(\"Code: %cd%cn%cn\", pc%d);\n\n", 37, 92, 92, i);
                }
                fprintf(firstFile, "}\n\n");
                fprintf(firstFile, "int buyfa(long long unsigned int *coin, int *code){\n    char *v[%d][3] = {\n    ", inNum);
                for(int i=1; i<inNum+1; i++){
                    if (i == inNum){
                    fprintf(firstFile, "{p%d, pr%d, pc%d}", i, i, i);
                    }else{
                    fprintf(firstFile, "{p%d, pr%d, pc%d},\n    ", i, i, i);
                    }
                }
                fprintf(firstFile, "\n};\n");
                fprintf(firstFile, "    int BuyPress;\n    int a = v[*code-1][1];\n    if(a>*coin){\n        printf(\"Sorry You don't have enought money\");\n        return 1;}\n    int Buymoney;\n    printf(\"Player Name is: %cs%cn\", v[*code-1][0]);\n", 37, 92);
                fprintf(firstFile, "    printf(\"[WISI] If You want to buy, press[1]: \");\n    scanf(\"%cd\", %cBuyPress);\n", 37, 38);
                fprintf(firstFile, "    if(BuyPress == 1){\n        Buymoney = *coin - a;\n        printf(\"You have bought: %cs%cn\", v[*code-1][0]);\n", 37, 92);
                fprintf(firstFile, "        printf(\"Your left money is: %cd\", Buymoney);\n    }\n    return 0;\n}", 37);
                fclose(firstFile);

            }
        }else{ //admin can't login text
            printf("\nYou cannot login as an admin!\nSOMETHING WENT WRONG!\n");
        }


    //for user login//
    }else if(type==2){ //for user login//
        system("cls");
        printf("You can log in as user;\n\n");

        printf("\nEnter your password:");
        scanf("%d",&Upassword);
        printf("Please enter your id:");
        scanf("%d",&Uid);
        if(Uid!=0000 && Upassword!=0000){ //user login success
            printf("\nWhich type of player do you want?\n");
            printf("Please enter your coin amount: ");
            scanf("%llu",&coin);
            if(coin<30000){ //file read
               printf("You cant buy anything!");
            }else{
                printf("\nYou Can Buy:\n\n");
                text();
                printf("\n\nOk finished!!");
                printf("\nEnter the player code to buy:: ");
                scanf("%d",&Buycode);
                if (Buycode<=0 || Buycode>x){
                    printf("Player Not Found!!");
                    exit(0);
                }else{
                    buyfa(&coin, &Buycode);
                }

            }

        }else{ //user login failed
            printf("You are not right:");

        }


    }else{ //no user no admin
        printf("\n####No Work!####\n");
        exit(1);
    }



return 0;
}

