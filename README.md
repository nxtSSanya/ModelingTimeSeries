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
<img src = "https://studme.org/htm/img/33/3609/347.png"></br>
And to find her parameters we again need to solve linear system:</br>
<img src = "data:image/gif;base64,R0lGODlh0wBwAHcAMSH+GlNvZnR3YXJlOiBNaWNyb3NvZnQgT2ZmaWNlACH5BAEAAAAALAEAAQDSAG4AhgAAAAAAAAAAOgAAZgA6ZgA6kABmkABmtjoAADoAOjoAZjo6ADo6Zjo6kDpmkDpmtjqQ22YAAGYAOmYAZmY6AGY6OmZmZmZmkGaQkGaQ22a222a2/5A6AJA6OpA6ZpBmAJBmZpBmkJCQZpC225Db25Db/7ZmALZmOrZmZraQOraQZra2Zra2tra2/7bbtrbb/7b/27b//9uQOtuQZtu2Ztu2kNu2ttvbttv/ttv/29v///+2Zv+2kP/bkP/btv//tv//2wECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwECAwf/gACCg4SFhoeIiYqLjI2JPxQFLhQCG46XmI+Rk5WZnp+goaKjgjY4EQ46JhCkrYWmqKqsrrS1treCPQoxACaWuKO6vL7AxcbHiTIHAD8TvMieyszO0I00C7/V2ourADsFNy3bjt3f4eOGQBwEI+juheqWPQip74nxAPP19r0Dz/wAAwp0tCNAtoEIFwFR0UBHwmPqCjh8SNGQDwoBllUENm/Wxo08HqjS+NFWwYMlSckIwLKly5cuSR4yIVMlzJswaxqTIaBESlrqAvRkBMRERkU0awUdqtCozmIm/P2k9SNCAKmLqj4dlLRW1av/HkXYeivixKmtCh5l1BVRW1pq/8kSemusqkS0tFYG8JhMLl1XevkikgbN7lm8o5b6FPW3lWKEWhFTtYr1k1lcXysDjCzZVdxPPyogYCmAQVjPLOVu49y5VeCPrwOybp2Yg9DFFB9vHkvbVebTkCkDHzf7obBjnzcmt1c84fFjsStGd9ccE5ATe68HIPBPewAHKVAueo7IO3jxjXTnts1U0cq789qHqn4JRQkZBkC8mPdLHYEXvcjHCHnprAOgCQJe8tVdStmGk2CKLHiYIT1ksANTMjAoCn2Y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"></br>
