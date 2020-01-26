#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>

#define UNITARIO 4.50
#define ICMS 0.18
#define IPI 0.04
#define PIS 0.0186
#define CONFINS 0.0854
#define TAM 30
#define DESC 4.05 //desconto de 10%  no valor da unidade


//calculo do valor total da carga sem o imposto c/ DESCONTO
float calculaVTSIcomDESC(int qtd){
	float total=DESC*qtd;
	return total;
}


//calculo do valor total da carga sem o imposto
float calculaValorTotalSemImposto(int qtd){
	float total=UNITARIO*qtd;
	return total;
}

//calculo do imposto da carga
float calculaImposto(float valortotalsemimposto){
	float total=((valortotalsemimposto*ICMS)+(valortotalsemimposto*IPI)+(valortotalsemimposto*PIS)+(valortotalsemimposto*CONFINS));
	return total;
}

//calculo valor total da carga *com o imposto
float calculaValorTotal(float valorsemimposto,float totalimposto){
	float total=valorsemimposto+totalimposto;
	return total;
}




main(){
	char nomecliente[TAM+1],opdesc;
	int qtdcomprada,opcao=1;
	float valortotalsemimpostocarga,totalimpostocarga,valortotalcarga; //para cada carga
	float valortotalsemimposto=0,totalimposto=0,valortotal=0; //para soma de todas as cargas
	
	do{
		//entradas
		printf("Insira um cliente:\n");
		fgets(nomecliente,TAM,stdin);
		while (nomecliente[0]=='\n'){
			//while(fgetc(stdin)!='\n');
			printf("Digite um nome valido!\n");
			fgets(nomecliente,TAM,stdin);
		 }
		 
		
		printf("\nInsira a quantidade comprada:\n");
		while(scanf("%i",&qtdcomprada)==0){
			printf("Digite um numero valido!\n");
			while(fgetc(stdin)!='\n');	
		 }
		
		
		if(qtdcomprada>=1000){//quantidade escolhida para estar apta ao desconto
			while(fgetc(stdin)!='\n');	
			printf("Deseja aplicar desconto? TECLE 'S' para sim: ");
			scanf("%c",&opdesc);
		 	switch(opdesc){
		 		case 'S': case 's':
		 			valortotalsemimpostocarga=calculaVTSIcomDESC(qtdcomprada);
		 			printf("Desconto de 10%c aplicado!\n",37);
		 			break;
				default:
					valortotalsemimpostocarga=calculaValorTotalSemImposto(qtdcomprada);
					printf("Densconto nao aplicado!\n");
					break;
			 }//fim switch case
		 	
		 }else{
		 	valortotalsemimpostocarga=calculaValorTotalSemImposto(qtdcomprada);
		 }//fim else
		
		
		//processamento das funções -individual 
		totalimpostocarga=calculaImposto(valortotalsemimpostocarga);
		valortotalcarga=calculaValorTotal(valortotalsemimpostocarga,totalimpostocarga);
		
		
		//saída individual
		printf("\nCliente:%s\n",nomecliente);
		printf("ICMS: R$%.2f IPI: R$%.2f PIS: R$%.2f CONFINS: R$%.2f     TOTAL: R$%.2f\n",valortotalsemimpostocarga*ICMS,valortotalsemimpostocarga*IPI,valortotalsemimpostocarga*PIS,valortotalsemimpostocarga*CONFINS,valortotalcarga);
		
		
		//valortotalsemimposto=0,totalimposto=0,valortotal=0
		valortotalsemimposto=valortotalsemimpostocarga+valortotalsemimposto;
		totalimposto=totalimpostocarga+totalimposto;
		valortotal=valortotalsemimposto+totalimposto;
		
		
		//Validação par continua o laço
		printf("\nPara sair pressione 0 ou qualquer outra tecla para continuar\n");
		scanf("%i",&opcao);
		while(fgetc(stdin)!='\n');
		// limpa lixo do teclado
			
	}while(opcao!=0);//fim do while
	
	
	//saídas todos!
		printf("\nTotal imposto: %.2f\n",totalimposto);
		printf("Total mercadorias: %.2f\n",valortotalsemimposto);
		printf("Total geral: %.2f\n",valortotal);
	
}//fim da main
