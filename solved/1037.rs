#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn is_boomerang(points: Vec<Vec<i32>>) -> bool {
        fn calc_len(pa: &[i32], pb: &[i32]) -> f32 {
            let la = (pa[0] - pb[0]).abs();
            let lb = (pa[1] - pb[1]).abs();
            ((la.pow(2) + lb.pow(2)) as f32).sqrt()
        }

        fn is_eq(a: f32, b: f32, c: f32) -> bool {
            (a + b - c).abs() < 0.00001
        }

        let la = calc_len(&points[0], &points[1]);
        let lb = calc_len(&points[0], &points[2]);
        let lc = calc_len(&points[1], &points[2]);

        !(is_eq(la, lb, lc) || is_eq(la, lc, lb) || is_eq(lb, lc, la))
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(vec![vec![1,1],vec![2,3],vec![3,2]], true)]
    #[test_case(vec![vec![1,1],vec![2,2],vec![3,3]], false)]
    #[test_case(vec![vec![0,0],vec![11,22],vec![18,36]], false)]
    fn test_solution(points: Vec<Vec<i32>>, ans: bool) {
        assert_eq!(Solution::is_boomerang(points), ans);
    }
}
