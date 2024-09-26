class MyCalendar {
public:
    vector<int> bookings_begins;
    vector<int> bookings_ends;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if(bookings_begins.empty()) {
            bookings_begins.push_back(start);
            bookings_ends.push_back(end);
            return true;
        }
        int i = 0;
        for(1; i<bookings_begins.size(); i++) {
            if(start >= bookings_ends[i]) {
                continue;
            }
            if(end > bookings_begins[i])
                return false;
            
            break;
        }
        bookings_begins.insert(bookings_begins.begin() + i, start);
        bookings_ends.insert(bookings_ends.begin() + i, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */