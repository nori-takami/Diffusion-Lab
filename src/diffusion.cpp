#include "diffusion.hpp"

int randomWalk(int N, std::mt19937& rand)
{
   std::uniform_int_distribution<int> dist(1,2);
   int currentPosition = 0;
   for (int i = 0; i < N; i++)
   {
      if (dist(rand) == 1)
      {
         currentPosition++;
      } else
      {
         currentPosition--;
      }
   }
   return currentPosition;
}
