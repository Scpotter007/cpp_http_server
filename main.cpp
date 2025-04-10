#include "crow.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello, World from Crow!";
    });

    CROW_ROUTE(app, "/status")([](){
        return crow::response(200, "Server is running");
    });

    CROW_ROUTE(app, "/greet/<string>")
    ([](const std::string& name){
        return "Hello, " + name + "!";
    });

    app.port(18080).multithreaded().run();
}

