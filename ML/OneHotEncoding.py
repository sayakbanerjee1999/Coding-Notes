# x = np. array([0, 1, 2, 1, 0])
def to_categorical(x, n_col=None):
    # Your code here
    # If number of columns is not given
    if n_col == None:
        n_col = np.unique(x).shape[0] if 0 in x else np.unique(x).shape[0] + 1
    
    one_hot = np.zeros((x.shape[0], n_col))

    for i in range(x.shape[0]):
        one_hot[i, x[i]] = 1

    return one_hot
