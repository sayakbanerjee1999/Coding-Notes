import numpy as np

def simple_conv2d(input_matrix: np.ndarray, kernel: np.ndarray, padding: int, stride: int):
    input_height, input_width = input_matrix.shape
    kernel_height, kernel_width = kernel.shape
    
    # Your code here
    padded_image = np.pad(input_matrix, 
                        pad_width = padding, 
                        mode='constant')
    # print(padded_image)

    output_h = (input_height-kernel_height+2*padding)//stride + 1
    output_w = (input_width-kernel_width+2*padding)//stride + 1

    output_matrix = np.zeros((output_h, output_w))
    
    # print(output_matrix)

    # Multiplying i, j with stride is key
    for i in range(output_h):
        for j in range(output_w):
            if (i*stride + kernel_height <= padded_image.shape[0]) and (j*stride + kernel_width <= padded_image.shape[1]):
                output_matrix[i, j] = np.sum(kernel * padded_image[i*stride :i*stride+kernel_height, j*stride:j*stride+kernel_width])

    return output_matrix
