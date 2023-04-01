#ifndef tkarray_hpp
#define tkarray_hpp

#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

namespace tkht
{

    template <class T, class Alloc = allocator<T>>
    class TKArray
    {

        typedef typename vector<T>::iterator iterator;

    private:
        set<T> r;
        vector<T> v;

    public:
        TKArray()
        {
            TKArray({});
        }

        TKArray(initializer_list<T> __v)
        {
            v = __v;
        }

        // calculate

        unsigned long size()
        {
            return v.size();
        }

        bool contain(T __v)
        {
            return find(__v) != end();
        }

        T front()
        {
            return v.front();
        }

        T back()
        {
            return v.back();
        }

        // operator

        T operator[](size_t pos)
        {
            return v[pos];
        }

        // operator v

        TKArray operator+(T __v)
        {
            TKArray that = copy();
            that += __v;
            return that;
        }

        TKArray operator-(T __v)
        {
            TKArray that = copy();
            that -= __v;
            return that;
        }

        void operator+=(T __v)
        {
            push(__v);
        }

        void operator-=(T __v)
        {
            erase(__v);
        }

        /// @brief push新元素，但移除重复添加的元素
        /// @param __v 新元素
        void operator^=(T __v)
        {
            if (!repeat(__v))
            {
                if (contain(__v))
                {
                    erase(__v);
                    repeat_push(__v);
                }
                else
                {
                    push(__v);
                }
            }
        }

        // operator a

        TKArray &operator=(vector<T> __a)
        {
            this->v = __a;
            return *this;
        }

        TKArray operator+(TKArray __a)
        {
            TKArray that = copy();
            that += __a;
            return that;
        }

        TKArray operator-(TKArray __a)
        {
            TKArray that = copy();
            that -= __a;
            return that;
        }

        void operator+=(TKArray __a)
        {
            for (T __v : __a)
            {
                push(__v);
            }
        }

        void operator-=(TKArray __a)
        {
            for (T __v : __a)
            {
                erase(__v);
            }
        }

        // actions

        void push(T __v)
        {
            v.push_back(__v);
        }

        void erase(T __v)
        {
            iterator it = find(__v);
            bool nonexist = it == end();
            if (!nonexist)
            {
                v.erase(it);
            }
        }

        TKArray copy()
        {
            TKArray that;
            that.v = this->v;
            return that;
        }

        // iterator

        iterator begin()
        {
            return v.begin();
        }

        iterator end()
        {
            return v.end();
        }

        iterator find(T __v)
        {
            return std::find(begin(), end(), __v);
        }

        // repeat

        bool repeat(T __v)
        {
            return r.count(__v);
        }

        void repeat_push(T __v)
        {
            r.insert(__v);
        }

        void repeat_clear()
        {
            r.clear();
        }
    };

}

#endif /* tkarray_hpp */
