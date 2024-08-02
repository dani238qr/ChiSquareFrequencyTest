#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

int main(int argc,char *argv[]) {

    if(argc!= 3){
        fprintf(stderr, "Usage: %s <size of probe > <probe filename>\n", argv[0]);
        return 1;
    }

    int max = atoi(argv[1]);

    if(max <= 0){
        fprintf(stderr, "Error: max must be a positive integer.\n");
        return 1;
    }

    const char *filename=argv[2];

    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL) {
        perror("Error opening file");
        return 1;
    }

    int *data=(int *)malloc(max*sizeof(int));
    if (data==NULL){
        perror("Error allocating memory");
        fclose(fp);
        return 1;
    }

    int count=0;

    while(count<max){
        int ch=fgetc(fp);
        if(ch==EOF) {
            break;
        }
        if(ch=='0' || ch =='1'){
            data[count++]= ch-'0';      //convert str in int
        }                              //0 is 048 in ascii, 1 is 049
    }                                 //49-48=1, 48-48=0  

    fclose(fp);
    
    double chi_s_cr;
    double pr_lvl;
    int user_c;
    printf("Choose probability level\n1) 0.995\n2) 0.975\n3) 0.20\n4) 0.10\n5) 0.05\n6) 0.025\n7) 0.02\n8) 0.01\n9) 0.005\n10) 0.002\n11) 0.001)\n> ");
    scanf("%d",&user_c);
    switch(user_c){
        case 1:
            pr_lvl=0.995;
            chi_s_cr=0.0000393;
            break;
        case 2:
            pr_lvl=0.975;
            chi_s_cr=0.000982;
            break;
        case 3:
            pr_lvl=0.20;
            chi_s_cr=1.642;
            break;
        case 4:
            pr_lvl=0.10;
            chi_s_cr=2.706;
            break;
        case 5:
            pr_lvl=0.05;
            chi_s_cr=3.841;
            break;
        case 6:
            pr_lvl=0.025;
            chi_s_cr=5.024;
            break;
        case 7:
            pr_lvl=0.02;
            chi_s_cr=5.412;
            break;
        case 8:
            pr_lvl=0.01;
            chi_s_cr=6.635;
            break;
        case 9:
            pr_lvl=0.005;
            chi_s_cr=7.879;
            break;
        case 10:
            pr_lvl=0.002;
            chi_s_cr=9.550;
            break;
        case 11:
            pr_lvl=0.001;
            chi_s_cr=10.828;
            break;
    }

    while(getchar()!='\n');
    char user;
    printf("print array(y/n): ");
    scanf("%c",&user);

    if (user == 'y'){
        printf("Read %d bits: ", count);
        for (int i=0;i<count;i++){
            printf("%d", data[i]);
        }
        printf("\n");
    }
    


    int zero,one;
    
    for (int x=0;x<max;x++){
        if(data[x]==1){
            one++;
        }
        else{
            zero++;
        }
    }
   
    int expect_f=max/2;
    
    printf("\nFrequency test\n");
    printf("\nNumber of 1s: %d ,expected frequencies %d ",one,expect_f);
    printf("\nNumber of 0s: %d ,expected frequencies %d ",zero,expect_f);
    
    //Chi-Square Statistic
    
    double chi_s=pow((double)(zero-expect_f),2)/expect_f+pow((double)(one-expect_f),2)/expect_f;
    //Degrees of Freedom
    
    int df=1; //2 cat. 0 and 1 => df=no. of cat. -1
    
    
    printf("\nChi-Square value: %.2f\nChi squared critical values(from Chi square table at %.2f): %.2f",chi_s,pr_lvl,chi_s_cr);
    
    if(chi_s<chi_s_cr){
        printf("\n\n %.2f < %.2f \n",chi_s,chi_s_cr);
        printf("\nNot enough evidence to reject the null hypothesis at the chosen significance level(%.2f)\n",pr_lvl);
        printf("The observed frequencies are not significantly different from the expected frequencies\n");
    }
    else if(chi_s>=chi_s_cr){
        printf("\n\n %.2f >= %.2f \n",chi_s,chi_s_cr);
        printf("\nWe have enough evidence to reject the null hypothesis at the chosen significance level(%.2f)\n",pr_lvl);
        printf("Rejecting the null hypothesis indicates that the observed frequencies are significantly different from the expected frequencies (or theoretical distribution).\nThe difference observed is considered statistically significant\n");
    }
   
    printf("\n");    
 
    free(data);

    return 0;
}

