LeetCode - 968
  
If Node needs to be covered by a Camera it sends -1 to parent
If Node has a Camera it sends 0 to the parent
If Node does not have a Camera but is somehow covered it sends 1 to the parent

class Solution {
public:
    int cameras = 0;
    
    int minCameraCover(TreeNode* root) {
        // Special Case if Root Node needs cameras
        if(minCameras(root) == -1)
            cameras++;
        
        return cameras;
    }
    
    int minCameras(TreeNode* root){
        if(root == NULL)
            return 1;
        
        int lc = minCameras(root->left);
        int rc = minCameras(root->right);
        
        // If any of left child or right child needs to be covered
        // Parents acquire a camera
        if(lc == -1  ||  rc == -1){
            cameras++;
            return 0;
        }
        
        // If any of left child or right child has a camera
        // Parent is covered and passes the info to its parent
        if(lc == 0  ||  rc == 0)
            return 1;
        
        // If neither of rc or lc has a camera but is covered
        // Pass info to parent that you need to be covered
        return -1;
    }
};
