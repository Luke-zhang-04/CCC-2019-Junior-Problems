rules = {}
rulesList = []

for _ in range(3):
    rule = input().split(" ")
    rules[rule[0]] = rule[1]
    rulesList.append(rule[0])

steps, initialSeq, finalSeq = input().split(" ")


class Node:
    def __init__(self, value, parent=None, ruleUsed=None, indexChanged=None):
        self.parent = parent
        self.children = []
        self.val = value
        self.leaves = []
        self.ruleUsed = ruleUsed
        self.indexChanged = indexChanged

    # gets child values by applying as many rules as possible
    def child_values(self, rules, steps):
        out_values = []
        val = self.val
        for i in range(len(val)):
            for rule in rules:
                if len(rule) <= len(val) - i:
                    for j in range(len(rule)):
                        if val[j + i] != rule[j]:
                            break
                    else:
                        temp_val = list(val)
                        temp_val[i : i + j + 1] = rules[rule]
                        out_values.append(["".join(temp_val), rule, i])

        for i in out_values:
            self.children.append(
                Node(i[0], parent=self, ruleUsed=i[1], indexChanged=i[2] + 1)
            )

        if steps > 0:
            for i in self.children:
                leaf = i.child_values(rules, steps - 1)
                if type(leaf) == list:
                    for j in leaf:
                        self.leaves.append(j)
                else:
                    self.leaves.append(leaf)

            return self.leaves
        else:
            return self

    def backtrack(self, leaf):
        output = []
        current = self
        for i in range(int(steps)):
            output.append(
                [
                    rulesList.index(current.ruleUsed) + 1,
                    current.indexChanged,
                    current.val,
                ]
            )
            current = current.parent
        for i in output[::-1]:
            print(*i)


top = Node(initialSeq)
top.child_values(rules, int(steps))
for i in top.leaves:
    if i.val == finalSeq:
        i.backtrack(i)
        break
