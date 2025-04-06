const
  SIZE = 5;

type
  TMatrix = array[1..SIZE, 1..SIZE] of Real;

var
  A: TMatrix;
  i, j: Integer;
  maxRowIndex, maxColIndex: Integer;
  maxRowSum, maxColSum: Real;

procedure InputMatrix(var M: TMatrix);
begin
  WriteLn('Enter elements of matrix:');
  for i := 1 to SIZE do
    for j := 1 to SIZE do
    begin
      Write('Enter element A[', i, ',', j, ']: ');
      ReadLn(M[i, j]);
    end;
end;

procedure FindMaxRowSum(const M: TMatrix; var maxIndex: Integer; var maxSum: Real);
var
  i, j: Integer;
  sum: Real;
begin
  maxSum := -MaxInt;
  for i := 1 to SIZE do
  begin
    sum := 0;
    for j := 1 to SIZE do
      sum := sum + M[i, j];
    if sum > maxSum then
    begin
      maxSum := sum;
      maxIndex := i;
    end;
  end;
end;

procedure FindMaxColSum(const M: TMatrix; var maxIndex: Integer; var maxSum: Real);
var
  i, j: Integer;
  sum: Real;
begin
  maxSum := -MaxInt;
  for j := 1 to SIZE do
  begin
    sum := 0;
    for i := 1 to SIZE do
      sum := sum + M[i, j];
    if sum > maxSum then
    begin
      maxSum := sum;
      maxIndex := j;
    end;
  end;
end;

procedure CalculateSum(const M: TMatrix; rowIndex, colIndex: Integer; var sum: Real);
var
  i: Integer;
begin
  sum := 0;
  for i := 1 to SIZE do
  begin
    sum := sum + M[rowIndex, i] + M[i, colIndex];
  end;
  // Убираем двойной счет элемента на пересечении строки и столбца
  sum := sum - M[rowIndex, colIndex];
end;

begin
  // Вводим данные для матрицы
  InputMatrix(A);

  // Находим строку с максимальной суммой элементов
  FindMaxRowSum(A, maxRowIndex, maxRowSum);

  // Находим столбец с максимальной суммой элементов
  FindMaxColSum(A, maxColIndex, maxColSum);

  // Проверяем, совпадают ли номера строки и столбца
  if maxRowIndex = maxColIndex then
  begin
    // Вычисляем сумму элементов строки и столбца
    CalculateSum(A, maxRowIndex, maxColIndex, maxRowSum);
    WriteLn('Sum of row and column elements: ', maxRowSum:0:2);
  end
  else
  begin
    // Выводим номера строки и столбца с максимальными суммами
    WriteLn('Row number with maximum amount: ', maxRowIndex);
    WriteLn('Column number with maximum sum: ', maxColIndex);
  end;
end.