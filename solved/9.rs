impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 || (x != 0 && x % 10 == 0) {
            return false;
        }
        let mut a = 0;
        let mut b = x;
        while b > 0 {
            a = a * 10 + b % 10;
            b /= 10;
        }

        a == x
    }
}
