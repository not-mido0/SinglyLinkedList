#include <iostream>
using namespace std; 

struct node{
    int data ; 
    node * next ; 
    node(int val) : data(val), next(nullptr){};
};

class LinkedList{
private:
    node *head ;
    int cnt ; 

    void print_recursive(node * temp ){ // Time O(n), Space O(n)
         
        if (temp)
        {
            cout << temp->data << " "; 
            print_recursive(temp->next);
        }
    }

    void print_recursive_reverse(node * temp ){ // Time O(n), Space O(n)
         
        if (temp)
        {
            print_recursive_reverse(temp->next);
            cout << temp->data << " "; 
        }
    }
    void clear() { // Time O(n), Space O(1)
    while (head != nullptr) {
    delete_front();
    }   

}

    int max_recursive(node* curr) {   // Time O(n), Space O(n) 
        if (curr->next == nullptr) {
            return curr->data;
        }
        int res = max_recursive(curr->next);
        if (curr->data > res)
            return curr->data;
        else
            return res;
    }

    node * move_and_remove(node * temp ){ // Time O(1), Space O(1)
        node * to_delete = temp ; 
        temp = temp->next;
        delete to_delete;
        cnt--;
        return temp ;
    }

public:
    LinkedList(): head(nullptr) , cnt(0){};

    bool is_Empty (){ // Time O(1), Space O(1) 
        return cnt == 0 ;
    }

    int size(){ // Time O(1), Space O(1)
        return cnt ; 
    }

    int get_front(){ // Time O(1), Space O(1)
        return head->data;
    }

    int get_last(){ // Time O(n), Space O(1)
        if(!head) return -1 ; 
        node* p = head; 
        while(p->next){
            p = p->next;
        }
        return p->data;
    }

    bool find(int val){ // Time O(n), Space O(1)
        if (!head)
        {
            return false ; 
        }
        for(node * p = head ; p ; p=p->next){
            if (p->data == val )
            {
                return true;
            }
            
        }
        return false; 
    }

    int index_of(int val){ // Time O(n), Space O(1)
        if (!head)
        {
            return -1 ; 
        }
        int i = 0 ; 
        for(node * p = head   ; p ; p=p->next  ){
            if (p->data == val )
            {
                return i;
            }
            i++;
        }
        return -1 ;
    }

    void insert_front(int val){ // Time O(1), Space O(1)
        node * p = new node(val);
        p->next=head;
        head = p ;
        cnt++;
    }

    void insert_last(int val ){ // Time O(n), Space O(1)

        if (!head)
        {
            insert_front(val); 
        }else
        {
            node *temp = head ;
            node *nw = new node(val);
            while (temp->next)
            {
                temp = temp->next;
            }
            temp ->next = nw ; 
            cnt ++ ;         
        }
    }

    void insert_at(int index, int val){ // Time O(n), Space O(1)
        if (index < 0 || index > cnt )
        {
            cout << "invalid Position";
            return;
        }
        
        if (index == 0 )
        {
            insert_front(val);
        }
        else if (index == cnt  )
        {
            insert_last(val);
        }else
        {
            node *nw = new node(val);
            node *p = head;
            node *prev = nullptr; 
            for (int i = 0 ; i < index ; ++i)
            {
                prev= p ; 
                p= p->next;
            }
            prev->next = nw ; 
            nw->next =p ;
            cnt ++ ;
        }   
    }
    
    int delete_front(){ // Time O(1), Space O(1)
        if (!head)
        {return -1;}
        node *p = head ; 
        head =head->next;
        int x= p->data;
        delete p ; 
        cnt--;
        return x; 
    }

    int delete_last(){ // Time O(n), Space O(1)
        if (!head)
        {
            return -1;
        }
        if (!head->next)
        {
            delete_front();
        }
        else
        {
            node * p = head; 
            node * prev = nullptr;
            while (p->next)
            {
                prev = p ;  
                p=p->next;
            }
            int x = p->data;
            prev->next = nullptr ; 
            delete p ; 
            cnt--;
            return x; 
        }
        return -1 ; 
    }
    
    int delete_at(int index){ // Time O(n), Space O(1)
        if (!head)
        {
            return -1 ;
        }
        if (index == 0 )
        {
            delete_front();
        }
        else if (index == cnt -1 )
        {
            delete_last();
        }
        else
        {
            node *curr = head; 
            node * prev = nullptr; 
            for (int i = 0 ; i < index ; ++i)
            {
                prev = curr;
                curr = curr ->next;
            }
            prev->next =curr->next;
            int x = curr->data;
            delete curr ;
            cnt--;
            return x ; 
        }        
        return -1 ; 
    }
    
