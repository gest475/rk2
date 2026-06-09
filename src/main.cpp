#include "chain.hpp"

int main() {
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter cs(&se);

    cs.Work(Task::CustomerIssue);
    cs.Work(Task::Programming);
    return 0;
}
