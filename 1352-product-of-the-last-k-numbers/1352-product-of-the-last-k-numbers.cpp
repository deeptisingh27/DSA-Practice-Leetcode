class ProductOfNumbers {
public:
    vector<int> prefixProducts;
    
    ProductOfNumbers() {
        prefixProducts = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset the stream history since any product spanning across this 0 is 0
            prefixProducts = {1};
        } else {
            // Multiply the new number with the running product
            prefixProducts.push_back(prefixProducts.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProducts.size();
        
        // If k >= n, it means a 0 was encountered within the last k elements
        if (k >= n) {
            return 0;
        }
        
        // Divide the latest cumulative product by the product right before the last k elements
        return prefixProducts.back() / prefixProducts[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */