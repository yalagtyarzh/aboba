const
  ROWS = 10;
  COLS = 2;

var
  i, count: Integer;
  students: array[1..ROWS, 1..COLS] of Integer;
  percentage: Real;

begin
  // Вводим данные для матрицы
  for i := 1 to ROWS do
  begin
    Write('Enter the total number of students in the group ', i, ': ');
    ReadLn(students[i, 1]);
    Write('Enter the number of excellent students in the group ', i, ': ');
    ReadLn(students[i, 2]);
  end;

  count := 0;

  // Выводим заголовок таблицы
  WriteLn('Groups with more than 15% excellent students:');
  WriteLn('-------------------------------');

  // Цикл для проверки условия и вывода номеров групп
  for i := 1 to ROWS do
  begin
    percentage := (students[i, 2] / students[i, 1]) * 100;
    if percentage > 15 then
    begin
      WriteLn('Group ', i);
      Inc(count);
    end;
  end;

  // Выводим общее число таких групп
  WriteLn('Total number of groups with more than 15% excellent students: ', count);
end.