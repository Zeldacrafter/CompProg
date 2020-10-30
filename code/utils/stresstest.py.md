---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import random\nimport subprocess\n\niterations = 1000000;\nmaxbits = 50000\n\
    minbits = 1\n\np = subprocess.Popen([\"./a.out\"], stdout=subprocess.PIPE,\n \
    \                    stdin=subprocess.PIPE,\n                     stderr=subprocess.PIPE)\n\
    i = 1\nwhile 1:\n    if (i % 1000 == 0):\n        print(i)\n    a = random.getrandbits(random.randrange(minbits,\
    \ maxbits + 1))\n    b = random.getrandbits(random.randrange(minbits, maxbits\
    \ + 1))\n    if bool(random.getrandbits(1)):\n        a *= -1\n    if bool(random.getrandbits(1)):\n\
    \        b *= -1\n    op = random.choice(['+', '-', '*'])\n    erg = 0\n    if\
    \ op == '+':\n        erg = a + b\n    elif op == '-':\n        erg = a - b\n\
    \    else:\n        erg = a * b\n\n    p.stdin.write(f'{op} {a} {b}\\n'.encode())\n\
    \    p.stdin.flush()\n    outs = p.stdout.readline().decode().rstrip()\n    if\
    \ outs != str(erg):\n        print(a)\n        print(op)\n        print(b)\n \
    \       print('=')\n        print(erg)\n        print(\"false:\")\n        print(outs)\n\
    \        f = open(\"wrong.in\", \"w\")\n        f.write(f\"{op}\\n{a}\\n{b}\\\
    n\")\n        f.close()\n        f = open(\"wrong.out\", \"w\")\n        f.write(str(erg)\
    \ + '\\n')\n        f.close()\n    i += 1\n\np.stdin.write('q'.encode())\np.stdin.flush()\n\
    p.wait();\n\nprint(\"100/100\")\n"
  dependsOn: []
  isVerificationFile: false
  path: code/utils/stresstest.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/utils/stresstest.py
layout: document
redirect_from:
- /library/code/utils/stresstest.py
- /library/code/utils/stresstest.py.html
title: code/utils/stresstest.py
---