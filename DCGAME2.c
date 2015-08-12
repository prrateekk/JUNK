#include <stdio.h>
int a[1000000],count[1000000];
int i,n,j,l,r,ltemp,rtemp;
long long int sum=0;
int main(){
	scanf("%d",&n);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	i=0;
	while (i<n){
		if (i>0&&a[i]>a[i-1]){
			j=ltemp;
			while (j>=0){
				if (a[j]>a[i]) break;
				j--;
			}
			if (j>=0) ltemp=j;
			else ltemp=0;
			l=i-j;
		}
		else{
			l=1;
			ltemp=i;
		}
		if (i<n-1&&a[i]>a[i-1]){
			j=rtemp;
			while (j<n){
				if (a[j]>a[i]) break;
				j++;
			}
			if (j<n) rtemp=j;
			else rtemp=n-1;
			r=j-i;
		}
		else{
			j=i+1;
			while (j<n){
				if (a[j]>a[i]) break;
				j++;
			}
			if (j<n) rtemp=j;
			else rtemp=n-1;
			r=j-i;
		}
		count[i]=l*r;
		i++;
	}
	for (i=0;i<n;i++) sum+=(count[i]);
	if (sum==(n*(n+1))/2) printf("Correct");
	else printf("wrong\n%lld\n%lld",sum,(n*(n+1))/2);
	printf("\n");
	for (i=0;i<n;i++) printf("%d ",count[i]);
	return 0;	
}
