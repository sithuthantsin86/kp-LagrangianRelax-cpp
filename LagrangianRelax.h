class LagrangianRelax{
    double *l, n;
    public:
    LagrangianRelax(double *p, double *w, double *c, double N, double lamda, double g){
        n = N;
        l = (double *)malloc(int(N)+1*sizeof(double));
	    if(l == NULL){std::cerr<<"Error : Your size is too much for <l>.\n";exit(1);}
        for(int i=0; i<int(N)+1; i++){
            if(p[i]-(lamda * w[i]) > 0){
                l[i] = p[i]-(lamda * w[i]);
            }
            else if(i==int(N)){
                l[i] = c[int(g)];
            }
            else
                l[i]=0;
        }
    }
    double* getLagrangianRelaxResult();
    void printLagrangianRelaxResult();
    ~LagrangianRelax(){
        delete l;
    }
};
double* LagrangianRelax::getLagrangianRelaxResult(){
    return l;
}
void LagrangianRelax::printLagrangianRelaxResult(){
    cout<<"\n\nL = ";
    for(int i=0; i<n+1; i++){
        cout << l[i] << " ";
    }
    cout<<"\n";
}