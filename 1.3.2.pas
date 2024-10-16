uses Math;

var
  x, result, productTerm, lnTerm: real;
  n, k: integer;

begin
  // Задаем значения N, A и B
  x := 0.5;
  n := 20;

  // Кубический корень из x^2 через Power
  result := n * Power(x, 2/3);

  // Переменная для произведения
  productTerm := 1.0;

  // Вычисление произведения
  for k := 1 to n do
  begin
    lnTerm := ln(sqrt(k * abs(x)) + 1);
    productTerm := productTerm * (lnTerm / (1.02 - 1.0 / k));
  end;

  // Итоговая формула
  result := result + productTerm;

  writeln('Result: ', result:0:5);
end.