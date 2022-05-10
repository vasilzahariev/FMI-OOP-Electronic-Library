#define CATCH_CONFIG_MAIN

#include "Catch2.h"
#include "../Electronic Library/Book.h"

TEST_CASE("Book Tester") {
	Book book("Lubi", "SDP", "sdp.txt", "Mn qk predmet", 5, ISBN("1234567890123"));

	REQUIRE(strcmp(book.getAuthor(), "Lubi") == 0);
}
