#include<iostream>
using namespace std;
class sl {
    struct node {
        int data;
        node*next;
    };
    node*start;
  public:
    sl() {
        start=NULL;
    };
    void insertatlast(int data) {
        node*n=new node;
        n->data=data;
        n->next=NULL;
        if(!start) {
            start=n;
        } else {
            node*a=start;
            while(a->next) {
                a=a->next;
            }
            n->next=a->next;
            a->next=n;
        }
    }
    void print() {
        node*b=start;
        while(b) {
            cout<<b->data;
            b=b->next;
        }

    }
    node*findmid(node*head){
    node*slow=head;
    node*fast=head->next;
    while(fast and fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
    }
    node*merge(node*a,node*b){
    node*r=NULL;
    if(!a){
        return b;
    }
    if(!b){
        return a;
    }
    if(a->data<b->data){
        r=a;
        r->next=merge(a->next,b);
    }else {
    r=b;
    r->next=merge(a,b->next);
    }
    return r;
    }
node*mergefunction(node*head){
if(!head || !head->next){
    return head;
}
node*mid=findmid(head);
node*left=head;
node*right=mid->next;
mid->next=NULL;
left=mergefunction(left);
right=mergefunction(right);

node*result=merge(left,right);

return result;
}
    void usemergesort() {
        node*a=start;
        start=mergefunction(a);
    }
};
int main() {
    sl obj;
    obj.insertatlast(5);
    obj.insertatlast(4);
    obj.insertatlast(3);
    obj.insertatlast(2);
    obj.insertatlast(1);
    obj.usemergesort();
    obj.print();


    return 0;
}
