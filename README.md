# Modeling Time Series
This time I'll try to simple modeling of time series. First of all, let's descript our models:</br>
1. Polynomial model (special case is n = 2)
2. Hyperbolic model
3. Logarithmic model
# Polynomial model with n = 2
Imagine, that we have a function:</br>
<img src = "https://moluch.ru/blmcbn/49571/49571.008.png"></br>
Using least squares method, we have system of linear equations:</br>
<img src = "https://moluch.ru/blmcbn/49571/49571.019.png"></br>
To solve Cramer's rule, we need to find have:
Header determinant:</br>
<img src = "https://moluch.ru/blmcbn/49571/49571.020.png"></br>
Then, finding same determinants and changing columns, have 3 (for case n = 2) parameters: a,b,c
<img src = "https://moluch.ru/blmcbn/49571/49571.021.png"></br>
<img src = "https://moluch.ru/blmcbn/49571/49571.022.png"></br>
<img src = "https://moluch.ru/blmcbn/49571/49571.023.png"></br>
And parameters a,b,c we can find according to Cramer's rule:
<img src="https://latex.codecogs.com/svg.image?a&space;=&space;\frac{\Delta_1}{\Delta},&space;b&space;=&space;\frac{\Delta_2}{\Delta},&space;c&space;=&space;\frac{\Delta_3}{\Delta}" title="a = \frac{\Delta_1}{\Delta}, b = \frac{\Delta_2}{\Delta}, c = \frac{\Delta_3}{\Delta}" /></br>
Finally, we substitute our values into the equation:
<img src = "https://moluch.ru/blmcbn/49571/49571.007.png"></br>
