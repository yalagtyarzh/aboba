const
  MAX_SIZE = 100;

var
  n, i, j: Integer;
  A: array[1..MAX_SIZE, 1..MAX_SIZE] of Real;
  sumDiagonal: Real;

begin
  // Вводим размер матрицы
  Write('Enter the matrix size n: ');
  ReadLn(n);

  if n > MAX_SIZE then
    n := MAX_SIZE;

  // Вводим данные для матрицы
  for i := 1 to n do
    for j := 1 to n do
    begin
      Write('Enter element A[', i, ',', j, ']: ');
      ReadLn(A[i, j]);
    end;

  // Инициализируем сумму элементов главной диагонали
  sumDiagonal := 0;

  // Двукратный цикл для изменения элементов под главной диагональю и вычисления суммы главной диагонали
  for i := 1 to n do
  begin
    for j := 1 to n do
    begin
      if i = j then
        sumDiagonal := sumDiagonal + A[i, j]
      else if i > j then
      begin
        if A[i, j] > A[j, i] then
          A[i, j] := (A[i, j] + A[j, i]) / 2;
      end;
    end;
  end;

  // Выводим измененную матрицу
  WriteLn('Modified matrix:');
  for i := 1 to n do
  begin
    for j := 1 to n do
      Write(A[i, j]:0:2, ' ');
    WriteLn;
  end;

  // Выводим сумму элементов главной диагонали
  WriteLn('Sum of the elements of the main diagonal: ', sumDiagonal:0:2);
end.