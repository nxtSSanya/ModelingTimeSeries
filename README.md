# Modeling Time Series
This time I'll try to find regression model of time series. First of all, let's descript our models:</br>
1. Polynomial model (special case is n = 2)
2. Hyperbolic model
3. Logarithmic model
# Polynomial model with n = 2
Imagine, that we have a function:</br>
<img src = "https://moluch.ru/blmcbn/49571/49571.008.png"></br>
Using least squares method, we have system of linear equations:</br>
<img src = "https://moluch.ru/blmcbn/49571/49571.019.png"></br>
To solve system using Cramer's rule, at first, we need to find general determinant:</br>
<img src = "https://moluch.ru/blmcbn/49571/49571.020.png"></br>
Then, finding same determinants and changing columns, have 3 (for case n = 2) parameters: a,b,c
<img src = "https://moluch.ru/blmcbn/49571/49571.021.png"></br>
<img src = "https://moluch.ru/blmcbn/49571/49571.022.png"></br>
<img src = "https://moluch.ru/blmcbn/49571/49571.023.png"></br>
And parameters a,b,c we can find according to Cramer's rule:
<img src="https://latex.codecogs.com/svg.image?a&space;=&space;\frac{\Delta_1}{\Delta},&space;b&space;=&space;\frac{\Delta_2}{\Delta},&space;c&space;=&space;\frac{\Delta_3}{\Delta}" title="a = \frac{\Delta_1}{\Delta}, b = \frac{\Delta_2}{\Delta}, c = \frac{\Delta_3}{\Delta}" /></br>
Finally, we substitute our values into the equation:
<img src = "https://moluch.ru/blmcbn/49571/49571.007.png"></br>
# Hyperbolic model
We can present our model like:</br>
<img src="https://latex.codecogs.com/svg.image?\hat{y_i}&space;=&space;a_0&space;&plus;&space;a_1\frac{1}{t_i}" title="\hat{y_i} = a_0 + a_1\frac{1}{t_i}" /></br>
And to find her parameters we again need to solve linear system:</br>
<img src = "https://sun9-8.userapi.com/impg/R0YyocrYvi1D0CW6_56NZb0c_C-ag9iit0iwBw/3og3iybJ_mc.jpg?size=236x123&quality=96&sign=e33b229c7320d09694df161ffbfc9333&type=album"></br>
<img src="https://latex.codecogs.com/svg.image?a_1&space;=\frac{n\sum\frac{y_i}{x_i}&space;-&space;\sum&space;\frac{1}{x_i}\sum&space;y_i}{n\sum\frac{1}{x^2_i}&space;-&space;(\sum&space;\frac{1}{x_i})^2}" title="a_1 =\frac{n\sum\frac{y_i}{x_i} - \sum \frac{1}{x_i}\sum y_i}{n\sum\frac{1}{x^2_i} - (\sum \frac{1}{x_i})^2}" /></br>
<img src="https://latex.codecogs.com/svg.image?a_0&space;=&space;\frac{1}{n}&space;\sum&space;y_i&space;-&space;\frac{1}{n}a_1\sum&space;\frac{1}{x_i}" title="a_0 = \frac{1}{n} \sum y_i - \frac{1}{n}a_1\sum \frac{1}{x_i}" /></br>
# Logarithmic model
And finally, we have a function:
<img src = "http://simenergy.ru/MyArticles/Math_analysis_digital_processing/005/Ordinary_Least_Squares.files/image033.png"></br>
Linear system:</br>
<img src = "http://simenergy.ru/MyArticles/Math_analysis_digital_processing/005/Ordinary_Least_Squares.files/image034.png"></br>
Solution:
<img src = "http://simenergy.ru/MyArticles/Math_analysis_digital_processing/005/Ordinary_Least_Squares.files/image035.png"></br>
