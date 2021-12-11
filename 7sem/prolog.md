# Prolog

## Терм.

В Прологе используется одна конструкция – терм.

Термы бывают трех вариантов:
1. Константа
    - Число (целое, вещественное)
    - Символьный атом (комбинация символов латинского алфавита, цифр и символа подчеркивания, начинающаяся со строчной буквы: aA, ab_2), используется для обозначения конкретного объекта предметной области или для обозначения конкретного отношения
    - Строка: последовательность символов, заключенных в кавычки
2. Переменная
    - Именованные
    - Анонимные
3. Составной терм
    - Это средство организации группы отдельных элементов знаний в единый  объект,  синтаксически представляется:
f(t1, t2,… tn)
f – это главный функтор
t – это термы.

Любой терм может быть как константой, так и переменной, и составным термом.

Факт - это составной терм.

В Прологе используются только термы, из них можно построить предложение, которое можно в виде «вопроса» «задать» базе знаний.

Вопрос формулируется в виде составного терма.

С помощью составного терма можно зафиксировать факт наличия связи между аргументами. При чем факт – это аналог аксиомы. А главный функтор составного терма – это название связи.

Количество термов в составном терме не регламентируется.


## Что собой представляет база знаний

С помощью термов и более сложных конструкций языка Prolog – фактов и правил «описываются» знания о предметной области, т.е. база знаний.  Используя базу знаний, система Prolog будет делать логические выводы, отвечая на наши вопросы. Таким образом, программа на Prolog представляет собой базу знаний и вопрос. 

База знаний состоит из предложений - CLAUSES (отдельных знаний или утверждений): фактов и правил. Каждое предложение заканчивается точкой. Предложения бывают двух видов: факты и правила. Предложение более общего вида – правило  имеет вид:
	A :- B1,... , Bn. 
A называется заголовком правила, а B1,..., Bn – телом правила.
Факт – это частный случай правила. Факт – это предложение, в котором отсутствует тело (т.е. тело пустое). 
Причем,  A,  B1,... , Bn     – это термы;    символ ":-" это специальный символ-разделитель.
Заголовок содержит отдельное знание о предметной области (составной терм), а тело содержит условия истинности этого знания. Правило называют условной истиной, а факт, не содержащий тела – безусловной истиной.

Заголовок, как составной терм  f(t1, t2, …,tm) , содержит знание о том, что между аргументами: t1, t2, …,tm существует отношение (взаимосвязь, взаимозависимость). А имя этого отношения – это f.  Например:   likes(judy, tennis)      
Если это факты (или правила) программы, то это записывается в разделе - CLAUSES:
likes(judy, tennis).
mother("Наташа", "Даша").


Для пролога по умолчанию установлено, что база знаний просматривается сверху-вниз. Но мы можем изменить порядок просмотра!


## В какой форме записываются факты и правила

Факты – это всегда истина (аналог аксиомы).
Правила – это аналог теоремы (если-то), это «условная» истина.

Факт – это утверждение программы, и имеет вид «предложения»:
student( Ivanov, mgtu).
student(X, mgtu).
Факты, которые не имеют переменных в качестве аргументов – основные. Иначе факт будет Неосновным.

Факт - это составной терм.

Итак, знания фиксируются с помощью фактов («=аксиомы») или правил («истинно при условии»).

Если программа состоит только из фактов, то может быть только 4 случая:

  1. Факты в базе и вопрос – основные. В этом случае используется простое правило: совпадение -  вопрос из программы выводится, если в программе есть тождественный факт;
  2. Факты в базе основные, а вопрос – неосновной. В этом случае используется простое правило: обобщение (факта)  –  если есть такая подстановка, что вопрос  QΘ логически следует из программы, то и вопрос  Q  следует из программы.
  3. Факты в базе неосновные, а вопрос – основной. В этом случае используется простое правило: конкретизация (факта) –  из утверждения  Р с квантором всеобщности выводится пример РΘ, которым является вопрос.
  4. Факты в базе и вопрос – неосновные. Это наиболее общий случай. Для ответа необходимо найти общий пример для вопроса и факта. В этом случае используется два правила:  конкретизация (факта)  – строится пример, а затем, с помощью правила  – обобщение, из примера выводится вопрос. Например 

Факт:          Р(Y , b).

Конкретизация: Р(a, b).  

Обобщение:     Р(a, X)

Вопрос:	       Р(a , X)


## Как работает алгоритм унификации, зачем он нужен, что в результате получается

