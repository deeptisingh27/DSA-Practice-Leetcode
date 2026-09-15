class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        
        n = len(s)
        ans = 0
        start = 0  # Earliest start index available for the next palindrome
        
        # 2 * n - 1 possible centers for odd and even length expansions
        for center in range(2 * n - 1):
            l = center // 2
            r = l + (center % 2)
            
            # Expand outward from the center
            while l >= start and r < n and s[l] == s[r]:
                length = r - l + 1
                if length >= k:
                    # Greedily take the first valid palindrome found
                    ans += 1
                    start = r + 1
                    break
                l -= 1
                r += 1
                
        return ans