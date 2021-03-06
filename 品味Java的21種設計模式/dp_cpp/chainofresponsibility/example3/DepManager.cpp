#include "DepManager.h"

namespace cn {
namespace javass {
namespace dp {
namespace chainofresponsibility {
namespace example3 {

std::string DepManager::handleFeeRequest(std::string user, double fee) {
    std::string str = "";

    //部门经理的权限只能在1000以内
    if (fee < 1000) {
        //为了测试，简单点，只同意小李申请的
        if ((new std::string("小李"))->equals(user)) {
            str = "部门经理同意" + user + "聚餐费用" + fee + "元的请求";
        } else {
            //其他人一律不同意
            str = "部门经理不同意" + user + "聚餐费用" + fee + "元的请求";
        }

        return str;
    } else {
        //超过1000，继续传递给级别更高的人处理
        if (this->successor != 0) {
            return this->successor->handleFeeRequest(user, fee);
        }
    }

    return str;
}
}
}
}
}
}
