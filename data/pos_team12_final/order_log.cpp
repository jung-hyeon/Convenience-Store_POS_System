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

    void order_log::order_push(order* myorder) { //order�� log_list�� push
        log_list.push_back(*myorder); //���� ���� push back
        delete myorder; //�����Ҵ� delete
    }

    order* order_log::order_pop(int order_id) { //order�� log_list���� pop
        for (list<order>::iterator iter = log_list.begin(); iter != log_list.end(); iter++) {
            if (iter->get_order_id() == order_id && iter->get_is_refunded() == false) {
                iter->set_is_refunded(true); //is_refunded = true. ȯ�� �Ϸ�.
                order* myorder = &(*iter);
                return myorder;
            }
        }
    }

}
