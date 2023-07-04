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
        int order_id;  //������ ��ȣ
        order_log* porder_log; //order log�� ������


    public:
        //constructor
        order_management();

        //destructor
        ~order_management();

        void set_order_log(order_log* order_log); //order_log�� setter

        void order_run(shopping_cart& cart, int coupon, int payment, int age, int change, bool payment_type); //order ���� �� order_log�� �߰�

        bool is_exist_order(int order_id); // order_log���� �ش�Ǵ� order_id �����ϴ��� �Ǵ�

        order* pop_order_log(int order_id); //order_log���� �ش�Ǵ� order pop�ϱ� 

        void push_to_log(order* new_order); //order_log�� ���ο� order push�ϱ�

    };
}