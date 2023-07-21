class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        marked = [False for i in range(0, len(words))]
        for i in range(0, len(words)):
            for j in range(i + 1, len(words)):
                if words[i] == ''.join(list(reversed(words[j]))) and marked[i] == False and marked[j] == False:
                    marked[i] = True
                    marked[j] = True
        return len(list(filter(lambda x: x == True, marked)))//2
        