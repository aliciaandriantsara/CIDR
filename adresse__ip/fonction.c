#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "declaration.h"

double giving_number_of_machine(int bits_number)
{
    double double_bits_number_of_host#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
;
    double number_of_machine=0;
    int bits_number_of_host=0;
    bits_number_of_host=32 - bits_number;
    double_bits_number_of_host=(double)bits_number_of_host;
    number_of_machine=pow(2, double_bits_number_of_host);
    return (number_of_machine);
}

int* giving_inverse_netmask(int* binaire_netmask)
{
    int i;
    int* binaire_netmask_inverse=NULL;
    binaire_netmask_inverse=(int*)malloc(32*sizeof(int));
    for(i=0; i<32; i++)
    {
        if(binaire_netmask[i] == 1)
        {
            binaire_netmask_inverse[i]=0;
        }
        else
        {
            binaire_netmask_inverse[i]=1;
        }
    }
    return (binaire_netmask_inverse);
}

int* binaire_adresse_broadcast(int* binaire_adresse_reseau, int* binaire_netmask)
{
    int i;
    int* binaire_netmask_inverse=NULL;
    int* binaire_broadcast=NULL;
    binaire_broadcast=(int*)malloc(32*sizeof(int));
    binaire_netmask_inverse=(int*)malloc(32*sizeof(int));
    binaire_netmask_inverse=giving_inverse_netmask(binaire_netmask);
    for(i=0; i<32; i++)
    {
        if(binaire_adresse_reseau[i] == 1 && binaire_netmask_inverse[i] == 0)
        {
            binaire_broadcast[i]=1;
        }
        else if(binaire_adresse_reseau[i] == 0 && binaire_netmask_inverse[i] == 1)
        {
            binaire_broadcast[i]=1;
        }
        else if(binaire_adresse_reseau[i] == 1 && binaire_netmask_inverse[i] == 1)
        {
            binaire_broadcast[i]=1;
        }
        else
        {
            binaire_broadcast[i]=0;
        }
    }
    return (binaire_broadcast);
}

int* giving_adresse_reseau(int* binaire_ip, int* binaire_netmask)
{
    int i; 
    int* binaire_adresse_reseau=NULL;
    binaire_adresse_reseau=(int*)malloc(32*sizeof(int));
    for(i=0; i<32; i++)
    {
        if(binaire_ip[i] == 0 || binaire_netmask[i] == 0)
        {
            binaire_adresse_reseau[i]=0;
        }
        else
        {
            binaire_adresse_reseau[i]=1;
        }

    }
    return (binaire_adresse_reseau);
}

int* giving_ip_binaire(int* ip_part_1, int* ip_part_2, int* ip_part_3, int* ip_part_4)
{
    int i;
    int* binaire_ip=NULL;
    binaire_ip=(int*)malloc(32*sizeof(int));
    for(i=0; i<8; i++)
    {
        binaire_ip[i]=ip_part_1[i];
    }
    for(i=8; i<16; i++)
    {
        binaire_ip[i]=ip_part_2[i-8];
    }
    for(i=16; i<24; i++)
    {
        binaire_ip[i]=ip_part_3[i-16];
    }
    for(i=24; i<32; i++)
    {
        binaire_ip[i]=ip_part_4[i-24];
    }
    return (binaire_ip);
}

