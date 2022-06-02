#pragma once
#include <string>
#include <sstream>
#include <iostream>

//значение флагов состояния процесса
#define GENERAT 0 //порождение
#define READY 1//готовность
#define EXECUT 2//выполнение 
#define WAIT 3//ожидание (блокировка)
#define DEL 4 //удаление процесса (завершение)

#define ERRNO -1 //возвращается при попытке получения сообщения из пустой очереди

using namespace std;

//глобальные переменные и объекты
extern class Set_of_processes procs;
extern class Set_of_msg_queues msgqs;

extern int last_id_proc; //последний задействованный уникальный id процесса
extern int last_id_msg; //последний задействованный уникальный id сообщения

class Msg; //cообщение
class Msq_queue; //очередь сообщений
class Set_of_msg_queues; //совокупность очередей сообщений
class Process; //процесс
class Set_of_processes; //совокупность процессов

class Msg //cообщение
{
private:
	int id; //уникальный идентификатор сообщения
	int type; //флаг типа сообщения
	string data; //содержимое сообщения (данные, тело сообщения)
	int id_sender; //идентификатор процесса - отправителя
public:
	Msg(int id_input, int type_input, string data_input, int id_sender_input) //конструктор
	{
		id = id_input;
		type = type_input;
		data = data_input;
		id_sender = id_sender_input;
	}
	Msg()
	{
		id = ERRNO;
		type = ERRNO;
		data = "";
		id_sender = ERRNO;
	}
	void init(int id_input, int type_input, string data_input, int id_sender_input)
	{
		id = id_input;
		type = type_input;
		data = data_input;
		id_sender = id_sender_input;
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
	Msg_queue(int id_input, int id_owner_input) //конструктор
	{
		id = id_input;
		id_owner = id_owner_input;
		msgs = NULL;
		qty_msgs = 0;
	}
	Msg_queue()
	{
		id = 0;
		id_owner = 0;
		msgs = NULL;
		qty_msgs = 0;
	}


	void init(int id_input, int id_owner_input)
	{
		id = id_input;
		id_owner = id_owner_input;
		delete[] msgs;
		msgs = NULL;
		qty_msgs = 0;
	}

	void push(int type_input, string data_input, int id_sender_input) //поместить сообщение в конец очереди
	{
		Msg* msgs_new = new Msg[qty_msgs + 1];
		for (int i = 0; i < qty_msgs; i++)
		{
			msgs_new[i] = msgs[i];
		}
		msgs_new[qty_msgs].init(++last_id_msg, type_input, data_input, id_sender_input);
		qty_msgs++;

		delete[] msgs;
		msgs = msgs_new;
	}

	Msg pop() //извлечь сообщение из очереди. Извлекается самое «старое» сообщение из очереди, удаляется из неё 
	{
		Msg pop_msg;
		if (qty_msgs > 0)
		{
			pop_msg = msgs[0];

			qty_msgs--;

			Msg* msgs_new = NULL;
			if (qty_msgs > 0)
			{
				msgs_new = new Msg[qty_msgs];
				for (int i = 0, j = 1; j < qty_msgs + 1; i++, j++)
				{
					msgs_new[i] = msgs[j];
				}
			}
			delete[] msgs;
			msgs = msgs_new;
		}
		else
		{
			pop_msg.init(ERRNO, ERRNO, "empty queue", ERRNO);
		}
		return pop_msg;
	}

	void clear() //очистить очередь 
	{
		delete[] msgs;
		qty_msgs = 0;
	}

	Msg pop_type(int type_output) //извлечь сообщение выбранного типа из очереди. Извлекается самое «старое» сообщение данного типа из очереди, удаляется из неё 
	{
		Msg pop_msg;
		if (qty_msgs > 0)
		{
			int search_i = -1; //индекс искомого сообщения с выбранным типом
			for (int i = 0; i < qty_msgs; i++)
			{
				if (msgs[i].get_type() == type_output)
				{
					search_i = i;
					break;
				}
			}
			if (search_i != -1)
			{
				pop_msg = msgs[search_i];

				qty_msgs--;

				Msg* msgs_new = NULL;
				if (qty_msgs > 0)
				{
					msgs_new = new Msg[qty_msgs];
					for (int i = 0, j = 0; i < qty_msgs + 1; i++)
					{
						if (i != search_i)
						{
							msgs_new[j] = msgs[i];
							j++;
						}
					}
				}
				delete[] msgs;
				msgs = msgs_new;
			}
			else
			{
				pop_msg.init(ERRNO, ERRNO, "", ERRNO);
			}
		}
		else
		{
			pop_msg.init(ERRNO, ERRNO, "", ERRNO);
		}
		return pop_msg;
	}

	Msg* output(int number) //получить указатель на сообщение с выбранным индексом (используется для вывода всех сообщений на экран в программе, иллюстрирующей работу механизма межпроцессового взаимодействия)
	{
		return &msgs[number];
	}

	int get_qty() //получить кол-во сообщений
	{
		return qty_msgs;
	}

	bool msgctl(int id_new_owner, int id_caller) //изменить идентификатор процесса – владельца очереди на новый (можно выполнить, только если вызывающий процесс является владельцем очереди)
	{
		if (id_caller == id_owner)
		{
			id_owner = id_new_owner;
			return true;
		}
		else
			return false;
	}

	bool is_this_type_exists(int type_find) //проверка, есть ли в данной очереди сообщения требуемого типа
	{
		if (type_find = -1 && qty_msgs > 0)
			return true;

		bool f = false;
		for (int i = 0; i < qty_msgs; i++)
		{
			if (msgs[i].get_type() == type_find)
			{
				f = true;
				break;
			}
		}
		return f;
	}

	//методы get
	int get_id()
	{
		return id;
	}

	int get_id_owner()
	{
		return id_owner;
	}
};

class Set_of_msg_queues //совокупность очередей сообщений 
{
private:
	Msg_queue* queues; //очереди сообщений
	int qty_queues; //кол-во очередей сообщений
public:
	Set_of_msg_queues() //конструктор
	{
		qty_queues = 0;
		queues = NULL;
	}

