import numpy as np

def compute_qkv(X, W_q, W_k, W_v):
    Q = np.matmul(X, W_q)
    K = np.matmul(X, W_k)
    V = np.matmul(X, W_v)

    return (Q, K, V)


def softmax(x):
    exp_x = np.exp(x - np.max(x, axis = -1, keepdims = True))
    softmax_ = exp_x / np.sum(exp_x, axis = -1, keepdims = True)
    return softmax_


def self_attention(Q, K, V):
    weights = np.matmul(Q, K.transpose(0, 2, 1)) / np.sqrt(K.shape[-1])
	
    # In Case Mask is given just add the mask to the weights array before passing to the softmax [weights = weights + mask]
 
    
    softmax_weights = softmax(weights)
    
    attention_output = np.matmul(softmax_weights, V)

    return attention_output


def multi_head_attention(Q, K, V, n_heads):
    head_dim = K.shape[-1] // n_heads
    seq_len = Q.shape[0]

    # Reshape from (seq_len, d_model) to (seq_len, n_heads, head_dim) and then transpose to (n_heads, seq_len, head_dim)
    Q_ = np.reshape(Q, (seq_len, n_heads, head_dim)).transpose(1, 0, 2)
    K_ = np.reshape(K, (seq_len, n_heads, head_dim)).transpose(1, 0, 2)
    V_ = np.reshape(V, (seq_len, n_heads, head_dim)).transpose(1, 0, 2)

    attention_scores = self_attention(Q_, K_, V_).transpose(1, 0, 2).reshape((seq_len, n_heads * head_dim))

    return attention_scores
