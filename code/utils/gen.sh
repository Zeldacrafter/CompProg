while <command>; do :; done

while ./gen.out > t.in && ./sol.out < t.in > 1.out &&
      ./check.out < t.in > 2.out && diff 1.out 2.out; do :; done
