/*
Codeforces-161D
WA on Test Case 4
*/

#include <iostream>
#define N 50001
#define ll long long
using namespace std;

struct node{
    struct node* parent;
    struct child* head;
    struct child* tail;
};
struct node* x[N];

struct child{
    int n;
    struct child* next;
};

ll int dp[N][501];

struct node* getnode(){
    struct node* temp=new node;
    temp->parent=NULL;
    temp->head=temp->tail=NULL;
    return temp;
}

int insert_edge(int par,int ch){
    if (x[par]==NULL) x[par]=getnode();
    if (x[ch]==NULL){
        x[ch]=getnode();
        x[ch]->parent=x[par];
    }
    struct child* temp=new child();
    temp->n=ch;
    temp->next=NULL;
    if (x[par]->head==NULL){
        x[par]->head=x[par]->tail=temp;
    }
    else{
        (x[par]->tail)->next=temp;
        x[par]->tail=temp;
    }
    return 0;
}
/*
Calculates number of nodes below c depth from a node x[n]
*/
ll int nodes_below(int n,int c){
    if (dp[n][c]>0) return dp[n][c];
    struct node* croot=x[n];
    struct child* temp=croot->head;
    if (c==1){
        ll int num=0;
        while (temp!=NULL){
            num++;
            temp=temp->next;
        }
        dp[n][c]=num;
        return num;
    }
    if (croot->head==NULL){
        return 0;
    }
    ll int sum=0;
    while (temp!=NULL){
        sum+=(nodes_below(temp->n,c-1));
        temp=temp->next;
    }
    dp[n][c]=sum;
    return sum;
}

ll int s[N];
int main(){
    int p,c,k,n;
    cin >> n >> k;
    if (n==1){
        cout << "0" << endl;
        return 0;
    }
    for (int i=0;i<n-1;i++){
        cin >> p >> c;
        insert_edge(p,c);
    }
    ll int sum=0,a,b,na,nb;
    for (int i=1;i<=n;i++){
        sum+=(nodes_below(i,k));
        a=k-1;
        b=1;
        while (a>b){
            na=nodes_below(i,a);
            nb=nodes_below(i,b);
            sum+=(na*(nb-1));
            b++;
            a--;
        }
        if (a==b){
            na=nodes_below(i,a);
            sum+=((na*(na-1))/2);
        }
    }
    cout << sum << endl;
    return 0;
}
