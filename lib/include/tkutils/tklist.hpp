#ifndef tklist_hpp
#define tklist_hpp

#include <stdio.h>
#include <list>

using namespace std;

namespace tkht {

template <class T, class Alloc = allocator<T> >
class TKList {

    typedef typename list<T>::iterator iterator;
    
private:
    list<T> _repeats;
    
public:
    list<T> vlist;
    
    TKList() {
        TKList(list<T>());
    }
    
    TKList(list<T> vlist) {
        this->vlist = vlist;
    }
    
    unsigned long size() {
        return vlist.size();
    }
    
    T front() {
        return vlist.front();
    }
    
    T back() {
        return vlist.back();
    }
    
    //operator
    TKList& operator=(list<T> __vl) {
        this->vlist = __vl;
        return *this;
    }
    
    void operator<<=(T __v) {
        if (contain(__v)) {
            erase_exist(__v);
            repeat_push(__v);
        } else if (repeat(__v)) {
            
        } else {
            push_back(__v);
        }
    }
    
    void operator-=(TKList __l) {
        for (T __v : __l) {
            erase_exist(__v);
        }
    }
    
    void operator+=(TKList __l) {
        for (T __v : __l) {
            push_back(__v);
        }
    }
    
    void operator-=(T __v) {
        erase_exist(__v);
    }

    void operator+=(T __v) {
        push_back(__v);
    }
    
    TKList operator-(TKList __l) {
        TKList that = TKList(this->vlist);
        for (T __v : __l) {
            that.erase_exist(__v);
        }
        return that;
    }
    
    //iterator
    
    iterator begin() {
        return vlist.begin();
    }
    
    iterator end() {
        return vlist.end();
    }
    
    iterator find(T __v) {
        return std::find(begin(), end(), __v);
    }
    
    bool contain(T __v) {
        return find(__v) != end();
    }
    
    bool repeat(T __v) {
        return std::find(_repeats.begin(), _repeats.end(), __v) != _repeats.end();
    }
    
    //push
    
    void push_back(T __v) {
        vlist.push_back(__v);
    }
    
    //repeat
    
    void repeat_push(T __v) {
        _repeats.push_back(__v);
    }
    
    void repeat_clear() {
        _repeats.clear();
    }
    
    //erase
    
    void erase(iterator __it) {
        vlist.erase(__it);
    }

    void erase_exist(T __v) {
        iterator it = find(__v);
        bool nonexist = it == end();
        if (!nonexist) erase(it);
    }
};

}

#endif /* tklist_hpp */
