#ifndef STACKPAC
#define STACKPAC
template <class T, int n>
class STACK
{
private:T a[n];
		int counter;
public: void ClearStack() { counter = 0; }
		bool EmptyStack() { return (counter == 0) ? true : false; }
		bool FullStack() { return (counter == n) ? true : false; }
		void PushStack(T x) { a[counter] = x; counter++; }
		T PopStack() { counter--; return a[counter]; }
};
#endif
