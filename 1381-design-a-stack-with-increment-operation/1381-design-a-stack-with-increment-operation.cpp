class CustomStack {
private:
    int maxSize;
    int currSize;
    class Element {
        private:
            int value;
            Element* below;
            Element* above;
        public:
            Element(int val) {
                value = val;
                below = NULL;
                above = NULL;
            }
            Element(int val, Element* b, Element* a) {
                value = val;
                below = b;
                above = a;
            }
            void increment(int amount) {
                value += amount;
            }
            void resetAbove() {
                above = NULL;
            }
            void setAbove(Element* a) {
                above = a;
            }
            void setBelow(Element* b) {
                below = b;
            }
            Element* getBelow() {
                return below;
            }
            Element* getAbove() {
                return above;
            }
            int getValue() {
                return value;
            }
        };
    Element* bottom;
    Element* top;

public:
    CustomStack(int maxS) {
        maxSize = maxS;
        currSize = 0;
        bottom = NULL;
        top = NULL;
    }
    
    void push(int x) {
        if(currSize >= maxSize) {
            return;
        }
        Element* e = new Element(x);
        currSize++;
        if(bottom == NULL) {
            bottom = e;
            top = e;
            return;
        }
        top->setAbove(e);
        e->setBelow(top);
        top = e;
    }
    
    int pop() {
        if(currSize <= 0) {
            return -1;
        }
        if(currSize == 1) {
            int v = top->getValue();
            delete(top);
            top = NULL;
            bottom = NULL;
            currSize--;
            return v;
        }
        currSize--;
        Element* t = top;
        int v = t->getValue();
        top = t->getBelow();
        top->resetAbove();
        delete(t);
        return v;
    }
    
    void increment(int k, int val) {
        Element* e = bottom;
        for(int i = 0; i<k && e; i++) {
            e->increment(val);
            e = e->getAbove();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */