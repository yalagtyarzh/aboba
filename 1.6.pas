uses Math;

var
  A, X1, dX, X, Y: real;
  N, i: integer;

// function CubeRoot(value: real): real;
// begin
//   if value >= 0 then
//     CubeRoot := Power(value, 1/3)
//   else
//     CubeRoot := -Power(-value, 1/3);
// end;

begin
  // Задаём значения
  A := 1.5;          // Значение A
  X1 := 0.0;         // Начальное значение X
  dX := A / 5.0;     // Шаг изменения X
  N := 10;           // Количество значений

  // Инициализация начального значения X
  X := X1;

  Writeln('  X    |  Y  ');
  writeln('-------------');

  // Вычисляем N значений функции Y
  for i := 1 to N do
  begin
    // Общая часть формулы для обеих ветвей
    // Y := CubeRoot(4 * Power(A, 2)) - CubeRoot(Sqrt(Power((X + 2 * A), 2)));

    Y := Power(4 * Power(A, 2), 1/3) - Power(Power((X + 2 * A), 2), 1/3);

    // if Y < 0 then
    // begin
    //   X := X + dX;
    //   writeln(X:0:2, #9, 'not exist');
    //   continue;
    // end;

    if X < 0 then
    begin
      // При x < 0: выражение под корнем
      Y := Power(Y, 3/2);
    end
    else
    begin
      // При x >= 0: минус выносится за корень
      // ПО УСЛОВИЮ ЗАДАЧИ МИНУС ВЫНЕСЕН ЗА КОРЕНЬ, НО СКОРЕЕ ВСЕГО ЭТО ОШИБКА ЗАПИСИ ЗАДАЧИ
      Y := Power(-Y, 3/2);
    end;

    // Выводим значение X и соответствующее значение Y
    writeln(X:0:2, #9, Y:0:4);

    // Увеличиваем X на шаг dX
    X := X + dX;
  end;
end.