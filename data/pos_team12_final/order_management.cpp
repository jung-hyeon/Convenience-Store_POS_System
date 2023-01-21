#include "order_management.h"

namespace pos {

    //Constructor
    order_management::order_management() {
        this->order_id = 0;
        this->porder_log = NULL;
    }

    //Destructor
    order_management::~order_management() {}


    //order�� ���� �� order_log�� �߰�
    void order_management::order_run(shopping_cart& cart, int coupon, int payment, int age, int change, bool payment_type) {

        order* new_order = new order; //order ����
        //setter�� �� �Ҵ�
        new_order->set_order_id(this->order_id);
        this->order_id++;
        new_order->set_coupon(coupon);
        new_order->set_payment(payment);
        new_order->set_customer_age(age);
        new_order->set_change(change);
        new_order->set_payment_type(payment_type);

        this->porder_log->order_push(new_order);//order_log�� ���ο� order �߰�
    }

    void order_management::set_order_log(order_log* order_log) { //order_log setter
        this->porder_log = order_log;
    }

    bool order_management::is_exist_order(int order_id) {
        return this->porder_log->is_exist_order(order_id);
    }

    order* order_management::pop_order_log(int order_id) { //order_log���� �ش�Ǵ� order pop�ϱ� 
        if (this->is_exist_order(order_id)) {
            return this->porder_log->order_pop(order_id);
        }
        else {
            return NULL;
        }

    }
    void order_management::push_to_log(order* new_order) { //order_log�� ���ο� order push�ϱ�
        this->porder_log->order_push(new_order);
    }

};