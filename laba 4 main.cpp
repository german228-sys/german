#include "mbed.h"

DigitalOut led1(LED1);
InterruptIn button(USER_BUTTON);
static auto press = 1;
Mutex stdio_mutex;
Thread t2(osPriorityNormal, OS_STACK_SIZE, nullptr, nullptr);
Thread t3(osPriorityNormal, OS_STACK_SIZE, nullptr, nullptr);
Thread t4(osPriorityNormal, OS_STACK_SIZE, nullptr, nullptr);

void pressed()
{
  press = press + 1;
}

void notify1()
{
  while (true)
  {
    stdio_mutex.lock();
    printf("11111\n\r");
    stdio_mutex.unlock();
    ThisThread::sleep_for(250);
  }
}
void notify2()
{
  while (true)
  {
    if (stdio_mutex.trylock())
    {
      printf("22222\n\r");
      stdio_mutex.unlock();
    }
    ThisThread::sleep_for(250);
  }
}
void notify3()
{
  while (true)
  {
    if (stdio_mutex.trylock())
    {
      printf("33333\n\r");
      stdio_mutex.unlock();
    }
    ThisThread::sleep_for(250);
  }
}

int main()
{
  // возможно стоит добавить while если будет выходить из цикла на 2 нажатии
  button.fall(&pressed);
  while (true)
  {
    if (press % 2 == 0)
    {
      t2.start(notify1);
      t3.start(notify2);
    }
    else
    {
      t4.start(notify3);
    }
  }
}