int* changing_in_decimal(int* binaire)
{
    int* number=NULL;
    int i;
    int* nombre=NULL;
    nombre=(int*)malloc(8*sizeof(int));
    number=(int*)malloc(4*sizeof(int));
    for(i=0; i<4; i++)
    {
        number[i]=0;
    }
    nombre[0]=128;
    nombre[1]=64;
    nombre[2]=32;
    nombre[3]=16;
    nombre[4]=8;
    nombre[5]=4;
    nombre[6]=2;
    nombre[7]=1;
    for(i=0;i<8;i++)
    {
        if(binaire[i] == 1)
        {
            number[0]=number[0]+ nombre[i];
        }
        else
        {
            number[0]=number[0];
        }
    }
    for(i=8;i<16;i++)
    {
        if(binaire[i] == 1)
        {
            number[1]=number[1]+ nombre[i-8];
        }
        else
        {
            number[1]=number[1];
        }
    }
    for(i=16;i<24;i++)
    {
        if(binaire[i] == 1)
        {
            number[2]=number[2]+ nombre[i-16];
        }
        else
        {
            number[2]=number[2];
        }
    }
    for(i=24;i<32;i++)
    {
        if(binaire[i] == 1)
        {
            number[3]=number[3]+ nombre[i-24];
        }
        else
        {
            number[3]=number[3];
        }
    }
    return (number);

}

int* giving_msr(int bits_number)
{
    int* binaire_netmask=NULL;
    int i;
    binaire_netmask=(int*)malloc(32*sizeof(int));
    for(i=0; i<bits_number; i++)
    {
        binaire_netmask[i]=1;
    }
    for(i=(bits_number + 1); i<32; i++)
    {
        binaire_netmask[i]=0;
    }
    return (binaire_netmask);
}

int* changing_in_binaire(int dividende)
{
    int* binaire=NULL;
    int i;
    int* diviseur=NULL;
    binaire=(int*)malloc(8*sizeof(int));
    diviseur=(int*)malloc(8*sizeof(int));
    diviseur[0]=128;
    diviseur[1]=64;
    diviseur[2]=32;
    diviseur[3]=16;
    diviseur[4]=8;
    diviseur[5]=4;
    diviseur[6]=2;
    diviseur[7]=1;
    if(dividende > 128)
    {
        printf("        <p>Erreur</p>\n");
    }
    else
    {
        for(i=0; i<8; i++)
        {
            if(dividende >= diviseur[i])
            {
                dividende=(dividende%diviseur[i]);
                binaire[i]=1;
            }
            else
            {
                binaire[i]=0;
            }
        }
    }
    return (binaire);
}

int* changing_type(char* tab_ip_1, char* tab_ip_2, char* tab_ip_3, char* tab_ip_4)
{
    int* a=NULL;
    a=(int*)malloc(4*sizeof(int));
    a[0]=atoi(tab_ip_1);
    a[1]=atoi(tab_ip_2);
    a[2]=atoi(tab_ip_3);
    a[3]=atoi(tab_ip_4);
    return (a);
    
}

int control_error(char *tab_ip_1, char *tab_ip_2, char *tab_ip_3, char *tab_ip_4)
{
    char *tab_ip=NULL;
    int i;
    int *a;
    int verify=0;
    a=(int*)malloc(4*sizeof(int));
    a[0]=strlen(tab_ip_1);
    a[1]=strlen(tab_ip_2);
    a[2]=strlen(tab_ip_3);
    a[3]=strlen(tab_ip_4);
    for(i=0; i<4; i++)
    {
        if(a[i] > 3)
        {
            verify=1;
            printf("        <p>Vous avez faits une erreur. Recommencez</p>\n");
        }
    }
    return (verify);
}