	Msg_queue* msgget(int id_queue, int id_caller) //получить очередь сообщений с выбранным идентификатором (выступает в качестве ключа). Если такая очередь не существует, то она создаётся)
	{
		Msg_queue* getted_queue = NULL;
		for (int i = 0; i < qty_queues; i++)
		{
			if (queues[i].get_id() == id_queue)
			{
				getted_queue = &queues[i];
				break;
			}
		}
		if (getted_queue == NULL)
		{
			qty_queues++;
			Msg_queue* queues_new = new Msg_queue[qty_queues];

			if (qty_queues > 1)
			{
				for (int i = 0; i < qty_queues - 1; i++)
				{
					queues_new[i] = queues[i];
				}
			}

			queues_new[qty_queues - 1].init(id_queue, id_caller);

			delete[] queues;
			queues = queues_new;

			getted_queue = &queues[qty_queues - 1];
		}

		return getted_queue;
	}

	bool queue_delete(int id_queue, int id_caller) //удалить очередь сообщений с выбранным идентификатором (можно удалить, только если вызывающий процесс является владельцем очереди)
	{
		int i_deleted_queue = -1;
		for (int i = 0; i < qty_queues; i++)
		{
			if (queues[i].get_id() == id_queue && queues[i].get_id_owner() == id_caller)
			{
				i_deleted_queue = i;
				break;
			}
		}
		if (i_deleted_queue == -1)
		{
			return false;
		}
		else
		{
			qty_queues--;
			Msg_queue* queues_new = NULL;
			if (qty_queues > 0)
			{
				queues_new = new Msg_queue[qty_queues];

				for (int i = 0, j = 0; j < qty_queues + 1; j++)
				{
					if (j != i_deleted_queue)
					{
						queues_new[i] = queues[j];
						i++;
					}
				}
			}

			delete[] queues;
			queues = queues_new;
			return true;
		}
	}

	Msg_queue* output(int number) //получить указатель на очередь с выбранным индексом
	{
		return &queues[number];
	}

