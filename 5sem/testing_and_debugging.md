[home](https://github.com/dKosarevsky/iu7/blob/master/2020_2021_5sem.md)
____________________________________
**Тестирование и отладка ПО** \
Рогозин Николай Олегович \
norogozin@gmail.com \
понедельник, аудитория 533, 19-00 \
Экзамен (по результатам 5 лаб + отчëтов)

Регаемся [тут](https://networking-labs.ru) и кидаем логин на почту преподавателю, с просьбой добавить на курс, после чего будут расшарены данные
____________________________________
**Литература**

* [Святослав Куликов "Тестирование ПО. Базовый курс"](https://drive.google.com/file/d/1aKEbSjcMXy64Bn7ERSTtMbNW9aSHts5_/view?usp=sharing) Основное пособие курса (Версия книги 3.0.1 от 14.09.2020)

* [Борис Бейзер "Тестирование черного ящика"](https://t.me/progbook/529)

* [Гленфорд Майерс “Искусство тестирования программ”](https://t.me/progbook/530)

* [Кент Бек “Экстремальное программирование. Разработка через тестирование”](https://t.me/progbook/353)
 
* [В.В. Липаев “Тестирование компонентов и комплексов программ”](https://www.ispras.ru/lipaev/books/Testing%20of%20components%20and%20systems%20software.pdf)

* [Вигерс Карл, Битти Джой, Разработка требований к программному обеспечению, третье издание 2014](https://drive.google.com/file/d/1QVz6f5MwM5To7lOfjPlos7Upp7nR9XMV/view?usp=sharing)

* [Алгоритмы. Руководство по разработке. 2-е издание, 2011. Стивен Скиена](https://drive.google.com/file/d/1QST3NybDwrrV8dHIY74cFzKfPts0CQhZ/view?usp=sharing)

____________________________________
План по лабам:

ЛР №1:
* Модульное тестирование
* Ручное тестирование
* Метод чёрного ящика
* Покрытие максимально возможного числа веток кода
* Таблица классов эквивалентности

**[последние два пункта для всех ЛР]**

ЛР №2:
* Интеграционное тестирование

ЛР №3:
* Функциональное системное тестирование
* Спецификация ПС (программное средство)

ЛР №4:
* Регрессионное тестирование
* Control Flow Graph (Граф контроля управления)

ЛР №5:
* Автоматизированное тестирование (использование фреймворков)
Рекомендуемая литература: Адам Фримен, Стивен Сандерсон "ASP.NET MVC 4 Framework с примерами на C# для профессионалов". 4-е издание


**По каждой лабе отчёт**

[примеры отчëтов](https://drive.google.com/folderview?id=18i40trnqhWeI-9_d8qQIuGmInX7iKd5f)

____________________________________

[Лекция 1. Введение (08.09.2020)](https://drive.google.com/file/d/1-pMKyrxKTTLofEffDx6PoXvwXECZby1N/view?usp=sharing)
____________________________________

[Лекция 2. Введение. Классификация видов тестирования. (14.09.2020)](https://drive.google.com/file/d/18cLNMmhsQ6fCxbWoreu_CZy_KO60Xkic/view?usp=sharing)
____________________________________

[Лекция 3. Требования к ПО. Тестирование документации и требований. (21.09.2020)](https://drive.google.com/file/d/1wBldO40Rh1e-V9BR2McLtSgB0CyTGoXM/view?usp=sharing)
____________________________________

[Лекция 4. Техники тестирования. (28.09.2020)](https://drive.google.com/file/d/1D-DFHT82Loa6cJSzy17EYUoU_OtYZeq8/view?usp=sharing) | [audio](https://drive.google.com/drive/folders/1RekFZfeuajk7gNvyHAR6rSigM033o1qF?usp=sharing)
____________________________________

[Лекция 5. Модульное тестирование. (05.10.2020)](https://drive.google.com/file/d/1kTVlcA73TDJHM9Mh8FuaTrRQTVJCFoup/view?usp=sharing) | [audio](https://drive.google.com/drive/folders/11ngSoIteME78-oTaD_ujpYJGJrsAkkXO?usp=sharing) | [photo](https://drive.google.com/drive/folders/1lgU7g5CspAllpdu2v8-ri8Jfz7_R7Tvm?usp=sharing)
____________________________________

[Лекция 6-7. Интеграционное тестирование. (12 и 19.10.2020)](https://drive.google.com/file/d/1JcfzPhxwmwWCKy_kqri9eKNWoiLCPC6S/view?usp=sharing) | [audio](https://drive.google.com/file/d/1zN698MQXnfbvJbO1cop7Yh9jX0DNHl7o/view?usp=sharing) | [photo](https://drive.google.com/file/d/1iSft5A-ang56okmeDQAYuqVUdq5S5S_M/view?usp=sharing)
____________________________________

[Лекция 8. Системное и регресионное тестирование. (09.11.2020)](https://drive.google.com/file/d/10G80kY88QkTejT4VC7u5YaY8u0xZ3peP/view?usp=sharing)
____________________________________

[Лекция 9. Тестирование польз. интерфейса и web-приложения. Автоматизированное тестирование. (09.11.2020)](https://drive.google.com/file/d/1RivtU8Z_V5z3ycdAxU6XThIDMsEB9FhK/view?usp=sharing)
____________________________________


[Лаба zebrate](https://github.com/dKosarevsky/zebrate)

[фикстуры](https://github.com/ClearcodeHQ/pytest-postgresql) для тестирования базёнки

[Сервис](https://app.code2flow.com/) для отрисовки CFG (Control Flow Graph).
Код для отрисовки к 3-й лабе до изменений:
```
def generate_zebra();
if(user_img) {
  //  изображение загруженное пользователем
  Image.open(user_img);
} else {
  //  изображение по ссылке
  Image.open(BytesIO(response.content));
}
//  комплекс методов
zebra generation;
```
и после:
```
def generate_zebra();
if(user_img) {
  //  файл загруженный пользователем
  if(img) {
    Image.open(user_img);
  } else {
    //  конвертируем
    convert_from_bytes(user_img.read())
  }
} else {
  //  изображение по ссылке
  Image.open(BytesIO(response.content));
}
//  комплекс методов
zebra generation;
```
last_version:
```
def generate_zebra();
if(user_img) {
  //  файл загруженный пользователем
  if(img) {
    Image.open(user_img);
  } else {
    //  конвертируем
    convert_from_bytes(user_img.read())
  }
} else {
  //  изображение по ссылке
  Image.open(BytesIO(response.content));
}
// cсылка на скачивание лошади
call horse_download_link;
//  комплекс методов
zebra generation;
// cсылка на скачивание тензора
call tensor_download_link;
  //  отображение зебры
  st.image(zebra);
    // cсылка на скачивание зебры
    call zebra_download_link;
```


27.11 - дополнительное занятие (теория - повтор 23.11) в 19.00
После теории будет проводиться защита л.р.
При защите сдается общий отчет, с демонстрацией работы тестов и ответами на вопросы, и выставляется оценка.
Крайний срок защиты - 7.12

В случае, если тестируется простое консольное приложение, для выполнения 5 лабораторной работы можно и достаточно использовать руководство
https://docs.microsoft.com/en-us/visualstudio/test/writing-unit-tests-for-c-cpp?view=vs-2019
и написать набор автоматизированных модульных тестов (подпадающих под требования к модульному тестированию)  с использованием CPPUnitTest от Microsoft

https://discord.gg/cBcxK3yG
