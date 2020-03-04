
#include <stdio.h>

int main( int argc, const char* argv[] ){
  printf( "\n Hello, and welcome to Bellingham Trail!\n\n" );
  printf( "<> To start off, where would you like to begin your journey?\n" );
  printf( "  (1) Stanwood\n  (2) Seatle\n  (3) Yelm\n\n");

  int answer;
  char* response = NULL;
  while (response == NULL){
    printf( "<> (1 , 2, or 3?):  ");
    scanf( "%d", &answer );
    switch ( answer ) {
      case 1:
        response = "Ah, going for the tiny town of Stanwood are we?  Very... interesting place, that one.\n\n";
        break;
      case 2:
        response = "The Emerald City!  I don't check in with the Seahawks much these days, but I do hope they're getting plenty of home runs!\n\n";
        break;
      case 3:
      response = "Yelm?  That's somewhere near Olympia, right?\n\n";
        break;
      default:
        printf("\n<< I don't think I've heard of that one.\n\n");
    }
  }
  printf("\n>> %s", response);
}
