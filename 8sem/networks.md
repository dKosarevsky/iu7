[8-й семестр](../2022_8_sem.md) | [home](../README.md)
____________________________________
# Компьютерные сети 
[Рогозин Николай Олегович](https://networking-labs.ru/) \
norogozin@gmail.com \
понедельник, 18-30 ауд. 529л (УЛК)\
07.02-23.05 \
Экзамен по итогу всех ЛР (9 штук). Часть ЛР в симуляторе [Cisco Packet Tracer](https://www.netacad.com/ru/courses/packet-tracer), выполняется пошагово по методичке. Часть - небольшие сетевые приложения. Базовое построение сетевого приложения на сокетах, желательно первые две ЛР выполнить на C. В последующих ЛР будет применение прикладных протоколов - можно будет воспользоваться какими-либо высокоуровневыми ЯП.
____________________________________
### Литература

* [hbr](https://habr.com/ru/post/134892/)
* [ciscolearning](https://ciscolearning.ru/)
* [Список вопросов к РК №1](https://docs.google.com/document/d/1zYmXS5kxyfDuPgQ_tBog3G79i8xrJGuy/edit?usp=sharing&ouid=104050528212751164470&rtpof=true&sd=true)

____________________________________
### Инструменты:

1. [Cisco Packet Tracer](https://www.netacad.com/ru/courses/packet-tracer) - Сетевой симулятор, потребуется для выполнения ряда лабораторных работ.
2. [Cisco CLI](https://www.cisco.com/c/ru_ru/td/docs/ios/fundamentals/configuration/guide/12_4/cf_12_4_book/cf_cli-basics.html)
3. [Wireshark](https://www.wireshark.org/) - Анализатор траффика, может использоваться для контроля работы сетевых протоколов и для самостоятельного просмотра структуры пакетов.

____________________________________
### Занятия (13)

* 14.02 - 1. Обзор и классификация сетей | [audio](https://drive.google.com/file/d/1gBJXzjiGZWQAXToCpsktHKEGyOt38MAu/view?usp=sharing) | [slides](https://docs.google.com/presentation/d/1ZPXRFfLD-hi8l1_TWF1224qHrCOUukNk/edit?usp=sharing&ouid=104050528212751164470&rtpof=true&sd=true)
* 14.02 - 2. Модель и стек OSI и TCP/IP [slides](https://docs.google.com/presentation/d/1kxcIIE8LtY26ES-wNcQtHtJlTb56XcWw/edit?usp=sharing&ouid=104050528212751164470&rtpof=true&sd=true)
* 21.02 - 3. Компоненты сети: узлы и линии связи | [audio](https://drive.google.com/file/d/1NdOWs6YKOtlW9ieT0UoXziRCH9HdcJll/view?usp=sharing) | [slides](https://docs.google.com/presentation/d/1Ii-iomXKiIiAAn0z214xbKWam6y8aC6x/edit?usp=sharing&ouid=104050528212751164470&rtpof=true&sd=true)
* 28.02 - 4. Основные принципы разработки сетевых приложений. Сетевые сокеты | [slides](https://drive.google.com/file/d/1KqRp5hkeV5HCB8WBTV7EuJF6DCeQpy1z/view?usp=sharing) 
* 14.03 - 5. Протоколы прикладного уровня [slides](https://drive.google.com/file/d/1KyTbX5nuQ3vj_hySuhZh7CJoap1tFm7N/view?usp=sharing)
* 21.03 - 6. Протоколы прикладного уровня, часть II [slides](https://drive.google.com/file/d/1SAk9SR-XpwaN73vW0Zn_mRFJbVasfLO4/view?usp=sharing)
* 28.03 - 7. Протоколы 
транспортного уровня [slides](https://drive.google.com/file/d/1W8sxt32O7p5U1FXXoY8i8fPsiKj7Mggy/view?usp=drivesdk)
* 04.04 -  
* 11.04 -  
* 18.04 -  
* 25.04 -  
* 16.05 -  
* 23.05 - 

____________________________________

## [Лабы](https://github.com/dKosarevsky/networks/blob/main/README.md)

### ЛР 1 ✔️

[Руководство к ЛР](https://docs.google.com/document/d/1Z86DTMJc3F9BhJevMdyAwROGtaHFz3Pp/edit?usp=sharing&ouid=104050528212751164470&rtpof=true&sd=true) | [ lab1.pkt](https://drive.google.com/file/d/1C61uFcZQjvF3QPzp_4GyaWIIDuxDkSpW/view?usp=sharing)

1. В симуляторе [CPT](https://skillsforall.com/resources/lab-downloads) построить несколько базовых сетевых топологий
2. Устранить неисправности в готовой схеме, неисправности категории: 
  * неправильно проложен кабель, поменять тип кабеля с прямого на кросовый
  * не настроен адрес
  * отключен интерфейс

[report](https://github.com/dKosarevsky/networks/blob/main/lab_01/report.md) | [files](https://github.com/dKosarevsky/networks/tree/main/lab_01)

### ЛР 2 ✔️

[Руководство к ЛР](https://networking-labs.ru/mod/assign/view.php?id=228)

Часть I.

Создать клиент-серверное приложение на основе сетевых (системных) сокетов, транспортный протокол UDP. Использовать язык С./ C++

1. Клиент должен передавать серверу десятичное число (вводится с клавиатуры).

2. На сервере число выводится в десятичной, двоичной, шестнадцатеричной, восьмеричной системах счисления + системе счисления с основанием номер студента по списку. (При совпадении с имеющейся прибавить 1).

Сервер и клиент должны корректно обрабатывать начало и конец соединения.

Часть II.

Создать клиент-серверное приложение на основе сетевых (системных) сокетов, транспортный протокол TCP. Использовать язык С./ C++

Клиент должен передать серверу имя файла в виде строки (вводится на стороне клиента с клавиатуры). Сервер должен передать файл с указанным именем клиенту (если в папке с сервером присутствует такой файл). Сервер должен вести лог, в который заносится каждый переданный файл и время передачи (через пробел).

[report](https://github.com/dKosarevsky/networks/blob/main/lab_02/report.md) | [code](https://github.com/dKosarevsky/networks/tree/main/lab_02/src)
____________________________________

### ЛР 3


Расширение (доработка) существующего TCP-сервера:

Необходимо сделать обработку базовых http-запросов и ответа на эти запросы.

Например базовая команда GET - на эту команду сервер должен соответствующим образом отвечать в соответствии со спецификацией. Спецификация протокола HTTP 1.1.

Нужно реализовать только базовый, минимальный набор запросов и ответов.

Т.е. сервер должен предоставлять возможность:
1. доступ к ресурсам - команда GET (как минимум GET, желательно реализовать HEAD)
2. добавление ресурсов - команда PUT
3. удаление ресурсов - команда DELETE

Желательно реализовать хотя бы базовый инструментарий для работы с сервером. 

В идеале сервер  должен поддерживать одновременную обработку подключений нескольких клиентов в многопоточном режиме используя для этого пул потоков. Т.е. если вспомнить ОС, то нам понадобится создать динамический массив потоков в той системе, для которой будет написан сервер, и для каждого подключения, каждому подключению выделять собственный поток и после завершения подключения возвращать поток в пул


Это будет достаточно большая ЛР по объёму, поэтому она будет оцениваться как 2 ЛР.

____________________________________

### ЛР 4

Настройка сетевых служб: DNS, HTTP, электронной почты в сетевом симуляторе

[Руководство к ЛР](https://docs.google.com/document/d/1Y3VU0xgl8_Ie_3lzDZ1uW_Du-xWUnRWR/edit?usp=sharing&ouid=104050528212751164470&rtpof=true&sd=true) | [lab4_v0.pkt](https://drive.google.com/file/d/1dqNYJUlDzUbZEZW3aM0F3gJqe_A8AEUx/view?usp=sharing)

[report](https://github.com/dKosarevsky/networks/blob/main/lab_04/report.md) | [files](https://github.com/dKosarevsky/networks/tree/main/lab_04)


____________________________________

### ЛР 5

Реализовать SMTP-клиент использующий один из открытых серверов (собственный SMTP-сервер писать не нужно, т.к. это займёт большое кол-во времени. Можно использовать Яндекс-сервер.) для передачи почтовых сообщений. 
Доп. задание будет в зависимости от варианта и оно будет задавать какой именно вид должно принять передаваемое сообщение и по какому принципу оно должно передаваться. 

[report](https://github.com/dKosarevsky/networks/blob/main/lab_05/report.md) | [code](https://github.com/dKosarevsky/smtp_client) | [web](https://share.streamlit.io/dkosarevsky/smtp_client/main/main.py)

____________________________________

### ЛР 6

выполняется в сетевом симуляторе

1. Распределить исходя из индивидуального варинта адреса устройства
2. Разбить сеть на подсети в соответствии с индивидуальным номером варианта

формула для разбития на подсети: 2^n-2

____________________________________

### ЛР 7