    int delete_node_with_key(int value){ // Time O(n), Space O(1)
        if (!head)
        {
            return -1 ;
        }
        if (head->data == value) {
            return  delete_front();
        }
        node *curr = head;
        node *prev = nullptr;
        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        
        if (curr == nullptr) {
            cout << "Value not found!" << endl;
            return -1 ;
        }
        int x = curr->data;
        prev->next = curr->next;
        delete curr;
        cnt--;
        return x ;
    }

    void print(){ // Time O(n), Space O(1)
        node *p = head; 
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void recursive_print(){ //Time O(n), Space O(n)
        print_recursive(head);
        cout << endl ;
    } 

    void recursive_print_reverse(){ // Time O(n), Space O(n)
        print_recursive_reverse(head);
        cout << endl ; 
    }

    ~LinkedList(){
        clear();
    }

    // dr_mostafa_saad's homework 
    
    void swap_pairs(){ // Time O(n), Space O(1) 
        for (node *temp = head ; temp ; temp = temp->next)
        {
            if (temp->next)
            {
                swap(temp->data,temp->next->data);
                temp = temp->next;
            }
            
        }
    }
    
    void delete_even_pos(){ // Time O(n), Space O(1)
        node *prev = nullptr ; 
        node *cur = head; 
        while (cur && cur->next)
        {
            prev = cur ; 
            cur = cur->next;
            prev ->next = cur->next;
            delete cur ; 
            cur = prev->next;
            cnt--;
        }
    }

    void insert_to_be_sorted(int val){ // Time O(n), Space O(1)
        if (!head || val <= head->data)
        {
            insert_front(val);
        }else{
            node *p = head; 
            while (p->next != nullptr && p->next->data < val) {
                p = p->next;
            }
            node* nw = new node(val);
            nw->next = p->next;
            p->next=nw ; 
            cnt++ ;
        }
    }
    
    void reverse_nodes_implace(){ // Time O(n), Space O(1)
        if (!head || !head->next)
        {
            return;
        }
        node *prev =nullptr;
        node *curr = head ;
        node *n =nullptr;
        while (curr != nullptr)
        {
            n = curr->next;
            curr->next = prev;

            prev = curr;
            curr=n ;
        }
        head = prev;
    }

    void reverse_head_tail(){ // Time O(n), Space O(1)
        if (!head || !head->next) return;

        // if the list has only 2 values 
        if (head->next->next == nullptr) {
            node* tail = head->next;
            tail->next = head;
            head->next = nullptr;
            head = tail;
            return;
        }
        // if the list has 3 or more 
        // this code gonna take o(n) time because i don't have tail 
        node *tail = head ; 
        node *prev = nullptr ; 
        while (tail->next)
        {
            prev = tail ; 
            tail = tail->next;
        }
        // we've got the tail and the node before it 

        node *p = head->next;

        head->next = nullptr; 
        prev->next = head; 
        tail->next=p;

        head = tail;
    }

    void print_with_addresses() { // Time O(n), Space O(1)
        node* curr = head;
        while (curr != nullptr) {
            cout << "[" << curr << "] -> Value: " << curr->data << endl;
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }   

    node* get_nth(int n) { // Time O(n), Space O(1)
		int c = 0;
		for (node* cur = head; cur; cur = cur->next)
			if (++c == n)
				return cur;

		return nullptr;
	}

    void left_rotate(int k ){ // Time O(n), Space O(1)
        if (!head)
        {
            return ;
        }
        node *to_rotate=get_nth(k);
        node *tail = get_nth(cnt);
        node *after_to = get_nth(k+1);
        tail->next = head ;
        to_rotate->next = nullptr;
        head = after_to;
    }

    void rm_duplicates(){  // Time O(n), Space O(1)
        for (node *p = head ; p && p->next ; p=p->next)
        {
            node *prev = p ; 
            node *curr =p->next;
            while (curr)
            {
                if (p->data == curr->data )
                {
                    prev->next = curr->next;
                    delete curr ;
                    curr= prev->next;
                    cnt--;
                }else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }
    
    int remove_last_occurness(int key){ // Time O(n), Space O(1)
        if (!head)
        {
            return -1;
        }
        
        node *found = nullptr;
        int idx= -1 , i = 0 ;
        for (node *p =head ; p ; p = p->next) 
        {
            if (p->data == key)
            {
                found = p ; 
                idx = i ; 
            }
            i++;   
        }
        if (idx == -1 )
        {
            return -1 ;
        }
        
        if (idx ==0)
        {
            return delete_front();
        }
        if (idx == cnt-1)
        {
            return delete_last();
        }else{
        node *prv = get_nth(idx);
        prv->next = found->next;
        delete found;
        cnt--;
        return idx ;
    }
    }

    void move_to_back(int key){ // Time O(n), Space O(1) 
        node* old_tail = get_nth(cnt);
        node* tail = old_tail;
        node* curr = head;
        node* prev = nullptr;
        int current_cnt = cnt;
        
        for (int i = 0; i < current_cnt; ++i) {
            if (curr->data == key && curr != tail) {
                node* nex = curr->next;

                if (prev) prev->next = nex;
                else head = nex;

                tail->next = curr;
                curr->next = nullptr;
                tail = curr;

                curr = nex;
            } else {
                prev = curr;
                curr = curr->next;
            }
    }
    }

    int max(){ //iterative  // Time O(n), Space O(1)
        node *n = head; 
        int max = -1 ; 
        while (n)
        {
            if (n->data > max)
            {
                max = n->data;
            }
            n = n->next;
        }
        return max ; 
    }

    int max_recu()  { // Time O(n), Space O(n)     
        if (!head) return -1; 
        return max_recursive(head);
    }

    void ArrangeODD_EVEN_Nodes(){ // Rearrange the nodes so that, odd nodes comes first and even nodes comes last
        // Time O(n), Space O(1)
        if (!head) return ; 
        node * odd= head;
        node * even = head->next;
        node * evenHead= even ;
        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
    }

    void insert_alternate(LinkedList &another){  //  Time O(min(n, m)), Space O(1)
        if (!head || !another.head) return ; 
        
        node * first_ = head ;
        node * sec_ = another.head;
        node *nex_fir = nullptr;
        node *nex_sec = nullptr; 
        while (first_ && sec_)
        {
            nex_fir = first_->next;
            nex_sec = sec_->next;
            first_->next = sec_;
            sec_->next = nex_fir;
            
            if (nex_fir) {
            sec_->next = nex_fir;
            }
            sec_ = nex_sec;
            first_=nex_fir;
        }
        cnt += another.cnt;
        another.head = nullptr;
        another.cnt = 0; 
    } 

    void add_2_numbers(LinkedList &another){ // Time O(max(n, m)), Space O(max(n, m))
        if (!another.head) return;

		node* my_cur = head;
		node* his_cur = another.head;
		int carry = 0, my_value, his_value;

        while (my_cur || his_cur)
        {
            my_value = 0, his_value = 0;
			if (my_cur)
				my_value = my_cur->data;
			if (his_cur) {
				his_value = his_cur->data;
				his_cur = his_cur->next;
			}

			my_value += his_value + carry;
			carry = my_value / 10;
			my_value %= 10;

			if(my_cur) {
				my_cur->data = my_value;
				my_cur = my_cur->next;
			}
			else
				insert_last(my_value);
        }
        if(carry)
			insert_last(carry);
        
    }
    
    void rm_dublicates_from_sorted(){ // Time O(n), Space O(1)
        
        insert_front(-50620); //dummy head  (good Practise)

        node * prv = head ; 
        node * cur = head ->next ;
        while (cur)
        {
            if (cur && cur->next && cur->data == cur->next->data )
            {
                int val = cur->data;
                while (cur && cur->data==val )
                {
                    cur = move_and_remove(cur);
                }
                prv->next = cur;
            }
            else {
                prv = cur;
                cur = cur->next;
            }
        }
        delete_front();
      
    }

    node* reverse_sub_list(node* current_head) { // Time O(n), Space O(1) 
    if (!current_head || !current_head->next) {
        return current_head;
    }

    node *prev = nullptr;
    node *curr = current_head;
    node *next_node = nullptr;

    while (curr != nullptr) {
        next_node = curr->next; 
        curr->next = prev;      

        prev = curr;           
        curr = next_node;       
    }
    
    return prev; 
}
    
    
    void reverse_chains(int k){  // Time O(n), Space O(1)
        if (!head || !head->next)
        {
            return;
        }
        if (k >= cnt) {
            reverse_nodes_implace();
            return;
        }
        
        node* kth_node = get_nth(k);
        node* after_kth = kth_node->next;

        kth_node->next = nullptr;
        node* old_head = head;
        head = reverse_sub_list(head);
        old_head->next = after_kth;
        
    }

    // "Acquire knowledge and impart it to the people.”
    // “Seek knowledge from the Cradle to the Grave.”
};



int main (){
    LinkedList ll ; 
    ll.insert_front(125);
    ll.insert_front(125);
    ll.insert_front(125);
    ll.insert_front(124);
    ll.insert_front(1);
    ll.insert_front(124);
    ll.insert_front(90);
    ll.insert_front(590);
    ll.print();
    
    ll.move_to_back(125);
    ll.print();
    // ll.ArrangeODD_EVEN_Nodes();
    ll.print();
    LinkedList an ; 
    // an.insert_last(50);
    // an.insert_last(51);
    // an.insert_last(51);
    // an.insert_last(51);
    // an.insert_last(52);
    // an.insert_last(52);

    // an.rm_dublicates_from_sorted();
    // an.print();
    ll.reverse_chains(9);
    ll.print();
    

}