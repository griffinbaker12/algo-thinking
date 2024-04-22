str = "abc"


def gen_contiguous_substrings(s):
    sub_strs = []
    for i in range(len(s)):
        for j in range(i + 1, len(s) + 1):
            sub_strs.append(str[i:j])


print(gen_contiguous_substrings(str))

# let's just say the only input is the string...you'd need to build recursive function inside


def gen_contiguos_substrings_rec(s):
    def recurse(s, start):
        if start == len(s):
            return []
        curr_substrings = [s[start:end] for end in range(start + 1, len(s) + 1)]
        return curr_substrings + recurse(s, start + 1)

    return recurse(s, 0)


print(gen_contiguos_substrings_rec(str))


def gen_combos1(s, path="", index=0):
    if index == len(s):
        return [
            path
        ]  # No more characters to consider; return current path as a combination

    # Include the current character and generate further combinations
    combinations_including_current = gen_combos1(s, path + s[index], index + 1)

    # Exclude the current character and generate further combinations
    combinations_excluding_current = gen_combos1(s, path, index + 1)

    # Combine all combinations from both scenarios and return
    return combinations_including_current + combinations_excluding_current


def gen_combos2(str):
    if not str:
        return [""]

    head = str[0]
    tl = str[1:]

    all_cs = []
    tail_combos = gen_combos2(tl)

    for tail_combo in tail_combos:
        all_cs.append(tail_combo)
        all_cs.append(head + tail_combo)

    return all_cs


def are_both_approaches_equal(arr1, arr2):
    return set(arr1) == set(arr2)


print(are_both_approaches_equal(gen_combos1(str), gen_combos2(str)))