	bool is_queue_exists(int id_queue_find) //проверить, есть ли очередь с данным id
	{
		bool f_finded = false;
		for (int i = 0; i < qty_queues; i++)
		{
			if (queues[i].get_id() == id_queue_find)
			{
				f_finded = true;
				break;
			}
		}

		return f_finded;
	}

	int get_qty() //получить кол-во очередей
	{
		return qty_queues;
	}
};


class Process //процесс
{
private:
	int id; //уникальный идентификатор процесса
	string name; //имя процесса
	string owner_name; //имя владельца процесса (какой-то пользователь или система)
	int f_condition; //флаг состояния процесса (порождение процесса, готовность, выполнение, ожидание, удаление процесса)
	string* queue_tasks; //очередь заданий
	string current_task; //текущее выполняемое задание
	int qty_tasks; //кол-во заданий (кроме текущего)

	Msg last_msg; //последнее полученное сообщение, используемое при работе процесса (было получено из очереди)

public:
	Process(int id_input, int name_input, string owner_name_input, int f_condition_input) //конструктор
	{
		id = id_input;
		name = name_input;
		owner_name = owner_name_input;
		f_condition = f_condition_input;
		queue_tasks = NULL;
		current_task = "";
		qty_tasks = 0;
	}
	Process()
	{
		id = 0;
		name = "empty process";
		owner_name = "";
		f_condition = 0;
		queue_tasks = NULL;
		current_task = "";
		qty_tasks = 0;
	}

	void init(int id_input, string name_input, string owner_name_input, int f_condition_input)
	{
		id = id_input;
		name = name_input;
		owner_name = owner_name_input;
		f_condition = f_condition_input;
		queue_tasks = NULL;
		current_task = "";
		qty_tasks = 0;
	}

	void add_task(string input) //добавить задание в конец очереди
	{
		string* tasks_new = new string[qty_tasks + 1];
		for (int i = 0; i < qty_tasks; i++)
		{
			tasks_new[i] = queue_tasks[i];
		}
		tasks_new[qty_tasks] = input;
		qty_tasks++;

		delete[] queue_tasks;
		queue_tasks = tasks_new;
	}

	void add_task_to_top(string input) //добавить задание в начало очереди (нужно, если данное задание имеет изначально высокий приоритет) 
	{
		string* tasks_new = new string[qty_tasks + 1];
		for (int i = 1, j = 0; j < qty_tasks; i++, j++)
		{
			tasks_new[i] = queue_tasks[j];
		}
		tasks_new[0] = input;
		qty_tasks++;

		delete[] queue_tasks;
		queue_tasks = tasks_new;
	}

	bool to_next_task() //перейти к следующему заданию (перенести задание из начала очереди в переменную с текущим заданием)
	{
		if (qty_tasks == 0)
		{
			current_task = "";
			return false;
		}
		else
		{
			current_task = queue_tasks[0];
			delete_task(0+1);
			return true;
		}
	}

	bool delete_task(int number) //удалить задание с выбранным индексом из очереди, нумерация от 1
	{
		if (number > 0 && number <= qty_tasks)
		{
			qty_tasks--;
			string* tasks_new = NULL;
			if (qty_tasks > 0)
			{
				tasks_new = new string[qty_tasks];

				for (int i = 0, j = 0; j < qty_tasks + 1; j++)
				{
					if (j != number - 1)
					{
						tasks_new[i] = queue_tasks[j];
						i++;
					}
				}
			}

			delete[] queue_tasks;
			queue_tasks = tasks_new;
			return true;
		}
		else
			return false;
	}

