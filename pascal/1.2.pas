uses Math;

var
  N, i: Integer;
  A, B, x, step, result: Real;

begin
  // Задаем значения N, A и B
  N := 10;
  A := 0.55;
  B := 1;

  // Вычисляем шаг
  step := (B - A) / (N - 1);

  // Выводим заголовок таблицы
  WriteLn('  X    |  f(X)');
  WriteLn('---------------');

  // Цикл для вычисления и вывода значений функции
  for i := 0 to N - 1 do
  begin
    x := A + i * step;
    result := (1 / Sqrt(x)) + Sqr(Ln(Abs(0.2 + Sin(x)))) * Power(x, 2/3);
    WriteLn(x:0:4, ' | ', result:0:4);
  end;
end.