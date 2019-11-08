t = "{text to alphabet here}"
s = "{text to search here}"
end_of_word = "_\0_"	# represents the character that marks the end of the word

def insert(t, dic):
    """
    Recursive function that inserts the 't' element in the dictionary. Each character of 't' it will be a node in dictionary tree.
    Return the dictionary 'dic' with the characters of 't' as tree nodes.

    Parameters:
    t: array that will be indexed.
    dic: dictionary in tree format. It may be empty or already filled.
    """
    if dic == {}:
        dic = {t[0]: {}}
    if len(t) == 1:
        try: 	# using 'try' the computational cost is lower
            dic[t[0]][end_of_word] = {}
        except:
            dic[t[0]] = {end_of_word: {}}
        return dic
    else:
        try:
            dic[t[0]]
        except:
            dic[t[0]] = {}
        dic[t[0]] = insert(t[1:], dic[t[0]])
        return dic

def search(s, dic):
    """
    Returns True if the string s was found and False otherwise.

    Parameters:
    s: string that will be fetched from the dictionary.
    dic: dictionary in tree format.
    """
    if not s:
        return False
    sub_tree = dic
    for c in s:
        try:
            sub_tree = sub_tree[c]
        except:
            return False
    try:
      sub_tree[end_of_word]
    except:
      return False
    return True


# inserting words in the dictionary
dic_tree = {}
for term in t.upper().split():
    dic_tree = insert(term, dic_tree)

# show the terms found
for term in s.upper().split():
    if(search(term, dic_tree)):
        print(term)
