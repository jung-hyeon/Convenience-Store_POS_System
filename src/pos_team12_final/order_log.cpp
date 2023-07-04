#include "order_log.h"
namespace pos {

    //public method

    bool order_log::is_exist_order(int order_id) {
        bool exist = false;
        for (list<order>::iterator iter = log_list.begin(); iter != log_list.end(); iter++) {
            if (iter->get_order_id() == order_id && iter->get_is_refunded() == false) {
                exist = true;
                break;
            }
        }
        return exist;
    }

    void order_log::order_push(order* myorder) { //order를 log_list에 push
        log_list.push_back(*myorder); //값을 빼서 push back
        delete myorder; //동적할당 delete
    }

    order* order_log::order_pop(int order_id) { //order를 log_list에서 pop
        for (list<order>::iterator iter = log_list.begin(); iter != log_list.end(); iter++) {
            if (iter->get_order_id() == order_id && iter->get_is_refunded() == false) {
                iter->set_is_refunded(true); //is_refunded = true. 환불 완료.
                order* myorder = &(*iter);
                return myorder;
            }
        }
    }

}
