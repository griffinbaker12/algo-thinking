#include <stdint.h>
#include <stdio.h>

uint32_t jenkins_one_at_a_time_hash(const uint8_t *key, size_t length) {
  size_t i = 0;
  uint32_t hash = 0;
  while (i != length) {
    hash += key[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash;
}

int main() {
  const size_t key_size = 3; // Clearly a constant, not variable
  uint8_t key[key_size] = {0};
  uint32_t original_hash = jenkins_one_at_a_time_hash(key, key_size);

  int x = 12; // 1100
  int y = 10; // 1010
              // 0110 = 6
  printf("%u\n", x ^ y);

  // For each bit in the key
  for (size_t byte = 0; byte < key_size; byte++) {
    for (int bit = 0; bit < 8; bit++) {
      uint8_t old = key[byte];
      key[byte] ^= (1 << bit); // Flip the bit

      uint32_t new_hash = jenkins_one_at_a_time_hash(key, key_size);
      printf("Change in bit %d of byte %zu affects hash: %s\n", bit, byte,
             (new_hash != original_hash) ? "Yes" : "No");

      key[byte] = old; // Restore original value
    }
  }

  char *str1 = "hello";
  char *str2 = "hullo"; // Changed 'e' to 'u'
                        //
  uint32_t og_hash = jenkins_one_at_a_time_hash((uint8_t *)str1, 5);
  uint32_t second_hash = jenkins_one_at_a_time_hash((uint8_t *)str2, 5);

  printf("%d\n", og_hash);
  printf("%d\n", second_hash);
  return 0;
}
