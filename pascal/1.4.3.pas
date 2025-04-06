program FindMinimumProduct;

uses
  SysUtils;

var
  n, i, j: Integer;
  A, C: array of Real;
  product, minProduct: Real;

begin
  // Вводим количество элементов массивов
  Write('Enter amount of elements in array: ');
  ReadLn(n);

  // Инициализируем массивы
  SetLength(A, n);
  SetLength(C, n);

  // Вводим данные для массивов A и C
  for i := 0 to n - 1 do
  begin
    Write('Enter element A', i + 1, ': ');
    ReadLn(A[i]);
    Write('Enter element C', i + 1, ': ');
    ReadLn(C[i]);
  end;

  // Инициализируем минимальное произведение большим значением
  minProduct := MaxInt;

  // Цикл для вычисления произведений и нахождения наименьшего среди них
  for i := 1 to n do
  begin
    product := 1;
    for j := 0 to i - 1 do
    begin
      product := product * (A[j] + C[j]);
    end;
    if product < minProduct then
    begin
      minProduct := product;
    end;
  end;

  // Выводим наименьшее произведение
  WriteLn('The lowest value: ', minProduct:0:4);
end.