void type_of_adress(int verification, char *tab_ip_1,  char *tab_ip_2, char *tab_ip_3, char *tab_ip_4)
{
    int verify=0;
    int value_1=0;
    value_1=atoi(tab_ip_1);
    verify=control_error(tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
    if(verify == 1)
    {
        goto QUIT;
    }
    else
    {
        if(verification == 1)
        {
            printf("            <p>Ce que vous avez entrez n'est pas un adresse IP</p>\n");
        }
        else
        {
            if (value_1 < 128)
            {
                printf("            <p>Vous avez entrez un adresse IP de type A</p>\n");
            }
            else if(value_1 < 192)
            {
                printf("            <p>Vous avez entrez un adresse IP de type B</p>\n");
                
            }            
                
            else if(value_1 < 224)
            {
                printf("            <p>Vous avez entrez un adresse IP de type C</p>\n");

            }  
            else if(value_1 <240)
            {
                printf("            <p>Vous avez entrez un adresse IP de type D</p>\n");

            }
            else
            {
                printf("            <p>Vous avez entrez un adresse IP de type E</p>\n");

            }
        
        }
    }
QUIT:
}

int testing_adresss(char *tab_ip_1, char *tab_ip_2, char *tab_ip_3, char *tab_ip_4)
{
    int *tab_ip=NULL;
    int i;
    int verification=0;
    tab_ip=(int*)malloc(4*sizeof(int));

    tab_ip[0]=atoi(tab_ip_1);
    tab_ip[1]=atoi(tab_ip_2);
    tab_ip[2]=atoi(tab_ip_3);
    tab_ip[3]=atoi(tab_ip_4);
    for(i=0; i<4; i++)
    {
        if(tab_ip[i] > 255)
        {
            verification=1;
        }
    }
    return (verification);
}

int verification_verification(char* tab_ip_1, char* tab_ip_2, char* tab_ip_3, char* tab_ip_4)
{
    int verification_2=0;
    if(!atoi(tab_ip_1))
    {
        verification_2=1;
    }
    else if(!atoi(tab_ip_2))
    {
        verification_2=1;
    }
    else if(!atoi(tab_ip_3))
    {
        verification_2=1;
    }
    else if(!atoi(tab_ip_4))
    {
        verification_2=1;
    }
    return (verification_2);

}

void main_main(char *recovery_ip, int chaine_ip, int bits_number)
{
    char tab_ip_1[4];
    char tab_ip_2[4];
    char tab_ip_3[4];
    char tab_ip_4[4];
    
    int* a=NULL;
    int* ip_part_1=NULL;
    int* ip_part_2=NULL;
    int* ip_part_3=NULL;
    int* ip_part_4=NULL;
    int* binaire_netmask=NULL;
    int* decimal_netmask=NULL;

    int* binaire_ip=NULL;
    int* binaire_adresse_reseau=NULL;
    int* binaire_netmask_inverse=NULL;
    int* binaire_broadcast=NULL;
    int* decimal_adresse_reseau=NULL;
    int* decimal_adresse_broadcast=NULL;


    int verification_2=0;
    int verification=0;
    double number_of_machine;

    a=(int*)malloc(4*sizeof(int));    
    ip_part_1=(int*)malloc(8*sizeof(int));
    ip_part_2=(int*)malloc(8*sizeof(int));
    ip_part_3=(int*)malloc(8*sizeof(int));
    ip_part_4=(int*)malloc(8*sizeof(int));
    binaire_netmask=(int*)malloc(32*sizeof(int));
    decimal_netmask=(int*)malloc(4*sizeof(int));
    binaire_ip=(int*)malloc(32*sizeof(int));
    binaire_adresse_reseau=(int*)malloc(32*sizeof(int));
    binaire_netmask_inverse=(int*)malloc(32*sizeof(int));
    
    if(chaine_ip == 1)
    {
        sscanf(recovery_ip, "%[^.].%[^.].%[^.].%[^.]", tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
        verification_2=verification_verification(tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);

        if(verification_2 == 0)
        {
            verification=testing_adresss(tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
            type_of_adress(verification, tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
            a=changing_type(tab_ip_1, tab_ip_2, tab_ip_3, tab_ip_4);
            ip_part_1=changing_in_binaire(a[0]);
            ip_part_2=changing_in_binaire(a[1]);
            ip_part_3=changing_in_binaire(a[2]);
            ip_part_4=changing_in_binaire(a[3]);
            binaire_netmask=giving_msr(bits_number);
            decimal_netmask=changing_in_decimal(binaire_netmask);
            printf("        <p>Le masque sous reseau est : \n");
            for(int i=0; i<4; i++)
            {
                printf("        %d.", decimal_netmask[i]);
            }
            printf("        </p>\n");
            binaire_ip=giving_ip_binaire(ip_part_1, ip_part_2, ip_part_3, ip_part_4);
            binaire_adresse_reseau=giving_adresse_reseau(binaire_ip, binaire_netmask);
            decimal_adresse_reseau=changing_in_decimal(binaire_adresse_reseau);
            printf("        <p>L'adresse reseau est : \n");
            for(int i=0; i<4; i++)
            {
                printf("        %d.", decimal_adresse_reseau[i]);
            }
            printf("        </p>\n");
            
            //printf("        <p>L'adresse reseau est : %d</p>\n", decimal_adresse_reseau);
            binaire_broadcast=binaire_adresse_broadcast(binaire_adresse_reseau, binaire_netmask);
            decimal_adresse_broadcast=changing_in_decimal(binaire_broadcast);
            printf("        <p>L'adresse broadcast est : \n");
            for(int i=0; i<4; i++)
            {
                printf("        %d.", decimal_adresse_broadcast[i]);
            }
            printf("        </p>\n");
            
            //printf("        <p>L'adresse broadcast est %d</p>\n", decimal_adresse_broadcast);
            number_of_machine=giving_number_of_machine(bits_number);
            printf("        <p>Le nombre de machine possible est %f</p>\n", number_of_machine);
        }
        else 
        {
            printf("                <p>Vous avez tapez des lettres au lieu de nombre. Recommencez</p>\n");
            goto RESTART;
        }
    }
    else
    {
        printf("                <p>Vous n'avez pas suivi l'instruction SA ETO. Recommencez</p>\n");
    }
RESTART:
}


int chainecarac(char* recovery_ip)
{
    int chaine=0;
    int i;
    for(i=0; i<16;i++)
    {
        if(recovery_ip[i] == '.')
        {
            chaine=1;
        }
    }
    return (chaine);
}

void last_test(int number_of_character)
{
    int chaine=0;
    int bits_number_reseau=0;
    char *true_recovery_ip=NULL;
    int number_of_ip=0;
    char *recovery=NULL;
    char recovery_ip[16];
    char recovery_bits_number[3];

    recovery=(char*)malloc(number_of_character*sizeof(char));
    strcpy(recovery, getenv("QUERY_STRING"));
    sscanf(recovery, "ip=%[^&]&bits_number=%s", recovery_ip, recovery_bits_number);
    if(!atoi(recovery_bits_number))
    {
        printf("        <p>Vous avez tapez des lettres au lieu des nombres dans le nombre de bits pour le reseau</p>\n");
    }
    else
    {
        bits_number_reseau=atoi(recovery_bits_number);
    }
    number_of_ip=strlen(recovery_ip);
    true_recovery_ip=(char*)malloc(number_of_ip*sizeof(char));
    if(number_of_ip<=18)
    {
        strcpy(true_recovery_ip, recovery_ip);
        chaine=chainecarac(true_recovery_ip);
        main_main(true_recovery_ip, chaine, bits_number_reseau);
    }
    else
    {
        printf("                <p>Vous n'avez pas suivi l'instruction ETO EH. Recommencez</p>\n");

    }
}

void foot_of_body()
{
    printf("        <p>\n");
    printf("            Cliquez sur le bouton retour pour reesayer\n");
    printf("            <form action=\"cidr.html\" method=\"post\">\n");
    printf("                <input type=\"submit\" value=\"Retour\"/>\n");
    printf("            </form>\n");
    printf("        </p>\n");
    printf("    </body>\n");
    printf("</html>\n");
}

void head_of_body()
{
    printf("    <body>\n");
    printf("        <h1>Adresse IP et reseau local</h1>\n");
}

void head(char *title)
{
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>%s</title>\n", title);
    printf("        <meta charset=\"utf-8\"/>\n");
    printf("        <link rel=\"stylesheet\" href=\"adresseip.css\"/>\n");
    printf("    </head>\n");
}
