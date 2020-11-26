#pragma once

#include <iostream>

class List;
 
class Node
{
    int key;
    Node *prev, *next;
 
 public:
     Node() {key=-1; prev=0; next=0;}         //конструктор по умолчанию
     Node(int k, Node *pr, Node *nxt)
         {key=k; prev=pr; next=nxt;}          //конструктор с аргументами
 
    int &Key() {return key;}

    friend class List;
};

class List
{
    Node *head, *tail;
 
 public:
 
    List();         
    List(int n);                  //формирование списка из n случайных чисел
    List (int *a, int n);        //формирование списка из массива n чисел
    List(const List &s);             //конструктор копирования
    ~List();
    List & operator= (const List &s);

    void AddAfter (int x, Node *pr);        //добавление узла после заданного
    void AddToTail (int x);          //добавление элемента в хвост
    void AddToHead (int x);            //добавление элемента в голову
    void AddToTail (List S);            //добавление списка S в хвост
    void AddToHead (List S);         //добавление списка S в голову

    void Del (Node *p);                 //удаление элемента по указателю p
    void DelTail();                        //удаление элемента с хвоста
    void DelHead();                      //удаление элемента с головы

    Node *FindKey (int key);            //поиск в списке по ключу
    Node *FindPos (int pos);             //поиск в списке по позиции

    bool Empty();                              //проверка пустоты списка
    bool NotEmpty() ;                       //проверка непустоты списка
    bool Inside(int);						// Есть ли элемент внутри списка
    void Clear();                               //очистка списка


    bool operator == (List S) ;           //проверка равенства списков
    bool operator != (List S);             //проверка неравенства списков

    Node *Max();                             //нахождение max эл-та списка
    Node *Min();                              //нахождение min эл-та списка

    void Scan(int n);                         //ввод списка из n элементов
    void Print();                                //печать списка

    friend std::ostream & operator << (std::ostream &r, List &X);
    friend std::istream & operator >> (std::istream &r, List &X);

};
