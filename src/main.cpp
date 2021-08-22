#include <iostream>
#include "classes/Controller.h"
#include "classes/UI.h"

int main(int, char**) {
    // Some way to designate input path, output path, and type
    
    UI *ui = new UI();
    Controller controller = Controller(ui);
    controller.Start();
}
