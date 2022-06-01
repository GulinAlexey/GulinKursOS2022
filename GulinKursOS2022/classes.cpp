#include "classes.h"

//глобальные переменные и объекты
Set_of_processes procs;
Set_of_msg_queues msgqs;

int last_id_proc = 0; //последний задействованный уникальный id процесса
int last_id_msg = 0; //последний задействованный уникальный id сообщения