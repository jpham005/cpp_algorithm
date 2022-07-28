#include <iostream>
#include <string>

using namespace std;

int breakPoint;

#define kQuestionArraySize 4

const static string kQuestionStrArray[kQuestionArraySize] = {
  "\"재귀함수가 뭔가요?\"",
  "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
  "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
  "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};

#define kAnswerArraySize 1

const static string kAnswerStrArray[kAnswerArraySize] = {
  "라고 답변하였지."
};

#define kBreakPointNotifierArraySize 3

const static string kBreakPointNotifierArray[kBreakPointNotifierArraySize] = {
  "\"재귀함수가 뭔가요?\"",
  "\"재귀함수는 자기 자신을 호출하는 함수라네\"",
  "라고 답변하였지."
};

void print_depth(int depth) {
  for (int i = 0; i < depth; i++) {
    cout << "____";
  }
}

void print_line(int depth, const string array[], int array_size) {
  for (int i = 0; i < array_size; i++) {
    print_depth(depth);
    cout << array[i] << endl;
  }
}

void printer(int depth) {
  if (depth == breakPoint) {
    print_line(depth, kBreakPointNotifierArray, kBreakPointNotifierArraySize);
    return;
  }

  print_line(depth, kQuestionStrArray, kQuestionArraySize);
  printer(depth + 1);
  print_line(depth, kAnswerStrArray, kAnswerArraySize);
}

int main() {

  cin >> breakPoint;

  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
  printer(0);
}
