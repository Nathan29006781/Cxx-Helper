

inline consteval long double sqrt_const(long double number)
{
  long double guess = number/2.0;
  long double prev_guess = number;

	while(guess != prev_guess){
    prev_guess = guess;
    guess = (guess+number/guess)/2;
  }

  return guess;
}