#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // a

int main (){
    setlocale(LC_ALL, "Portuguese"); // define que o meu sistema será em Português
    
    char estado1, estado2; // Cadastros de variavel com somente uma caractere
    char cdCarta1[99], cdCarta2[99] , cidade1[99], cidade2[99]; // Cadastro de variaveis do tipo Strings
    int pontosTuristicos1, pontosTuristicos2, pontosCarta1 = 0, pontosCarta2 = 0,maiorPopulacao, maiorArea, maiorPib, maiorPontosTuristicos, menorDensidade, maiorPibPerCapital, comparacao, qualComparar, 
    qualComparar1, qualComparar2; // cadastro variaveis inteiras
    unsigned long int populacao1 , populacao2; // cadastro variaveis interias para grandes números
    float area1, area2, pib1, pib2, densidade1, densidade2, pibPerCapital1, pibPerCapital2;  // cadastro variaveis com . flutuante

    printf("===Bem-vindo ao Super Trunfo - Países===\n");
    
    /* Entrada de dados da Carta 1 */
    printf("Cadastro carta 1:\n");
    printf("Estado: ");
    scanf(" %c", &estado1);  
    while (getchar() != '\n'); // limpa ENTER do buffer
    printf("Qual o Código? ");
    scanf("%s", cdCarta1);
    while (getchar() != '\n'); 
    printf("Nome da Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0'; // remove o ENTER
    printf("Qual a População: ");
    scanf("%lu", &populacao1);
    while (getchar() != '\n'); 
    printf("Qual a Área dessa cidade? ");
    scanf("%f", &area1);
    while (getchar() != '\n'); 
    printf("Qual o PIB dessa cidade? ");
    scanf("%f", &pib1);
    while (getchar() != '\n'); 
    printf("Qual a quantidade de pontos turísticos? ");
    scanf("%d", &pontosTuristicos1);
    while (getchar() != '\n'); 
    printf("================================\n\n");

    /* Entrada de dados da Carta 2 */
    printf("Cadastro carta 2:\n");
    printf("Estado: ");
    scanf(" %c", &estado2);  
    while (getchar() != '\n'); 
    printf("Qual o Código? ");
    scanf("%s", cdCarta2);
    while (getchar() != '\n'); 
    printf("Nome da Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0'; 
    printf("Qual a População: ");
    scanf("%lu", &populacao2);
    while (getchar() != '\n'); 
    printf("Qual a Área dessa cidade? ");
    scanf("%f", &area2);
    while (getchar() != '\n'); 
    printf("Qual o PIB dessa cidade? ");
    scanf("%f", &pib2);
    while (getchar() != '\n'); 
    printf("Qual a quantidade de pontos turísticos? ");
    scanf("%d", &pontosTuristicos2);
    while (getchar() != '\n'); 
    printf("================================\n\n");

    /* Calculos*/

    /* calculo de densidade */
    densidade1 = (float) populacao1 / area1;
    densidade2 = (float) populacao2 / area2;

    /* calculo PIB per capital */
    pibPerCapital1 = (float) (pib1 * 1000000000)/ populacao1;
    pibPerCapital2 = (float) (pib2 * 1000000000)/ populacao2;

    /* Comparação */
    maiorPopulacao = (populacao1 > populacao2) ? 1 : 0; //Comparação População
    maiorArea = (area1 > area2) ? 1 : 0; // comparação Área
    maiorPib = (pib1 > pib2) ? 1 : 0; // comparação PIB
    maiorPontosTuristicos = (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0; // comparação Pontos Turísticos
    menorDensidade = (densidade1 < densidade2) ? 1 : 0; // comparação Densidade
    maiorPibPerCapital = (pibPerCapital1 > pibPerCapital2) ? 1 : 0; // comparação Pib Per Capital


    system("cls");

    /* Comparação de cartas */
    printf("=== Comparação das cartas ===\n");
    printf("1. Comparar Atributo Individualmente\n");
    printf("2. Comparar dois Atributos de cada carta\n");
    printf("3. Comparar todos os Atributos\n");
    printf("4. Exibir Cartas");
    printf("Digite uma das opções acima: ");
    scanf("%d", &comparacao);
    printf("\n");
    system("cls");

    printf("==================================\n");
    switch (comparacao){
        case 1:
            printf("=== Comparação Individualmente ===\n");
            printf("Qual Atributo deseja comparar\n\n");
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. PIB\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade\n");
            printf("6. PIB Per Capital\n");
            printf("Digite uma das opções acima: ");
            scanf("%d", &qualComparar);
            system("cls");

            switch (qualComparar){
                case 1:
                    printf("Carta 1 - %s (%c%s)\n", cidade1, estado1, cdCarta1);
                    printf("Carta 2 - %s (%c%s)\n", cidade2, estado2, cdCarta2);
                    if (maiorPopulacao == 1){  // se população 1 for maior que população 2 então: a carta 1 recebe 1 ponto
                        printf("Resultado População: Carta 1 (%s) tem a maior populção!\n", cidade1);
                        pontosCarta1++;
                    }else if (maiorPopulacao == 0){   // senão se população 2 for maior que população 1 então: a carta 2  recebe 1 ponto
                        printf("Resultado População: Carta 2 (%s) tem a maior população!\n", cidade2);
                        pontosCarta2++;
                    }else{  // senão for maior nenhum dos dois (são iguais) então ninguem recebe pontos
                        printf("Empate em Populçação!\n");
                    }
                break;
                case 2:
                    printf("Carta 1 - %s (%c%s)\n", cidade1, estado1, cdCarta1);
                    printf("Carta 2 - %s (%c%s)\n", cidade2, estado2, cdCarta2);
                    if (maiorArea == 1){ // se a área 1 for maior que a área 2 então: a carta 1 recebe 1 ponto
                        printf("Resultado Área: Carta 1 (%s) tem a maior área!\n", cidade1);
                        pontosCarta1++;
                    }else if (maiorArea == 0){ // se a área 2 for maior que área 1 então: a carta 2 recebe 1 ponto
                        printf("Resultado Área: Carta 2 (%s) tem a maior área!\n", cidade2);
                        pontosCarta2++;
                    }else{  // senão for maior nenhum dos dois (são iguais) então ninguem recebe pontos
                        printf("Empate em Área!\n");
                    }
                break;
                case 3:
                    printf("Carta 1 - %s (%c%s)\n", cidade1, estado1, cdCarta1);
                    printf("Carta 2 - %s (%c%s)\n", cidade2, estado2, cdCarta2);
                    if(maiorPib == 1){  // se o PIB 1 for maior que o PIB 2 então: a carta 1 recebe 1 ponto
                        printf("Resultado PIB: Carta 1 (%s) tem o maior PIB!\n", cidade1);
                        pontosCarta1++;
                    }else if(maiorPib == 0){  // se o PIB 2 for maior que o PIB 1 então: a carta 2 recebe 1 ponto
                        printf("Resultado PIB: Carta 2 (%s) tem o maior PIB\n", cidade2);
                        pontosCarta2++;
                    }else{  // senão for maior nenhum dos dois (são iguais) então ninguem recebe pontos
                    printf("Empate em PIB!\n");
                    }
                break;
                case 4:
                    printf("Carta 1 - %s (%c%s)\n", cidade1, estado1, cdCarta1);
                    printf("Carta 2 - %s (%c%s)\n", cidade2, estado2, cdCarta2);
                    if(maiorPontosTuristicos == 1){   // se pontos turísticos 1 for maior que pontos turísticos 2 então: a carta 1 recebe 1 ponto
                        printf("Resultado Pontos Turísticos: Carta 1 (%s) tem mais pontos turísticos!\n", cidade1);
                        pontosCarta1++;
                    }else if(maiorPontosTuristicos == 0){  // se pontos turísticos 2 for maior que pontos turísticos 1 então: a carta 2 recebe 1 ponto
                        printf("Resultado Pontos Turísticos: Carta 2 (%s) tem mais pontos turísticos!\n", cidade2);
                        pontosCarta2++;
                    }else{  // senão for maior nenhum dos dois (são iguais) então ninguem recebe pontos
                        printf("Empate em Pontos Turísticos\n");
                    }
                break;
                case 5:
                    printf("Carta 1 - %s (%c%s)\n", cidade1, estado1, cdCarta1);
                    printf("Carta 2 - %s (%c%s)\n", cidade2, estado2, cdCarta2);
                    if(menorDensidade == 1){  // se densidade 1 for menor que densidade 2 então: a carta 1 recebe 1 ponto
                        printf("Resultado Densidade: Carta 1 (%s) tem a menor densidade!\n", cidade1); 
                        pontosCarta1++;
                    }else if(menorDensidade == 0){  // se densidade 2 for menor que densidade 1 então: a carta 2 recebe 1 ponto
                        printf("Resultado Densidade: Carta 2 (%s) tem a menor densidade!\n", cidade2);
                        pontosCarta2++;
                    }else{  // senão for maior nenhum dos dois (são iguais) então ninguem recebe pontos
                        printf("Empate em Densidade!\n"); 
                    }
                break;
                case 6:
                    printf("Carta 1 - %s (%c%s)\n", cidade1, estado1, cdCarta1);
                    printf("Carta 2 - %s (%c%s)\n", cidade2, estado2, cdCarta2);
                    if(maiorPibPerCapital == 1){  // se PIB per capital 1 for maior que PIB per capital 2 então: a carta 1 recebe 1 ponto
                        printf("Resultado PIB per Capital: Carta 1 (%s) tem o maior PIB per Capital!\n", cidade1);
                        pontosCarta1++;
                    }else if(maiorPibPerCapital == 0){  // se PIB per capital 2 for maior que PIB per capital 1 então: a carta 2 recebe 1 ponto 
                        printf("Resultado PIB per Capital: Carta 2 (%s) tem o maior PIB per Capital!\n", cidade2);
                        pontosCarta2++;
                    }else{  // senão for maior nenhum dos dois (são iguais) então ninguem recebe pontos
                        printf("Empate em PIB per Capital!\n");
                    }
                break;
                default:
                    printf("Opção Invalida.\n");
                break;
            }
        break;
        case 2:
            /*  Coparação de dois atributos */
            printf("=== Comparação Individualmente ===\n");
            printf("Escolha o primeiro atributo a ser comparado\n\n");
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. PIB\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade\n");
            printf("6. PIB Per Capital\n");
            printf("Digite uma das opções acima: ");
            scanf("%d", &qualComparar1);
            system("cls");

            printf("=== Comparação Individualmente ===\n");
            printf("Escolha o segundo atributo a ser comparado\n\n");
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. PIB\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade\n");
            printf("6. PIB Per Capital\n");
            printf("Digite uma das opções acima: ");
            scanf("%d", &qualComparar2);
            system("cls");

            (qualComparar1 == qualComparar2) ? printf("Você escolheu duas vezes o mesmo atributo"): 0 ;
            printf("==================================\n");
            printf("Carta 1 - %s (%c%s)\n", cidade1, estado1, cdCarta1);
            printf("Carta 2 - %s (%c%s)\n", cidade2, estado2, cdCarta2);
            printf("==================================\n");

            // se a coparação for entre População e também for entre Área
            if((qualComparar1 == 1 && qualComparar2 == 2) || (qualComparar2 == 1 && qualComparar1 == 2)){  
                if(maiorPopulacao == 1){
                    printf("Resultado População: Carta 1 (%s) tem a maior populção!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPopulacao == 0){
                    printf("Resultado População: Carta 2 (%s) tem a maior população!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Populçação!\n");
                }
                if(maiorArea == 1){
                   printf("Resultado Área: Carta 1 (%s) tem a maior área!\n", cidade1);
                   pontosCarta1++; 
                }else if(maiorArea == 0){
                    printf("Resultado Área: Carta 2 (%s) tem a maior área!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Área!\n");
                }
            }

            // se a comparação for entre População e também for entre PIB

            if((qualComparar1 == 1 && qualComparar2 == 3)||(qualComparar2 == 1 && qualComparar1 == 3)){
                if(maiorPopulacao == 1){
                    printf("Resultado População: Carta 1 (%s) tem a maior populção!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPopulacao == 0){
                    printf("Resultado População: Carta 2 (%s) tem a maior população!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Populçação!\n");
                }
                if(maiorPib == 1){
                    printf("Resultado PIB: Carta 1 (%s) tem o maior PIB!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPib == 0){
                    printf("Resultado PIB: Carta 2 (%s) tem o maior PIB\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB!\n");
                }
            }

            // se a comparação for entre População e também entre Pontos Turísticos
            if((qualComparar1 == 1 && qualComparar2 == 4)|| (qualComparar2 == 1 && qualComparar1 == 4)){
                if(maiorPopulacao == 1){
                    printf("Resultado População: Carta 1 (%s) tem a maior populção!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPopulacao == 0){
                    printf("Resultado População: Carta 2 (%s) tem a maior população!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Populçação!\n");
                }
                if(maiorPontosTuristicos == 1){
                    printf("Resultado Pontos Turísticos: Carta 1 (%s) tem mais pontos turísticos!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPontosTuristicos == 0){
                    printf("Resultado Pontos Turísticos: Carta 2 (%s) tem mais pontos turísticos!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Pontos Turísticos\n");
                }
            }

            // se a comparação for entre População e também entre Densidade
            if((qualComparar1 == 1 && qualComparar2 == 5)||(qualComparar2 == 1 && qualComparar1 ==5)){
               if(maiorPopulacao == 1){
                printf("Resultado População: Carta 1 (%s) tem a maior populção!\n", cidade1);
                pontosCarta1++;
                }else if(maiorPopulacao == 0){
                    printf("Resultado População: Carta 2 (%s) tem a maior população!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Populçação!\n");
                } 
                if(menorDensidade == 1){
                    printf("Resultado Densidade: Carta 1 (%s) tem a menor densidade!\n", cidade1);
                    pontosCarta1++;
                }else if(menorDensidade == 0){
                    printf("Resultado Densidade: Carta 2 (%s) tem a menor densidade!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Densidade!\n");
                }
            }

            // se a comparação for entre Populaçao e também entre Pib Per Capital
            if((qualComparar1 == 1 && qualComparar2 == 6)||(qualComparar2 == 1 && qualComparar1 == 6)){
                if(maiorPopulacao == 1){
                    printf("Resultado População: Carta 1 (%s) tem a maior populção!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPopulacao == 0){
                    printf("Resultado População: Carta 2 (%s) tem a maior população!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Populçação!\n");
                }
                if(maiorPibPerCapital == 1){
                    printf("Resultado PIB per Capital: Carta 1 (%s) tem o maior PIB per Capital!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPibPerCapital == 0){
                    printf("Resultado PIB per Capital: Carta 2 (%s) tem o maior PIB per Capital!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB per Capital!\n");
                }
            }

            // se a comparação for entre Área e também entre PIB
            if((qualComparar1 == 2 && qualComparar2 == 3)||(qualComparar2 == 2 && qualComparar1 == 3)){
                if(maiorArea == 1){
                   printf("Resultado Área: Carta 1 (%s) tem a maior área!\n", cidade1);
                   pontosCarta1++; 
                }else if(maiorArea == 0){
                    printf("Resultado Área: Carta 2 (%s) tem a maior área!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Área!\n");
                }
                if(maiorPib == 1){
                    printf("Resultado PIB: Carta 1 (%s) tem o maior PIB!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPib == 0){
                    printf("Resultado PIB: Carta 2 (%s) tem o maior PIB\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB!\n");
                }
            }
            
            // se a comparação for entre Área e também entre Pontos Turísticos
            if((qualComparar1 == 2 && qualComparar2 == 4)||(qualComparar2 == 2 && qualComparar1 == 4)){
                if(maiorArea == 1){
                   printf("Resultado Área: Carta 1 (%s) tem a maior área!\n", cidade1);
                   pontosCarta1++; 
                }else if(maiorArea == 0){
                    printf("Resultado Área: Carta 2 (%s) tem a maior área!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Área!\n");
                }
                if(maiorPontosTuristicos == 1){
                    printf("Resultado Pontos Turísticos: Carta 1 (%s) tem mais pontos turísticos!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPontosTuristicos == 0){
                    printf("Resultado Pontos Turísticos: Carta 2 (%s) tem mais pontos turísticos!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Pontos Turísticos\n");
                }
            }
            
            // se a comparação for entre Área e também entre Densidade
            if((qualComparar1 == 2 && qualComparar2 == 5)||(qualComparar2 == 2 && qualComparar1 == 5)){
                if(maiorArea == 1){
                   printf("Resultado Área: Carta 1 (%s) tem a maior área!\n", cidade1);
                   pontosCarta1++; 
                }else if(maiorArea == 0){
                    printf("Resultado Área: Carta 2 (%s) tem a maior área!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Área!\n");
                }
                if(menorDensidade == 1){
                    printf("Resultado Densidade: Carta 1 (%s) tem a menor densidade!\n", cidade1);
                    pontosCarta1++;
                }else if(menorDensidade == 0){
                    printf("Resultado Densidade: Carta 2 (%s) tem a menor densidade!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Densidade!\n");
                }
            }

            // se a comparação for entre Área e também entre Pib Per Capital
            if((qualComparar1 == 2 && qualComparar2 == 6)||(qualComparar2 == 2 && qualComparar1 == 6)){
                if(maiorArea == 1){
                   printf("Resultado Área: Carta 1 (%s) tem a maior área!\n", cidade1);
                   pontosCarta1++; 
                }else if(maiorArea == 0){
                    printf("Resultado Área: Carta 2 (%s) tem a maior área!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Área!\n");
                }
                if(maiorPibPerCapital == 1){
                    printf("Resultado PIB per Capital: Carta 1 (%s) tem o maior PIB per Capital!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPibPerCapital == 0){
                    printf("Resultado PIB per Capital: Carta 2 (%s) tem o maior PIB per Capital!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB per Capital!\n");
                }
            }

            // se a comparção for entre PIB e também entre Pontos Turísticos
            if((qualComparar1 == 3 && qualComparar2 == 4)||(qualComparar2 == 3 && qualComparar1 == 4)){
                if(maiorPib == 1){
                    printf("Resultado PIB: Carta 1 (%s) tem o maior PIB!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPib == 0){
                    printf("Resultado PIB: Carta 2 (%s) tem o maior PIB\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB!\n");
                }
                if(maiorPontosTuristicos == 1){
                    printf("Resultado Pontos Turísticos: Carta 1 (%s) tem mais pontos turísticos!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPontosTuristicos == 0){
                    printf("Resultado Pontos Turísticos: Carta 2 (%s) tem mais pontos turísticos!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Pontos Turísticos\n");
                }
            }

            // se a comparação for entre PIB e também entre Densidade
            if((qualComparar1 == 3 && qualComparar2 == 5)||(qualComparar2 == 3 && qualComparar1 == 5)){
                if(maiorPib == 1){
                    printf("Resultado PIB: Carta 1 (%s) tem o maior PIB!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPib == 0){
                    printf("Resultado PIB: Carta 2 (%s) tem o maior PIB\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB!\n");
                }
                if(menorDensidade == 1){
                    printf("Resultado Densidade: Carta 1 (%s) tem a menor densidade!\n", cidade1);
                    pontosCarta1++;
                }else if(menorDensidade == 0){
                    printf("Resultado Densidade: Carta 2 (%s) tem a menor densidade!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Densidade!\n");
                }
            }

            // se a comparação for entre PIB e também entre Pib Per Capital
            if((qualComparar1 == 3 && qualComparar2 == 6)||(qualComparar2 == 3 && qualComparar1 == 6)){
               if(maiorPib == 1){
                    printf("Resultado PIB: Carta 1 (%s) tem o maior PIB!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPib == 0){
                    printf("Resultado PIB: Carta 2 (%s) tem o maior PIB\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB!\n");
                }
                if(maiorPibPerCapital == 1){
                    printf("Resultado PIB per Capital: Carta 1 (%s) tem o maior PIB per Capital!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPibPerCapital == 0){
                    printf("Resultado PIB per Capital: Carta 2 (%s) tem o maior PIB per Capital!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB per Capital!\n");
                }
            }

            // se a comparação for Pontos Turísticos e também entre Densidade
            if((qualComparar1 == 4 && qualComparar2 == 5)||(qualComparar2 == 4 && qualComparar1 == 5)){
              if(maiorPontosTuristicos == 1){
                    printf("Resultado Pontos Turísticos: Carta 1 (%s) tem mais pontos turísticos!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPontosTuristicos == 0){
                    printf("Resultado Pontos Turísticos: Carta 2 (%s) tem mais pontos turísticos!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Pontos Turísticos\n");
                }
                if(menorDensidade == 1){
                    printf("Resultado Densidade: Carta 1 (%s) tem a menor densidade!\n", cidade1);
                    pontosCarta1++;
                }else if(menorDensidade == 0){
                    printf("Resultado Densidade: Carta 2 (%s) tem a menor densidade!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Densidade!\n");
                }  
            }

            // se a comparação for entre Pontos Turísticos e também entre Pib Per Capital
            if((qualComparar1 == 4 && qualComparar2 == 6)||(qualComparar2 == 4 && qualComparar1 == 6)){
               if(maiorPontosTuristicos == 1){
                    printf("Resultado Pontos Turísticos: Carta 1 (%s) tem mais pontos turísticos!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPontosTuristicos == 0){
                    printf("Resultado Pontos Turísticos: Carta 2 (%s) tem mais pontos turísticos!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Pontos Turísticos\n");
                }
                if(maiorPibPerCapital == 1){
                    printf("Resultado PIB per Capital: Carta 1 (%s) tem o maior PIB per Capital!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPibPerCapital == 0){
                    printf("Resultado PIB per Capital: Carta 2 (%s) tem o maior PIB per Capital!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB per Capital!\n");
                } 
            }

            // se a comparação for entre Densidade e também entre Pib Per Capital
            if((qualComparar1 == 5 && qualComparar2 == 6)||(qualComparar2 == 5 && qualComparar1 == 6)){
                 if(menorDensidade == 1){
                    printf("Resultado Densidade: Carta 1 (%s) tem a menor densidade!\n", cidade1);
                    pontosCarta1++;
                }else if(menorDensidade == 0){
                    printf("Resultado Densidade: Carta 2 (%s) tem a menor densidade!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em Densidade!\n");
                }
                if(maiorPibPerCapital == 1){
                    printf("Resultado PIB per Capital: Carta 1 (%s) tem o maior PIB per Capital!\n", cidade1);
                    pontosCarta1++;
                }else if(maiorPibPerCapital == 0){
                    printf("Resultado PIB per Capital: Carta 2 (%s) tem o maior PIB per Capital!\n", cidade2);
                    pontosCarta2++;
                }else{
                    printf("Empate em PIB per Capital!\n");
                }  
            }

            /* Comparação pontos */
            if(pontosCarta1 > pontosCarta2){ 
                printf("A carta 1 (%s) foi a campeã com %i pontos!!!!\n", cidade1, pontosCarta1);
            }else if(pontosCarta2 > pontosCarta1){
                printf("A carta 2 (%s) foi a campeã com %i pontos!!!!\n", cidade2, pontosCarta2);
            }else{
                printf("Empate das Cartas!! ambas fizeram (%i)\n", pontosCarta1);
            }
            printf("==================================\n");
            
        break;
        case 3:
            printf("Carta 1 - %s (%c%s)\n", cidade1, estado1, cdCarta1);
            printf("Carta 2 - %s (%c%s)\n", cidade2, estado2, cdCarta2);

            /* comparação população */
            if (maiorPopulacao == 1){  
                printf("Resultado População: Carta 1 (%s) tem a maior populção!\n", cidade1);
                pontosCarta1++;
            }else if (maiorPopulacao == 0){   
                printf("Resultado População: Carta 2 (%s) tem a maior população!\n", cidade2);
                pontosCarta2++;
            }else{  
                printf("Empate em Populçação!\n");
            }

            /* Comparação área */
            if (maiorArea == 1){ 
                printf("Resultado Área: Carta 1 (%s) tem a maior área!\n", cidade1);
                pontosCarta1++;
            }else if (maiorArea == 0){ 
                printf("Resultado Área: Carta 2 (%s) tem a maior área!\n", cidade2);
                pontosCarta2++;
            }else{  
                printf("Empate em Área!\n");
                    }

            /* Comparação PIB */
            if(maiorPib == 1){  
                printf("Resultado PIB: Carta 1 (%s) tem o maior PIB!\n", cidade1);
                pontosCarta1++;
            }else if(maiorPib == 0){  
                printf("Resultado PIB: Carta 2 (%s) tem o maior PIB\n", cidade2);
                pontosCarta2++;
            }else{  
                printf("Empate em PIB!\n");
            }

            /* Comparção Pontos Turísticos */
            if(maiorPontosTuristicos == 1){   
                printf("Resultado Pontos Turísticos: Carta 1 (%s) tem mais pontos turísticos!\n", cidade1);
                pontosCarta1++;
            }else if(maiorPontosTuristicos == 0){  
                printf("Resultado Pontos Turísticos: Carta 2 (%s) tem mais pontos turísticos!\n", cidade2);
                pontosCarta2++;
            }else{  
                printf("Empate em Pontos Turísticos\n");
            }

            /* Comparação densidade */
            if(menorDensidade == 1){  
                printf("Resultado Densidade: Carta 1 (%s) tem a menor densidade!\n", cidade1); 
                pontosCarta1++;
            }else if(menorDensidade == 0){  
                printf("Resultado Densidade: Carta 2 (%s) tem a menor densidade!\n", cidade2);
                pontosCarta2++;
            }else{  
                printf("Empate em Densidade!\n"); 
            }

            /* Comparação PIB per capital */
            if(maiorPibPerCapital == 1){  
                printf("Resultado PIB per Capital: Carta 1 (%s) tem o maior PIB per Capital!\n", cidade1);
                pontosCarta1++; 
            }else if(maiorPibPerCapital == 0){  
                printf("Resultado PIB per Capital: Carta 2 (%s) tem o maior PIB per Capital!\n", cidade2);
                pontosCarta2++;
            }else{  
                printf("Empate em PIB per Capital!\n");
            }

            /* Comparação pontos */
            if(pontosCarta1 > pontosCarta2){ 
                printf("A carta 1 (%s) foi a campeã com %i pontos!!!!\n", cidade1, pontosCarta1);
            }else if(pontosCarta2 > pontosCarta1){
                printf("A carta 2 (%s) foi a campeã com %i pontos!!!!\n", cidade2, pontosCarta2);
            }else{
                printf("Empate das Cartas!! ambas fizeram (%i)\n", pontosCarta1);
            }
            printf("==================================\n");
            break;
            case 4:
                  /* Saida de dados carta 1 */
                printf("==================================\n");
                printf("Carta 1\n");
                printf("Estado: %c\n", estado1);
                printf("Código: %c%s\n", estado1, cdCarta1);
                printf("Nome da cidade: %s\n", cidade1);
                printf("População: %lu\n", populacao1);
                printf("Área: %.2f km²\n", area1);
                printf("PIB: %.2f bilhoes de reais\n", pib1);
                printf("Numero de Pontos Turísticos: %d\n", pontosTuristicos1);
                printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
                printf("PIB per Capital: %.2f reais\n", pibPerCapital1);
                printf("==================================\n");
                printf("\n");

                /* Saida de dados carta 2 */
                printf("Carta 2\n");
                printf("Estado: %c\n", estado2);
                printf("Código: %c%s\n", estado2, cdCarta2);
                printf("Nome da cidade: %s\n", cidade2);
                printf("População: %lu\n", populacao2);
                printf("Área: %.2f km²\n", area2);
                printf("PIB: %.2f bilhoes de reais\n", pib2);
                printf("Numero de Pontos Turísticos: %d\n", pontosTuristicos2);
                printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
                printf("PIB per Capital: %.2f reais\n", pibPerCapital2);
                printf("==================================\n");
                printf("\n");
            break;
            default:
                printf("Opção Invalida.\n");
            break;
            }
    return 0;
}