package main

func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int)
	n := len(s)
	r, ans := -1, 0
	for i := 0; i < n; i++ {
		if i != 0 {
			delete(m, s[i-1])
		}
		for r+1 < n && m[s[r+1]] == 0 {
			m[s[r+1]]++
			r++
		}
		ans = max(ans, r-i+1)
	}
	return ans
}
