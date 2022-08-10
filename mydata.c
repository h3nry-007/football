int x = 3;
char p1[] = "Ronaldo";
unsigned long long int pr1 = 80000;
int pc1 = 1;

char p2[] = "Messi";
unsigned long long int pr2 = 85000;
int pc2 = 2;

char p3[] = "Neymar";
unsigned long long int pr3 = 76000;
int pc3 = 3;

void text(){
    printf("Player: %s\n", p1);
    printf("Price: %u\n", pr1);
    printf("Code: %d\n\n", pc1);

    printf("Player: %s\n", p2);
    printf("Price: %u\n", pr2);
    printf("Code: %d\n\n", pc2);

    printf("Player: %s\n", p3);
    printf("Price: %u\n", pr3);
    printf("Code: %d\n\n", pc3);

}

int buyfa(long long unsigned int *coin, int *code){
    char *v[3][3] = {
    {p1, pr1, pc1},
    {p2, pr2, pc2},
    {p3, pr3, pc3}
};
    int BuyPress;
    int a = v[*code-1][1];
    if(a>*coin){
        printf("Sorry You don't have enought money");
        return 1;}
    int Buymoney;
    printf("Player Name is: %s\n", v[*code-1][0]);
    printf("[WISI] If You want to buy, press[1]: ");
    scanf("%d", &BuyPress);
    if(BuyPress == 1){
        Buymoney = *coin - a;
        printf("You have bought: %s\n", v[*code-1][0]);
        printf("Your left money is: %d", Buymoney);
    }
    return 0;
}