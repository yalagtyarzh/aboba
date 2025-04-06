type
  TStudent = record
    Group: string[10];
    FIO: string[50];
    BirthYear: Integer;
    Gender: Char;
    PhysicsGrades: array[1..5] of Integer;
    MathGrades: array[1..5] of Integer;
    InformaticsGrades: array[1..5] of Integer;
    Scholarship: Real;
  end;

var
  Students: array[1..100] of TStudent;
  n, i, j: Integer;
  group: string[10];
  avgPhysics, avgMath, avgInformatics, avgTotal: Real;

function CalculateAverage(Grades: array of Integer): Real;
var
  sum, i: Integer;
begin
  sum := 0;
  for i := Low(Grades) to High(Grades) do
    sum := sum + Grades[i];
  CalculateAverage := sum / Length(Grades);
end;

begin
  // Вводим количество студентов
  Write('Enter amount of student: ');
  ReadLn(n);

  // Вводим данные о студентах
  for i := 1 to n do
  begin
    WriteLn('Enter data for the student ', i, ':');
    Write('Group: ');
    ReadLn(Students[i].Group);
    Write('FIO: ');
    ReadLn(Students[i].FIO);
    Write('Birthdate: ');
    ReadLn(Students[i].BirthYear);
    Write('Gender (M/F): ');
    ReadLn(Students[i].Gender);
    WriteLn('Physics grades: ');
    for j := 1 to 5 do
      Read(Students[i].PhysicsGrades[j]);
    WriteLn('Math grades: ');
    for j := 1 to 5 do
      Read(Students[i].MathGrades[j]);
    WriteLn('Computer Science Grades: ');
    for j := 1 to 5 do
      Read(Students[i].InformaticsGrades[j]);
    Write('Scholarship: ');
    ReadLn(Students[i].Scholarship);
  end;

  // Вводим номер группы для поиска
  Write('Enter group number to search: ');
  ReadLn(group);

  // Выводим студентов заданной группы с средним баллом больше 4.5
  WriteLn('Students of the group ', group, ' with an average score greater than 4.5:');
  for i := 1 to n do
  begin
    if Students[i].Group = group then
    begin
      avgPhysics := CalculateAverage(Students[i].PhysicsGrades);
      avgMath := CalculateAverage(Students[i].MathGrades);
      avgInformatics := CalculateAverage(Students[i].InformaticsGrades);
      avgTotal := (avgPhysics + avgMath + avgInformatics) / 3;
      if avgTotal > 4.5 then
        WriteLn(Students[i].FIO, ' - Average score: ', avgTotal:0:2);
    end;
  end;
end.