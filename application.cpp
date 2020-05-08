#include "application.h"
#include "widget.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
using namespace genv;
void Application::load_widget(Widget * current_widget){
    widgets.push_back(current_widget);
    }



