const
  SIZE = 5;

var
  i, j: Integer;
  A: array[1..SIZE, 1..SIZE] of Real;
  C: array[1..SIZE] of Real;
  hasEqualElements: Boolean;

begin
  // Вводим данные для матрицы A
  WriteLn('Enter elements of matrix A:');
  for i := 1 to SIZE do
    for j := 1 to SIZE do
    begin
      Write('Enter element A[', i, ',', j, ']: ');
      ReadLn(A[i, j]);
    end;

  // Вводим данные для массива C
  WriteLn('Enter element of array C:');
  for i := 1 to SIZE do
  begin
    Write('Enter element C[', i, ']: ');
    ReadLn(C[i]);
  end;

  // Проверяем, имеются ли равные элементы в массиве C
  hasEqualElements := False;
  for i := 1 to SIZE - 1 do
    for j := i + 1 to SIZE do
      if C[i] = C[j] then
      begin
        hasEqualElements := True;
        Break;
      end;

  // Если имеются равные элементы, изменяем значения элементов массива C
  if hasEqualElements then
  begin
    for i := 1 to SIZE do
      for j := 1 to SIZE do
        C[i] := C[i] + A[j, i];
  end;

  // Выводим измененный массив C
  WriteLn('Modified array C:');
  for i := 1 to SIZE do
    WriteLn('C[', i, ']: ', C[i]:0:2);
end.