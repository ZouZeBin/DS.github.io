#define SIZE 10
int a[SIZE];
int* load()
{ 
FILE *fp;
int i;
fp=fopen("input.txt","r");
for(i=0;i<SIZE;i++) fscanf(fp,"%d",&a[i]);
//printf("%d,",a[i]);
fclose(fp);
return a;
}
void save(int m,int n)
{ FILE *fp;
int i;
if((fp=fopen("output.txt","w"))==NULL) {
printf("cannot open file.\n"); return;
}
fprintf(fp,"%d,%d\n",m,n);
fclose(fp);
}

