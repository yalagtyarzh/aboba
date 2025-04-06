uses
  Math;

var
  n, i: Integer;
  R, H: array of Real;
  volume, totalVolume: Real;

begin
  // Вводим количество резервуаров
  Write('Enter the number of tanks: ');
  ReadLn(n);

  // Инициализируем массивы
  SetLength(R, n);
  SetLength(H, n);

  // Вводим данные для каждого резервуара
  for i := 0 to n - 1 do
  begin
    Write('Enter radis R', i + 1, ': ');
    ReadLn(R[i]);
    Write('Enter filling level H', i + 1, ': ');
    ReadLn(H[i]);
  end;

  totalVolume := 0;

  // Цикл для вычисления объема горючего в каждом резервуаре
  for i := 0 to n - 1 do
  begin
    // Вычисляем объем горючего в текущем резервуаре
    volume := Pi * Sqr(H[i]) * (R[i] - H[i] / 3);

    // Суммируем объемы
    totalVolume := totalVolume + volume;
  end;

  // Выводим общий объем горючего
  WriteLn('Total fuel volume: ', totalVolume:0:4);
end.