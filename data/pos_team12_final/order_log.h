#pragma once
#include <list>
#include <iostream>
#include <string>
#include "order.h"

using namespace std;

namespace pos {
    class order_log {
    private:
        //private property
        list<order>log_list; //order기록들이 담기는 log_list
    public:
        //public method
        bool is_exist_order(int order_id); //order_log에서 해당되는 order_id 존자하는지 판단
        void order_push(order* myorder); //order를 log_list에 push
        order* order_pop(int order_id); //order를 log_list에서 pop

    };
}