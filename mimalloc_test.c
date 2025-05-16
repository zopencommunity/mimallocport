#include <stdio.h>
#include <string.h>
#include "mimalloc.h"  // Make sure this header is in your include path

int main(void) {
  printf("Starting mimalloc direct API test...\n");

  // Allocate memory with mi_malloc
  size_t size = 1024;
  void* ptr = mi_malloc(size);
  if (ptr == NULL) {
    printf("mi_malloc failed!\n");
    return 1;
  }

  // Use the memory
  memset(ptr, 0xAB, size);
  printf("Memory allocated and initialized using mi_malloc.\n");

  // Aligned allocation
  void* aligned_ptr = mi_malloc_aligned(4096, 64);
  if (aligned_ptr == NULL) {
    printf("mi_malloc_aligned failed!\n");
    mi_free(ptr);
    return 1;
  }

  printf("Aligned memory allocated at %p\n", aligned_ptr);

  // Free the memory
  mi_free(ptr);
  mi_free(aligned_ptr);
  printf("Memory freed using mi_free.\n");

  // Optional: print stats
  mi_collect(true);  // collect reclaimed pages
  mi_stats_print(NULL);  // prints to stdout

  return 0;
}

