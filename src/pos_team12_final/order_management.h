#pragma once
#include <iostream>
#include <list>
#include "account_management.h"
#include "stock_management.h"
#include "shopping_cart.h"
#include "cart_item.h"
#include "order_log.h"

using namespace std;

namespace pos {
    class order_management {

    private:
        int order_id;  //영수증 번호
        order_log* porder_log; //order log의 포인터


    public:
        //constructor
        order_management();

        //destructor
        ~order_management();

        void set_order_log(order_log* order_log); //order_log의 setter

        void order_run(shopping_cart& cart, int coupon, int payment, int age, int change, bool payment_type); //order 생성 후 order_log에 추가

        bool is_exist_order(int order_id); // order_log에서 해당되는 order_id 존자하는지 판단

        order* pop_order_log(int order_id); //order_log에서 해당되는 order pop하기 

        void push_to_log(order* new_order); //order_log에 새로운 order push하기

    };
}