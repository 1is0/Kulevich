//---------------------------------------------------------------------------

#ifndef StackH
#define StackH
//---------------------------------------------------------------------------

struct Operations
{
  char ch;
  Operations* prev;
};

struct Numerals
{
  float ch;
  Numerals* prev;
};

typedef enum
{
  all_true = 1,
  fault
}errors;

class St
{
public:
  Operations* pointer1;
  Numerals* pointer2;
  char* f_str;
  char* s_str;
  void initialize();
  void check();
  void put_spaces();
  void postfix();
  float calc(float a, float b, float c, float d, float e);
  void find_errors();
  errors err_code;
  ~St();
private:
  int pr_stack();
  bool operand_true(char c);
  void op_create(char c);
  void op_push(char c);
  char op_pop();
  void num_create(float c);
  void num_push(float c);
  float num_pop();
};
#endif

