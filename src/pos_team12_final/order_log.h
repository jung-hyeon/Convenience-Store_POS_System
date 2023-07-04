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
        list<order>log_list; //order��ϵ��� ���� log_list
    public:
        //public method
        bool is_exist_order(int order_id); //order_log���� �ش�Ǵ� order_id �����ϴ��� �Ǵ�
        void order_push(order* myorder); //order�� log_list�� push
        order* order_pop(int order_id); //order�� log_list���� pop

    };
}