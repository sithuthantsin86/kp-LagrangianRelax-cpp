#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"MKnapsack.h"
#include"LagrangianRelax.h"
int main(int argc, char* argv[]){
    KnapData mData;
    double lamda, *L, g;
    lamda=1;
    g=0;
	char* str = NULL;
    if(argc >= 2){
      	str = argv[1];
   	}
    else{
      	fprintf(stderr, "usage: %s <input_file>\n", argv[0]);
    	exit(-1);
    }
    MKnapsack MK(str);
    mData = MK.getData();
    MK.printInputData();
    L = (double *)malloc(mData.N+1*sizeof(double));
	if(L == NULL){
        std::cerr<<"Error : Your size is too much for <l>.\n";exit(1);
    }
    LagrangianRelax LR(mData.p, mData.w, mData.c, mData.N, lamda, g);
    L = LR.getLagrangianRelaxResult();
    LR.printLagrangianRelaxResult();
	return 0;
}