**Унификация** – операция, которая позволяет формализовать процесс логического вывода (наряду с правилом резолюции). С практической точки зрения  - это основной вычислительный шаг, с помощью которого происходит:
 - Двунаправленная передача параметров процедурам,
 - Неразрушающее присваивание,
 - Проверка условий (доказательство).

Упрощенно, процесс унификации можно представить как формальный процесс сравнивания (сопоставления) терма вопроса с очередным термом знания.

Алгоритм унификации – это основной шаг поиска ответа на вопрос.

Когда два терма считаются унифицированными с точки зрения алгоритма унификации?
Например, составной терм НЕ унифицируется с константой
Составные термы унифицируются, когда:
Одинаковые главные функторы
Одинаковая арность (одинаковое количество аргументов
Аргументы попарно унифицируются


Алгоритм унификации работает, пока стек НЕ пуст!

Если работает алгоритм унификации, то он использует некоторые разделы оперативной памяти, а именно:
 - Стек
 - Рабочее поле
 - Результирующая ячейка памяти



## Как система работает: что такое резольвента и т.п.

Вычисления с помощью конечной логической программы представляют собой пошаговое преобразование исходного вопроса. На каждом шаге имеется некоторая совокупность целей - утверждений, истинность (выводимость) которых надо доказать. Эта совокупность называется **резольвентой** - её состояние меняется в процессе доказательства (Для хранения резольвенты система использует стек). Успешное завершение работы программы достигается тогда, когда резольвента пуста. Преобразования резольвенты выполняются с помощью редукции.

**Редукцией** цели G с помощью программы P называется замена цели G телом того правила из P, заголовок которого унифицируется с целью (в заголовке правила зафиксировано знания). Такие правила будем называть сопоставимыми с целью, и система подбирает нужные с помощью алгоритма унификации.

Новая резольвента образуется в два этапа
  1. в текущей резольвенте выбирается одна из подцелей (по стековому принципу - верхняя) и для неё выполняется редукция - замена подцели на тело найденного (подобранного, если удалось) правила (а как подбирается правило?),
  2. затем, к полученной конъюнкции целей применяется подстановка, полученная как наибольший общий унификатор цели (выбранной) и заголовка сопоставленного с ней правила.

Если для редукции цели из резольвенты был выбран факт из БЗ, то новая резольвента будет содержать в конъюнкции на одну цель меньше, т.к. факт – частный случай правила с пустым телом. И, если задан простой вопрос (на первом шаге он попадает в резольвенту) и подобран для редукции факт, то произойдет немедленное его согласование. А если для простого вопроса подобрано правило, то число целей в резольвенте не уменьшится, т.к. цель будет заменена телом подобранного правила.


Поступивший вопрос система помещает в резольвенту.
ДАЛЕЕ РЕДУКЦИЯ:
Система заменяет вопрос в резольвенте на тело того правила, заголовок (в нем знание!) которого унифицирован с целью (т. е с вопросом)

Унифицируется ТОЛЬКО заголовок!

Редукция – это замена вопроса (цели) на тело того правила, которое унифицировалось с заголовком правила.

Одно тело – это уже конъюнкция целей!

База знаний – в рамках редукции вещь неизменная…

В общем случае цель – это составной терм!

После замены цели на тело к переменным в теле при редукции применяется подстановка!!!
При доказательстве цели она «выталкивается» из резольвенте.
Резольвента может уменьшаться, только когда мы находим не правило, а факт, так как у факта НЕТ тела, которое может попасть в подстановку.
Когда резольвента пуста, то алгоритм прекращает работу.


## Какие бывают переменные. Что они обозначают?

Переменные бывают:
    - Именованные – имена начинаются с заглавной буквы или нижнего подчеркивания. Такая переменная обозначает объект, которого мы еще не знаем.
    - Анонимные – обозначается только символом подчеркивания.

Переменные в момент фиксации утверждений в программе, обозначая некоторый неизвестный объект из некоторого множества объектов, не имеют значения. Значения для переменных могут быть установлены Prolog-системой только в процессе поиска ответа на вопрос, т.е. реализации программы.

Вообще – переменные предназначены для передачи значений «во времени и в пространстве». Переменные в факты и правила входят только с квантором всеобщности. А в вопросы переменные входят только с квантором существования. Поэтому символы кванторов в программе на Prolog не пишутся.

**Именованные** переменные уникальны в рамках предложения, а **анонимная** переменная – любая уникальна.

В процессе выполнения программы переменные могут связываться с различными объектами – конкретизироваться. Это относится только к именованным переменным. Анонимные переменные не могут быть связаны со значением.


----------