	System::String^ exec() //выполнение в зависимости от состояния (возвращается инфо о результате выполнения)
	{
		string command; //строка с командой из текущего задания
		stringstream  task_stream; //поток для разбора текущего задания
		bool f_success; //для проверки появления сообщения в очереди в режиме ожидания

		switch (f_condition)
		{
		case GENERAT: //порождение
			f_condition = READY;
			return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " перешёл в состояние готовности.";
			break;

		case READY: //готовность
			if (qty_tasks > 0)
			{
				to_next_task();
				f_condition = EXECUT;
				return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " получил задание \"" + gcnew System::String(current_task.c_str()) + "\" из очереди заданий и перешёл в состояние выполнения.";
			}
			else
			{
				current_task = "";
				return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " не имеет заданий в очереди и остаётся в состоянии готовности.";
			}
			break;

		case EXECUT: //выполнение
			task_stream << current_task; //создать поток из текста текущего задания
			task_stream >> command; //получить команду из задания

			//выполнение в зависимости от команды фиксированной длины
			if (command == "snd") //отправить сообщение
			{
				int id_queue_of_msg; //id очереди, куда надо отправить сообщение
				task_stream >> id_queue_of_msg; //получить из задания

				int type_of_msg; //тип отправляемого сообщения
				task_stream >> type_of_msg; //получить из задания


				string msg_text = current_task; //получить текст задания
				msg_text.assign(msg_text, msg_text.find("\"") + 1, msg_text.rfind("\"") - msg_text.find("\"") - 1); //отобрать текст сообщения из задания

				//msg_text = std::to_string(msg_text.find("\"")) + " " + std::to_string(msg_text.rfind("\""));

				msgqs.msgget(id_queue_of_msg, id)->push(type_of_msg, msg_text, id); //отправить сообщение в очередь

				f_condition = READY;
				current_task = "";
				return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " отправил сообщение \"" + gcnew System::String(msg_text.c_str()) + "\" типа " + System::Convert::ToString(type_of_msg) + " в очередь " + System::Convert::ToString(id_queue_of_msg) + " и перешёл в состояние готовности.";
			}
			else if (command == "rsv") //получить сообщение
			{
				int id_queue_of_msg; //id очереди, откуда надо получить сообщение
				task_stream >> id_queue_of_msg; //получить из задания

				int type_of_msg; //тип получаемого сообщения (-1, если любой)
				task_stream >> type_of_msg; //получить из задания

				if (msgqs.is_queue_exists(id_queue_of_msg) == true)
				{
					if (type_of_msg != -1)
					{
						last_msg = msgqs.msgget(id_queue_of_msg, id)->pop_type(type_of_msg);
					}
					else
					{
						last_msg = msgqs.msgget(id_queue_of_msg, id)->pop();
					}
					if (last_msg.get_id() == ERRNO)
					{
						if (type_of_msg != -1)
						{
							return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " не нашёл в очереди сообщений с id = " + System::Convert::ToString(id_queue_of_msg) + " сообщения типа " + System::Convert::ToString(type_of_msg) + " и перешёл в состояние ожидания появления сообщения.";
						}
						else
						{
							return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " не нашёл в очереди сообщений с id = " + System::Convert::ToString(id_queue_of_msg) + " сообщений любых типов и перешёл в состояние ожидания появления сообщения.";
						}
					}
					else
					{
						f_condition = READY;
						current_task = "";
						if (type_of_msg != -1)
						{
							return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " получил из очереди сообщений с id = " + System::Convert::ToString(id_queue_of_msg) + " сообщение типа " + System::Convert::ToString(type_of_msg) + " и перешёл в состояние готовности.";
						}
						else
						{
							return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " получил из очереди сообщений с id = " + System::Convert::ToString(id_queue_of_msg) + " сообщение любого типа и перешёл в состояние готовности.";
						}
					}
				}
				else
				{
					f_condition = WAIT;
					return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " не нашёл очередь сообщений с id = " + System::Convert::ToString(id_queue_of_msg) + " и перешёл в состояние ожидания появления очереди.";
				}
			}
			else if (command == "finish") //завершить работу процесса
			{
				f_condition = DEL;
				current_task = "";
				return "При выполнении процесса \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " перешёл в состояние удаления (завершения).";
			}
			else if (command == "nop")
			{
				f_condition = READY;
				current_task = "";
				return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " выполнил пустую команду и перешёл в состояние готовности.";
			}
			else
			{
				f_condition = READY;
				current_task = "";
				return "При выполнении процесса \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " обнаружена неизвестная команда \"" + gcnew System::String(command.c_str()) + "\". Задание с данной командой пропущено. Процесс перешёл в состояние готовности.";
			}
			break;

		case WAIT: //ожидание (блокировка)
			int id_queue; //id очереди, откуда надо получить сообщение
			int type_queue_find; //тип сообщения, который надо получить

			task_stream << current_task; //создать поток из текста текущего задания
			task_stream >> command; //получить команду из задания
			task_stream >> id_queue;
			task_stream >> type_queue_find;

			f_success = false;
			if (msgqs.is_queue_exists(id_queue) == true)
			{
				if (msgqs.msgget(id_queue, id)->is_this_type_exists(type_queue_find) == true)
				{
					f_success = true;
				}
			}
			if (f_success == true)
			{
				f_condition = EXECUT;

				if (type_queue_find != -1)
				{
					return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " нашёл в очереди сообщений с id = " + System::Convert::ToString(id_queue) + " сообщение типа " + System::Convert::ToString(type_queue_find) + " и перешёл в состояние выполнения.";
				}
				else
				{
					return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " нашёл в очереди сообщений с id = " + System::Convert::ToString(id_queue) + " сообщение любого типа и перешёл в состояние выполнения.";
				}
			}
			else
			{
				if (type_queue_find != -1)
				{
					return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " не нашёл очередь сообщений с id = " + System::Convert::ToString(id_queue) + " или/и сообщения типа " + System::Convert::ToString(type_queue_find) + " в ней и остался в состоянии ожидания появления сообщения.";
				}
				else
				{
					return "Процесс \"" + gcnew System::String(name.c_str()) + "\" с id = " + System::Convert::ToString(id) + " не нашёл очередь сообщений с id = " + System::Convert::ToString(id_queue) + " или/и сообщения любых типов в ней и остался в состоянии ожидания появления сообщения.";
				}
			}
			break;
			
		case DEL:
			return "";
			break;
		}
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

	void set_name(string input)
	{
		name = input;
	}

	string get_name()
	{
		return name;
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
	
	int get_qty_tasks()
	{
		return qty_tasks;
	}

	string get_task(int number)
	{
		return queue_tasks[number];
	}

	string get_current_task()
	{
		return current_task;
	}

	string get_last_msg_data()
	{
		return last_msg.get_data();
	}
};

class Set_of_processes //совокупность процессов
{
private:
	Process* processes; //процессы
	int qty_processes; //кол-во процессов
public:
	Set_of_processes() //конструктор
	{
		qty_processes = 0;
		processes = NULL;
	}

	void add(string name_input, string owner_name_input) //создать процесс (состояние процесса – «порождение», очередь заданий пустая, кол-во заданий равно нулю)
	{
		Process* processes_new = new Process[qty_processes + 1];
		for (int i = 0; i < qty_processes; i++)
		{
			processes_new[i] = processes[i];
		}
		processes_new[qty_processes].init(++last_id_proc, name_input, owner_name_input, GENERAT);
		qty_processes++;

		delete[] processes;
		processes = processes_new;
	}

	bool del(int id_del) //удалить процесс с выбранным идентификатором
	{
		int i_deleted_proc = -1;
		for (int i = 0; i < qty_processes; i++)
		{
			if (processes[i].get_id() == id_del)
			{
				i_deleted_proc = i;
				break;
			}
		}
		if (i_deleted_proc == -1)
		{
			return false;
		}
		else
		{
			qty_processes--;
			Process* processes_new = NULL;
			if (qty_processes > 0)
			{
				processes_new = new Process[qty_processes];

				for (int i = 0, j = 0; j < qty_processes + 1; j++)
				{
					if (j != i_deleted_proc)
					{
						processes_new[i] = processes[j];
						i++;
					}
				}
			}

			delete[] processes;
			processes = processes_new;
			return true;
		}
	}

	Process* get_process(int id_proc) //получить указатель на процесс с выбранным идентификатором
	{
		Process* getted_proc = NULL;
		for (int i = 0; i < qty_processes; i++)
		{
			if (processes[i].get_id() == id_proc)
			{
				getted_proc = &processes[i];
				break;
			}
		}
		return getted_proc;
	}

	Process* output(int number) //получить указатель на процесс с выбранным индексом
	{
		return &processes[number];
	}

	int get_qty() //получить кол-во процессов
	{
		return qty_processes;
	}
};