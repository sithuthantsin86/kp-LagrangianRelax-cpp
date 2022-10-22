using namespace std;
typedef struct{
    double N, N_g, *p, *w, *c;
}KnapData;

class MKnapsack{
	KnapData mData;
	public:
    MKnapsack(char* file_name){

        ifstream f;
	    f.open(file_name);
	    if(!f){
      	    std::cerr << "Error: file could not be opened for <f>." << std::endl;
      	    exit(1);
        }

	    f >> mData.N;
	    f >> mData.N_g;

	    mData.p = (double *)malloc(mData.N*sizeof(double));
	    if(mData.p == NULL){std::cerr<<"Error : Your size is too much for <p>.\n";exit(1);}

        mData.w = (double *)malloc(mData.N*mData.N_g*sizeof(double));
        if(mData.w == NULL){std::cerr<<"Error : Your size is too much for <w>.\n";exit(1);}

        mData.c = (double *)malloc(mData.N_g*sizeof(double));
        if(mData.c == NULL){std::cerr<<"Error : Your size is too much for <c>.\n";exit(1);}

        for(int i=0; i<mData.N; i++){
            f >> mData.p[i];
        }
        for(int i=0; i<mData.N_g; i++){
            for(int j=0; j<mData.N; j++){
                f >> mData.w[i*int(mData.N)+j];
            }
            f >> mData.c[i];
        }
    }
    KnapData getData();
    void printInputData();
    ~MKnapsack(){
        delete mData.p;
        delete mData.w;
        delete mData.c;
    }
};
KnapData MKnapsack::getData(){
    return mData;
}
void MKnapsack::printInputData(){
    cout<<"\nf(x) = ";
    for(int i=0; i<mData.N; i++){
        cout<<mData.p[i]<<" ";
    }
    cout<<"---> max;\n";  
    for(int i=0; i<mData.N_g; i++){
        cout<<"\ng" << i << " = ";
        for(int j=0; j<mData.N; j++){
            cout<< mData.w[i*int(mData.N)+j] << " ";
        }
        cout<< "<= " << mData.c[i] << "\n";
    }
    cout<<"\nThe number of items <N> = "<<mData.N;
    cout<<"\nThe number of limits = "<<mData.N_g;
}