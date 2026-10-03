class LFUCache {
    struct node{
        node *next;
        node *prv;
        int val;
        int freq=0;
        int k;
    };
public:
    int c;
    unordered_map<int,node*> mp;
    node * head=new node();
    node * tail=new node();
    
    LFUCache(int capacity) {
        c=capacity;
        head->next=tail;
        tail->prv=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node * temp=mp[key];
            temp->freq=(temp->freq)+1;
            if((temp->prv)->freq <= (temp->freq)){
                   node *insertpoint=check(temp->prv,temp->freq);
                   deletenode(temp);
                   insertnode(temp,insertpoint);
            }
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node * temp=mp[key];
            temp->freq +=1;
            temp->val=value;
            if((temp->prv)->freq <= (temp->freq)){
                node *insertpoint=check(temp->prv,temp->freq);
                deletenode(temp);
                insertnode(temp,insertpoint);
            }

        }else{
            if(mp.size()==c){
                node *temp=tail->prv;
                mp.erase(temp->k);
                deletenode(temp);
                node * temp1=new node();
                temp1->k=key;
                temp1->val=value;
                temp1->freq +=1;
                node *insertpoint=check(tail->prv,temp1->freq);
                cout<<insertpoint->k<<endl;
                
                insertnode(temp1,insertpoint);
                mp[key]=temp1;
                cout<<(tail->prv)->k<<endl;
            }
            else{
                node * temp1=new node();
                temp1->k=key;
                temp1->val=value;
                temp1->freq +=1;
                mp[key]=temp1;
                node *insertpoint=check(tail->prv,temp1->freq);
                insertnode(temp1,insertpoint);
            }
        }
    }
    node * check(node *temp,int f){
        if(f>=(head->next)->freq) return head;
        while(temp->freq <= f){
              temp=temp->prv;
        }
        return temp;
    }
    void deletenode(node* temp){
        node * prve=temp->prv;
        node * after=temp->next;

        prve->next=after;
        after->prv=prve;
    }
    void insertnode(node * temp,node *point){
       node* after=point->next;
       point->next=temp;
       temp->next=after;
       after->prv=temp;
       temp->prv=point;
       
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */