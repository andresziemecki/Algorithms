def isPal(word):
    if (len(word) == 1):
        return True
    else:
        A = [0]*26
        for w in word.lower():
            A[ord(w) - ord('a')] = A[ord(w) - ord('a')] + 1
        total_impairs = 0
        for e in A:
            if (e%2 != 0):
                total_impairs = total_impairs + 1
            if (total_impairs == 2):
                return False
        return True
T = int(input());
for t in range(1,T+1):
    N, Q = [int(f) for f in input().split(' ')];
    Palindrome = str(input())
    total = 0
    for q in range(Q):
        L, R = [int(f) for f in input().split(' ')];
        subPal = Palindrome[L-1:R]
        if (isPal(subPal)):
            total = total + 1
    print("Case #{}: {}".format(t, total), flush=True)
