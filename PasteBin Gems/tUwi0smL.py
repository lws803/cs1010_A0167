def filter_and_transform_seqs(d):
    new_seqs = []
    new_labels = []
    indcs = []
    for i, s, vt in zip(np.arange(d.shape[0]), d.protein_sequence.get_values(), d.vector_type.get_values()):
        s = s.replace(" ", "").replace("*", '').replace(".", "")
        s = s.upper()
        if (len(s) == sum(list(map(lambda x: x.isalpha(), s)))):
            new_seqs.append(s)
            new_labels.append(vt)
            indcs.append(i)
    d = d.iloc[indcs]
    d['protein_sequence'] = new_seqs
    return d[d.columns[1:]].drop_duplicates()