#include <string>
#include "SmartCarrier.h"

using namespace std;

int main() {
    SmartCarrier *p_smart_carrier = nullptr;
    p_smart_carrier = new SmartCarrier("FOOTHILL WIRELESS");
    p_smart_carrier->Init();
    p_smart_carrier->StartService();
    delete p_smart_carrier;
    return 0;
}
