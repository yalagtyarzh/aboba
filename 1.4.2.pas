uses
  Math;

var
  n, i, countXi: Integer;
  X, Y, T: array of Real;

begin
  // Вводим количество элементов массивов
  Write('Enter amount of elements in array: ');
  ReadLn(n);

  // Инициализируем массивы
  SetLength(X, n);
  SetLength(Y, n);
  SetLength(T, n);

  // Вводим данные для массивов X и Y
  for i := 0 to n - 1 do
  begin
    Write('Enter element X', i + 1, ': ');
    ReadLn(X[i]);
    Write('Enter element Y', i + 1, ': ');
    ReadLn(Y[i]);
  end;

  countXi := 0;

  // Цикл для вычисления массива T и подсчета элементов, которые получили значения из массива X
  for i := 0 to n - 1 do
  begin
    if X[i] > Y[i] then
    begin
      T[i] := X[i];
      Inc(countXi);
    end
    else
      T[i] := Y[i];
  end;

  // Выводим массив T
  WriteLn('Array T:');
  for i := 0 to n - 1 do
    WriteLn('T', i + 1, ': ', T[i]:0:4);

  // Выводим количество элементов, которые получили значения из массива X
  WriteLn('Amount of elements, which received values from array X: ', countXi);
end.