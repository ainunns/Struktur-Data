#include <iostream>
#include <queue>
using namespace std;

typedef struct products {
  int id;
  mutable int whenProcessed;
  int processingTime;
  int processed;
  int whenBlocked;
  int blockingTime;
  bool blockedBefore;
  bool processedBefore;
  bool operator<(const struct products &p) const {
    return (p.whenProcessed < whenProcessed) ||
           (p.id < id && p.whenProcessed == whenProcessed);
  }
} Products;

int main() {
  int timeout;
  cin >> timeout;
  int t, lp, b, lb;
  int item = 1;
  priority_queue<Products> machine;
  while (true) {
    Products produk;
    cin >> t;
    if (t == -1)
      break;
    cin >> lp >> b >> lb;
    produk.id = item++;
    produk.whenProcessed = t;
    produk.processed = 0;
    produk.processingTime = lp;
    produk.whenBlocked = b;
    produk.blockingTime = lb;
    produk.blockedBefore = false;
    produk.processedBefore = false;
    machine.push(produk);
  }

  Products currProcess;
  int timer = 0;
  while (!machine.empty()) {
    currProcess = machine.top();
    machine.pop();
    currProcess.processedBefore = true;
    timer = max(timer, currProcess.whenProcessed);
    printf("%d: Mesin mengerjakan produk %d\n", timer, currProcess.id);

    if (currProcess.whenBlocked <= timeout &&
        currProcess.blockedBefore == false) {
      timer += currProcess.whenBlocked;
      currProcess.processed += currProcess.whenBlocked;
      currProcess.blockedBefore = true;
      currProcess.whenProcessed = timer + currProcess.blockingTime;
      machine.push(currProcess);
      printf("%d: Mesin memblokir produk %d\n", timer, currProcess.id);
      continue;
    }

    if (!currProcess.processedBefore) {
      if (timeout >= currProcess.processingTime) {
        timer += currProcess.processingTime;
        printf("%d: Mesin menyelesaikan produk %d\n", timer, currProcess.id);
        continue;
      } else {
        timer += timeout;
        currProcess.processed += timeout;
        currProcess.whenProcessed = timer;
        printf("%d: Mesin mengembalikan produk %d\n", timer, currProcess.id);
        machine.push(currProcess);
        continue;
      }
      // kalo sebelumnya udah di processed, terus sisanya kurang dari timeout
    } else {
      // else, kita oper ke belakang antrian
      if (currProcess.processingTime - currProcess.processed <= timeout) {
        timer += currProcess.processingTime - currProcess.processed;
        printf("%d: Mesin menyelesaikan produk %d\n", timer, currProcess.id);
        continue;
      } else {
        timer += timeout;
        currProcess.processed += timeout;
        currProcess.whenProcessed = timer;
        printf("%d: Mesin mengembalikan produk %d\n", timer, currProcess.id);
        machine.push(currProcess);
        continue;
      }
    }
  }
}