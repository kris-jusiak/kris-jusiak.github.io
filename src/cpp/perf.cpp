perf stat ./bench

perf record ./bench
perf report

-fno-omit-frame-pointer
perf record -g ./bench
perf report -g

-fno-omit-frame-pointer
perf record -g ./bench
perf report -g 'graph,0.5,caller'

static void escape(void *p) {
	asm volatile("" : : "g"(p) : "memory");
}

static void clobber() {
	asm volatile("" : : : "memory");
}

std::vector<int> v;
escape(&v);
(void)v;

