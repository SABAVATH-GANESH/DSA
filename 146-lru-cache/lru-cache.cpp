class LRUCache {
public:
    struct node{
       node* prv;
       node* next;
       int k;;
       int val;
    };
    unordered_map<int,node*> mp;
    int c;
    node * head=new node();
    node * tail=new node();
    LRUCache(int capacity) {
        c=capacity;
        head->next=tail;
        tail->prv=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node * temp=mp[key];
            d(temp);
            a(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node *temp=mp[key];
            temp->val=value;
            d(temp);
            a(temp);
        }else{
             if(c==mp.size()){
                mp.erase((tail->prv)->k);
                d(tail->prv);
            }
            node * temp1=new node();
            temp1->val=value;
            temp1->k=key;
            mp[key]=temp1;
            a(temp1);
        }

    }
    void a(node * temp){
        node *t=head->next;
        head->next=temp;
        temp->next=t;
        temp->prv=head;
        t->prv=temp;
    }
    void d(node * temp){
        node * t=temp->next;
        node * p=temp->prv;
        p->next=t;
        t->prv=p;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */