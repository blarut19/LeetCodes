class MyCircularDeque {
private:
    int elementCount;
    int maxElementCount;
    class Node{
        private:
            int value;
            Node* next;
            Node* prev;
        public:
            Node(int val) {
                value = val;
                next = NULL;
                prev = NULL;
            }
            Node(int val, Node* n, Node* p) {
                value = val;
                next = n;
                prev = p;
            }
            void setNext(Node* n){
                next = n;
            }
            void setPrev(Node* p){
                prev = p;
            }
            Node* getNext(){
                return next;
            }
            Node* getPrev(){
                return prev;
            }
            int getValue(){
                return value;
            }
    };
    Node* head;

public:
    MyCircularDeque(int k) {
        elementCount = 0;
        maxElementCount = k;
        head = NULL;
    }
    
    bool insertFront(int value) {
        if(insertLast(value)) {
            head = head->getPrev();
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(elementCount >= maxElementCount)
            return false;
        if(elementCount == 0) {
            Node* newNode = new Node(value);
            newNode->setNext(newNode);
            newNode->setPrev(newNode);

            head = newNode;

            elementCount++;
            return true;
        }
        Node* newNode = new Node(value, head, head->getPrev());
        head->getPrev()->setNext(newNode);
        head->setPrev(newNode);

        elementCount++;
        return true;
    }
    
    bool deleteFront() {
        if(elementCount == 0)
            return false;
        Node* h = head;
        head = h->getNext();
        head->setPrev(h->getPrev());
        h->getPrev()->setNext(head);
        elementCount--;
        delete(h);
        if(elementCount == 0) {
            head = NULL;
        }
        return true;
    }

    bool deleteLast() {
        if(elementCount == 0)
            return false;
        head = head->getPrev();
        deleteFront();

        return true;
    }
    
    int getFront() {
        if(head)
            return head->getValue();
        return -1;
    }
    
    int getRear() {
        if(head)
            return head->getPrev()->getValue();
        return -1;
    }
    
    bool isEmpty() {
        if(elementCount == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(elementCount == maxElementCount)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */