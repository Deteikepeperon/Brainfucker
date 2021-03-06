#include <iostream>
#include <fstream>
#include <sstream>

constexpr int MEMORY_SIZE = 30000;

constexpr char INCREMENT = '+';   // increment (increase by one) the byte at the data pointer
constexpr char DECREMENT = '-';   // decrement (decrease by one) the byte at the data pointer
constexpr char RIGHT     = '>';   // increment the data pointer (to point to the next cell to the right)
constexpr char LEFT      = '<';   // decrement the data pointer (to point to the next cell to the left)
constexpr char INPUT     = ',';   // accept one byte of input, storing its value in the byte at the data pointer
constexpr char OUTPUT    = '.';   // output the byte at the data pointer
constexpr char START     = '[';   // if the byte at the data pointer is zero, jump to immediately to the command after the matching ']' command
constexpr char END       = ']';   // if the byte at the data pointer is nonzero, jump to immediately to the command after the matching '[' command


int main(int argc, char *argv[])
{
  unsigned int memory_ptr = 0;          // a memory pointer
  unsigned int code_ptr = 0;            // a code pointer

  unsigned char memory[MEMORY_SIZE];    // an array of bytes with at least 30000 elements initialized to zero
  memset(memory, 0, sizeof(memory));


  // command line argument processing
  if (argc != 2) {
    std::cerr << "Error: A Brainfuck code is not passed as a command line argument." << std::endl;
    exit(1);
  };


  // file loading
  std::ifstream file(argv[1]);

  if (!file) {
    std::cerr << "Error: Cannot open the file." << std::endl;
    exit(1);
  };


  // file processing (get file as a buffer & get code as a string)
  std::stringstream buf;

  buf << file.rdbuf();
  std::string code(buf.str());


  // Brainfuck analysis
  while (code_ptr < code.size()) {
    switch (code[code_ptr]) {

      case INCREMENT:
        memory[memory_ptr]++;
        break;

      case DECREMENT:
        memory[memory_ptr]--;
        break;

      case RIGHT:
        memory_ptr = (memory_ptr == MEMORY_SIZE) ? 0 : memory_ptr += 1;
        break;

      case LEFT:
        memory_ptr = (memory_ptr == 0) ? MEMORY_SIZE - 1 : memory_ptr -= 1;
        break;

      case INPUT:
        memory[memory_ptr] = getchar();
        break;

      case OUTPUT:
        putchar(memory[memory_ptr]);
        break;

      case START:
        if (memory[memory_ptr] == 0) {
          int loop = 0;

          for (code_ptr++; loop > 0 || code[code_ptr] != ']'; code_ptr++) {
            if (code[code_ptr] == '[')  loop++;
            if (code[code_ptr] == ']')  loop--;
          }
        }
        break;

      case END:
        if (memory[memory_ptr] != 0) {
          int loop = 0;

          for (code_ptr--; loop > 0 || code[code_ptr] != '['; code_ptr--) {
            if (code[code_ptr] == ']') loop++;
            if (code[code_ptr] == '[') loop--;
          }

          code_ptr--;
        }
        break;

      default:
        break;
    }

    code_ptr++;
  }

  std::cout << std::endl;

  return 0;
}