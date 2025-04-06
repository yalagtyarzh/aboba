type
  TStore = record
    Name: string[50];
    District: string[50];
    Address: string[100];
    OpenHour: Integer;
    CloseHour: Integer;
  end;

var
  Stores: array[1..100] of TStore;
  n, i, count: Integer;
  district: string[50];

begin
  // Вводим количество магазинов
  Write('Enter the number of stores: ');
  ReadLn(n);

  // Вводим данные о магазинах
  for i := 1 to n do
  begin
    WriteLn('Enter details for the store ', i, ':');
    Write('Namew: ');
    ReadLn(Stores[i].Name);
    Write('District: ');
    ReadLn(Address[i].District);
    Write('Адрес: ');
    ReadLn(Stores[i].Address);
    Write('Open hour (0-23): ');
    ReadLn(Stores[i].OpenHour);
    Write('Close hour (0-23): ');
    ReadLn(Stores[i].CloseHour);
  end;

  // Вводим район для поиска
  Write('Enter area to search: ');
  ReadLn(district);

  count := 0;

  // Выводим книжные магазины данного района, работающие после 18 часов
  WriteLn('Bookstores in the area ', district, ' working after 18:00:');
  for i := 1 to n do
  begin
    if (Stores[i].District = district) and (Stores[i].CloseHour > 18) then
    begin
      WriteLn('Name: ', Stores[i].Name);
      WriteLn('Address: ', Stores[i].Address);
      WriteLn('Opening hours: ', Stores[i].OpenHour, ' - ', Stores[i].CloseHour);
      WriteLn;
      Inc(count);
    end;
  end;

  // Выводим количество таких магазинов
  WriteLn('Number of such stores: ', count);
end.