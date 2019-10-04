t = "{text to alphabet here}"
s = "{text to search here}"
end_of_word = "_\0_"	# represents the character that marks the end of the word

def insert(t, dic):
    """
    Inserts the 't' element in the dictionary. Each character of 't' it will be a node in dictionary tree.
    Return the dictionary 'dic' with the characters of 't' as tree nodes.

    Parameters:
    t: string term to insert.
    dic: dictionary in tree format. It may be empty or already filled.
    """
    if dic == {}:
        dic = {t[0]: {}}
    if len(t) == 1:
        if t in dic.keys():
            dic[t][end_of_word] = {}
        else:
            dic[t] = {end_of_word: {}}
        return dic
    else:
        if t[0] not in dic.keys():
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
    return True if end_of_word in sub_tree.keys() else False


# inserting words in the dictionary
dic_tree = {}
for term in t.upper().split():
    dic_tree = insert(term, dic_tree)

# show the terms found
for term in s.upper().split():
	if(term, search(term, dic_tree)):
        print (term)
