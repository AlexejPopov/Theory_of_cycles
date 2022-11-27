﻿#include <iostream>
#include <locale.h>

using namespace std;

/*  Цикл - это конструкция для повторений действия в соответствии с заданным условием. Каждое повторение цикла называется его шаг или итерация. Цикл состоит из двух
    элементов:

     - заголовок, в нем указываются специальные настройки, если цикл их поддерживает либо условие работы цикла.
     - тело цикла, в нем располагаются команды, которые будут выполняться неоднократно.

       Есть два подхода написания цикла:
        1. Известно точное кол-во повторений тех или иных действий в цикле.
        2. Не известно точное количество повторений в цикле, но знаем условие когда эти действия должны повторяться или же должны закончиться.

   Циклы бывают трех видов:
    1. Цикл с предусловием (while) - цикл, в котором сначала проверяется условие и если условие истина, то выполняется действие, указанное в теле цикла.
    2. Цикл с постусловием (do while) - цикл, в котором сначала один раз выполнится все содержимое тела цикла, а потом будет проверено условие, которое определит нужно
       ли повторять эти действия. Если условие истина, то мы повторим эти действия, если условие ложь, то мы выйдем из цикла.
    3. Цикл с параметрами (for).

    Как создается цикл?
    1. Формулируется условие его работы
    2. Если цикл будет что-то подсчитывать, нам потребуется счетчик
    3. Пока его условие истина, он будет повторяться */

int main()
{
    setlocale(LC_ALL, "rus");
    int Count = 0;                                                      // счетчик количества отжиманий

    /* В цикле с предусловием сначала проверится условие. Если условие истина, то выполнится действие.
    Внутри, в круглых скобках у цикла указывается условие, результатом которого будет истина либо ложь (результат будет в типе данных bool).
    (!) Точка с запятой не ставится после круглых скобочек цикла while. */

    while (Count < 10)                                                  // пока (Сount!=10)
    {
        cout << "Мы отжались " << Count << " раз(а)!" << endl;          // нужен счетчик для выхода из бесконечного цикла, чтобы условие Count<10 перестало соблюдаться.
        Count++;                                                        // если увеличивать счетчик по Cout+=2, то будет 5 значений!
    }
    cout << Count << endl;

    /* Изменение счетчика на 1 сообщает сколько у нас будет повторений в цикле. В нашем случае 10 раз (от 0 до 10). Когда Count станет 10 мы выйдем из цикла.
    Условие, начальное значение счетчика, и как мы его меняем определяют количество повторений в цикле. Счет начинается с нуля!

    Когда мы заходим в цикл счетчик равен 0 и мы первым делом выводим счетчик на экран, а потом увеличиваем его на 1 (++). После того как мы дошли до фигурной закрываю-
    щейся скобки, она вернет нас снова к проверке условия, которое будет истиной т.к. у нас 1 (1<10). И после мы будем уже сравнивать 1-цу с 10-ю, и т.к. она меньше 10,
    снова зайдем в цикл, выведем на экран 1, потом увеличим до 2-х и так до тех пор пока условие истина.

    Как нам сделать так, чтобы считалось не от 0, а от 1? Есть три варианта:

        1. В вывод на экран мы добавим единицу. Сам счетчик меняться не будет, след, не повлияет на кол-во повторений, а повлияет лишь на то, что увидит пользователь
        на экране:

        cout << "Мы отжались " << Count + 1 << " раз(а)!" << endl;

        2. Переместить счетчик до вывода на экран, чтобы он успел прибавить единицу.
        Перемещение счетчика по циклу не влияет на количество повторений цикла, а влияет лишь на то, как мы сам счетчик используем.

        3. Поставить вместо 0 в Count единицу, но тогда в скобках нужно поставить <= 10!

    Рассмотрим на примере мытья посуды, моем пока не закончится грязная посуда.
    Вымоем заданное количество посуды в цикле. Пока количество посуды больше 0, моем и уменьшаем ее количество счетчиком. Когда посуды станет 0, посуда будет вымыта.

    (Если в количество посуды мы введем число вне диапазона значений цикла, то цикл не выполнится. Т.е. если условие цикла ложно, цикл будет проигнорирован компилятором.
    Чтобы цикл выполнился, необходимо чтобы значение в круглых скобках цикла обратилось в лог.истину) */

    int posuda = 0;
    cout << "Введите количество посуды: "; cin >> posuda;

    while (posuda > 0)
    {
        if (posuda == 0)cout << "Вся посуда вымыта!" << endl;                   // это условие никогда не сработает, т.к. с 0 цикл не выполнится
        else cout << "Осталось " << posuda << " посуды!" << endl;
        posuda--;                                                               // уменьшение посуды (счетчика)
    }

    /* Как прервать цикл во время работы?
    Break заставляет выйти из цикла. Все после него не будет выполнено.

    В цикле можно создавать комбинированные условия, прервать цикл если что-то не устраивает, например, если большое количество посуды.
    Все действия в цикле выполняются сверху вниз, а потом проверка условия, если условие истина, то снова весь цикл заново проверяется сверху вниз, а потом снова про-
    верка условия, и так снова и снова. И так до тех пор пока цикл не завершит свою работу или будет прерван ключевым словом break.

    Цикл позволяет пропустить свои некоторые итерации/повторения/шаги с помощью оператора сontinue.
    Когда компилятор обрабатывает continue, он пропускает все действия указанные в цикле дальше слова continue и переходит снова к проверке условия!
    А если уменьшение счетчика тоже будет пропущено, т.к. находится после continue, то сам цикл застопорится на одной цифре и станет бесконечным. Поэтому нужно обяза-
    тельно уменьшить переменную (счетчик) до continue (пропуска всех последующих действий, указанных в цикле).

    Правило (!)
    В циклах с предусловием и с постусловием при необходимости пропуска каких-либо действий, переменную (счетчик) необходимо изменять, а только потом пропускать! */

    int dishes = 0;
    cout << "Введите количество посуды: "; cin >> dishes;
    while (dishes > 0)
    {
        if (dishes > 15)
        {
            cout << "Слишком много грязной посуды! У меня нет столько времени!" << endl;
            break;
        }
        if (dishes == 5)
        {
            cout << "Сильное загрязнение! Пусть отмокает!" << endl;
            dishes--;                                                           // сначала уменьшаем значение переменной, а потом переходим к continue 
            continue;                                                           // переход к следующей итерации цикла
        }
        if (dishes == 0)cout << "Вся посуда вымыта!" << endl;
        else cout << "Осталось " << dishes << " посуды!" << endl;
        if (dishes == 2)
        {
            cout << "Домою потом!" << endl;
            break;                                                              // прерывает цикл и выходит из него!
        }
        dishes--;
    }
}

/* Когда количество посуды будет равно 2, сработает break и выведет нас из цикла. Т.к. следующее условие когда посуда равна нулю стоит после break, выполнится действие
при break и весь следующий блок IF в этом цикле проигнорируется. Последовательность действий в цикле важна! След, мы переставим условие с break вниз цикла, после выво-
да на экран, т.е. у нас сперва вывод на экран, а потом проверка.

Любой цикл работает тогда, когда условие выполняется (в круглых скобочках цикла получается истина) и работает до тех пор пока истина сохраняется. Но мы можем цикл в
люб.момент прервать с помощью break, написав при этом условие прерывания цикла. Также мы можем пропустить несколько повторений в цикле с помощью continue, прописав при
этом грамотно условие и не забыть изменить переменную (счетчик), чтобы не уйти в бесконечный цикл при пропуске каких-то действий. */