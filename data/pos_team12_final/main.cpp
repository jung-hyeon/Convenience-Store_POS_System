#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "abstract_item.h"
#include "account_management.h"
#include "cart_item.h"
#include "item_list.h"
#include "item_list_management.h"
#include "item_with_exdate.h"
#include "item_with_guarantee.h"
#include "money.h"
#include "order.h"
#include "order_log.h"
#include "order_management.h"
#include "purchase_management.h"
#include "refund_management.h"
#include "shopping_cart.h"
#include "stock_management.h"

using namespace pos;
using namespace std;

// ������ ���� today�� ���������� ����
int today = 20221207;

int main() {
    {
        item_list item_list;
        account_management account_management;
        order_management order_management;
        refund_management refund_management;
        stock_management stock_management;
        purchase_management purchase_management;
        item_list_management item_list_management;
        order_log order_log;
        money money;

        account_management.set_stock_management(stock_management);
        account_management.set_money(money);
        order_management.set_order_log(&order_log);
        refund_management.set_stock_management(stock_management);
        refund_management.set_account_management(account_management);
        refund_management.set_order_management(order_management);
        stock_management.set_item_list_management(&item_list_management);
        purchase_management.set_stock_management(&stock_management);
        purchase_management.set_account_management(&account_management);
        purchase_management.set_order_management(&order_management);
        item_list_management.set_item_list(item_list);

        int response = 0;
        cout << endl;

        cout << "POS �ý����� �����մϴ�." << endl;

        while (1) {
            cout << endl;
            cout << "������ ��¥�� " << today << " �Դϴ�." << endl;
            cout << "������ �Ͻðڽ��ϱ�?" << endl;
            cout << endl;
            cout << "====================== POS ��� ====================" << endl;
            cout << "          1. ��� ����           2. ����" << endl;
            cout << "          3 .ȯ��                4. ȸ��" << endl;
            cout << "          5. POS �ý��� ����(��� ���� �ʱ�ȭ)" << endl;
            cout << "====================================================" << endl;
            cout << "�Է� (�Է� ����: 1) : ";
            cin >> response;
            if (response == 1) {
                stock_management.stock_run();
            }
            else if (response == 2) {
                purchase_management.purchase_run();
            }
            else if (response == 3) {
                refund_management.refund_run();
            }
            else if (response == 4) {
                account_management.account_run();
            }
            else if (response == 5) {
                cout << endl;
                cout << "POS �ý����� �����մϴ�.";
                break;
            }
            else {
                cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
            }
        }
    }

    return 0;
}