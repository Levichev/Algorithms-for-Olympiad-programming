# Мануал по ДП
---
Динамическое программирование  — способ решения сложных задач путём разбиения их на более простые подзада. 

Структура ДП
Чтобы успешно решить задачу динамикой нужно:
1) Состояние динамики: параметр(ы), однозначно задающие подзадачу.
2) Значения начальных состояний.
3) Переходы между состояниями: формула пересчёта.
4) Порядок пересчёта.
5) Положение ответа на задачу: иногда это сумма или, например, максимум из значений нескольких состояний.


## Задача о Рюкзаке


**Задача о рюкзаке** (англ. Knapsack problem) — дано **N** предметов, **n[i]** предмет имеет массу **w[i] > 0** и стоимость **p[i] > 0**. Необходимо выбрать из этих предметов такой набор, чтобы суммарная масса не превосходила заданной величины **W** (вместимость рюкзака), а суммарная стоимость была максимальна.

Есть несколько вариаций этой задачи, рассмотрим некоторые из них в порядке возрастания сложности  

1)
- **w[i] == c[i]**  
- **∑w[i] <= W**  
- **∑w[i] → max**  

**Решение:**  
База
```python
for i = 1..W:
  dp[i][0] = 0
  
for j = 0..N:
  dp[0][j] = 1
```
Состояние
**d[i][j]** - можно ли набрать сумму **j** с помощью первых **i** предметов (Не обязательно брать все предметы) 

Формула
**d[i][j] = max( d[i-1][j], d[i-1][j-w[i]] )**

Ответ
```python
for i = W..0:
  if dp[N][i] == 1:
    ans = i
```
**w[i]** == **c[i]**  

![Frame 16](https://user-images.githubusercontent.com/35433764/114986024-281ce080-9e9c-11eb-9058-07ca9cac690c.png)
![Frame 17](https://user-images.githubusercontent.com/35433764/114986023-27844a00-9e9c-11eb-9c4b-798c18c5a815.png)
![Frame 18](https://user-images.githubusercontent.com/35433764/114986022-27844a00-9e9c-11eb-912f-ea8e78ca861b.png)
![Frame 19](https://user-images.githubusercontent.com/35433764/114986019-26ebb380-9e9c-11eb-9a91-d94ddb3bce72.png)
![Frame 20](https://user-images.githubusercontent.com/35433764/114986018-26531d00-9e9c-11eb-8f98-6f52014f8e7b.png)
![Frame 21](https://user-images.githubusercontent.com/35433764/114986016-25ba8680-9e9c-11eb-8718-54eb8f0d45e2.png)

## Задача о Рюкзаке со стоимостью

![Frame 9](https://user-images.githubusercontent.com/35433764/114986394-9cf01a80-9e9c-11eb-8710-a75e970b0b26.png)
![Frame 10](https://user-images.githubusercontent.com/35433764/114986392-9cf01a80-9e9c-11eb-988b-6528608bc1ef.png)
![Frame 11](https://user-images.githubusercontent.com/35433764/114986390-9c578400-9e9c-11eb-85aa-83799bdf39e8.png)
![Frame 12](https://user-images.githubusercontent.com/35433764/114986388-9c578400-9e9c-11eb-8909-c62e3d2b97ed.png)
![Frame 13](https://user-images.githubusercontent.com/35433764/114986386-9bbeed80-9e9c-11eb-898c-6e9b08b23fa0.png)
![Frame 14](https://user-images.githubusercontent.com/35433764/114986382-9b265700-9e9c-11eb-8c17-a89c11dfffae.png)
![Frame 15](https://user-images.githubusercontent.com/35433764/114986381-9a8dc080-9e9c-11eb-8af5-ac275c5061bc.png)
