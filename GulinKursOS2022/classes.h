#pragma once
#include <string>
#include "classes.h"

using namespace std;

class Process; //процесс
class Msg; //cообщение
class Msq_queue; //очередь сообщений
class Set_of_processes; //совокупность процессов
class Set_of_msg_queues; //совокупность очередей сообщений

class Process //процесс
{
private:
	int id; //уникальный идентификатор процесса
	int type; //флаг типа процесса
	string owner_name; //имя владельца процесса (какой-то пользователь или система)
	int f_condition; //флаг состояния процесса (порождение процесса, готовность, выполнение, ожидание, удаление процесса)
	string* queue_tasks; //очередь заданий
	string* current_task; //текущее выполняемое задание
	int qty_tasks; //кол-во заданий
public:
	void add_task(string input) //добавить задание в конец очереди
	{

	}

	void add_task_to_top(string input) //добавить задание в начало очереди (нужно, если данное задание имеет изначально высокий приоритет) 
	{

	}

	void exec() //выполнение в зависимости от состояния
	{

	}

	//Методы set, get полей
	void set_id(int input) 
	{
		id = input;
	}

	int get_id()
	{
		return id;
	}

	void set_type(int input)
	{
		type = input;
	}

	int get_type()
	{
		return type;
	}

	void set_owner_name(string input)
	{
		owner_name = input;
	}

	string get_owner_name()
	{
		return owner_name;
	}

	void set_f_condition(int input)
	{
		f_condition = input;
	}

	int get_f_condition()
	{
		return f_condition;
	}
};

class Msg //cообщение
{
private:
	int id; //уникальный идентификатор сообщения
	int type; //флаг типа сообщения
	string data; //содержимое сообщения (данные, тело сообщения)
	int id_sender; //идентификатор процесса - отправителя
public:
	//Методы set, get полей 
	void set_id(int input)
	{
		id = input;
	}

	int get_id()
	{
		return id;
	}

	void set_type(int input)
	{
		type = input;
	}

	int get_type()
	{
		return type;
	}

	void set_data(string input)
	{
		data = input;
	}

	string get_data()
	{
		return data;
	}

	void set_id_sender(int input)
	{
		id_sender = input;
	}

	int get_id_sender()
	{
		return id_sender;
	}
};

class Msg_queue //очередь сообщений
{
private:
	int id; //уникальный идентификатор очереди (он же является ключом доступа)
	int id_owner; //идентификатор процесса - владельца очереди (который может удалить очередь)
	Msg* msgs; //очередь сообщений
	int qty_msgs; //кол-во сообщений
public:
	void push(int type_input, string data_input, int id_sender_input) //поместить сообщение в конец очереди
	{

	}

	Msg* pop() //извлечь сообщение из очереди. Извлекается самое «старое» сообщение из очереди, удаляется из неё 
	{

	}

	void clear() //очистить очередь 
	{

	}

	Msg* pop_type(int type_output) //извлечь сообщение выбранного типа из очереди. Извлекается самое «старое» сообщение данного типа из очереди, удаляется из неё 
	{

	}

	Msg* output(int number) //получить указатель на сообщение с выбранным индексом (используется для вывода всех сообщений на экран в программе, иллюстрирующей работу механизма межпроцессового взаимодействия)
	{
		return &msgs[number];
	}

	int get_qty() //получить кол-во сообщений
	{
		return qty_msgs;
	}

	void msgctl(int id_new_owner, int id_caller) //изменить идентификатор процесса – владельца очереди на новый (можно выполнить, только если вызывающий процесс является владельцем очереди)
	{

	}
};

class Set_of_processes //совокупность процессов
{
private:
	Process* processes; //процессы
	int qty_processes; //кол-во процессов
public:
	void add(int id_input, int type_input, string owner_name_input) //создать процесс (состояние процесса – «порождение», очередь заданий пустая, кол-во заданий равно нулю)
	{

	}

	void del(int id_del) //удалить процесс с выбранным идентификатором
	{

	}

	void exec_processes() //выполнить следующую итерацию функционирования процессов
	{

	}

	Process* get_process(int id_proc) //получить указатель на процесс с выбранным идентификатором
	{

	}

	Process* output(int number) //получить указатель на процесс с выбранным индексом
	{

	}

	int get_qty() //получить кол-во процессов
	{

	}
};

class Set_of_msg_queues //совокупность очередей сообщений 
{
private:
	Msg_queue* queues; //очереди сообщений
	int qty_queues; //кол-во очередей сообщений
public:
	Msg_queue* msgget(int id_queue, int id_caller) //получить очередь сообщений с выбранным идентификатором (выступает в качестве ключа). Если такая очередь не существует, то она создаётся)
	{
	
	}

	void queue_delete(int id_queue, int id_caller) //удалить очередь сообщений с выбранным идентификатором (можно удалить, только если вызывающий процесс является владельцем очереди)
	{

	}

	Msg_queue* output(int number) //получить указатель на очередь с выбранным индексом
	{

	}

	int get_qty() //получить кол-во очередей
	{

	}
};
