#include <iostream> // std::cout
#include <chrono>   // std::chrono::seconds
#include <thread>   // Una de las liberías que permitirán hacer uso de hilos

void func(bool& empezar){
    while(!empezar)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));    //Se pone ese tiempo de espera para evitar la sobrecarga del nucleo donde se está trabajando
    std::cout << "Marcela" << std::endl;
}

int main(){
    bool empezar = false;
    std::thread th(func, std::ref(empezar));  //Se usa el constructor para inicializar el hilo
                                    //Cuando la función que se usa en el hilo se termine, el hilo también lo hará

    std::cout << "Liliana" << std::endl;

    empezar = true;             //Permite iniciar el hilo asociado a func(bool& empezar)

    if(th.joinable())
        th.join();                  //.join detiene el main (el hilo actual) hasta que el hilo asociado a func termina
                                    //Se debe detener el hilo actual para evitar algún error por el funcionamiento de un hilo mientras que el otro terminó
}
