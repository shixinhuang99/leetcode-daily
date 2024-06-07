#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn all_cells_dist_order(
        rows: i32,
        cols: i32,
        r_center: i32,
        c_center: i32,
    ) -> Vec<Vec<i32>> {
        let mut ret = vec![];

        for r in 0..rows {
            for c in 0..cols {
                ret.push(vec![r, c]);
            }
        }

        ret.sort_by(|a, b| {
            let d_a = (a[0] - r_center).abs() + (a[1] - c_center).abs();
            let d_b = (b[0] - r_center).abs() + (b[1] - c_center).abs();
            d_a.cmp(&d_b)
        });

        ret
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(1,2,0,0,vec![vec![0,0],vec![0,1]])]
    #[test_case(2,2,0,1,vec![vec![0,1],vec![0,0],vec![1,1],vec![1,0]])]
    #[test_case(2,3,1,2,vec![vec![1,2],vec![0,2],vec![1,1],vec![0,1],vec![1,0],vec![0,0]])]
    fn test_solution(
        rows: i32,
        cols: i32,
        r_center: i32,
        c_center: i32,
        mut ans: Vec<Vec<i32>>,
    ) {
        assert!(slice_eq_no_order(
            &mut Solution::all_cells_dist_order(rows, cols, r_center, c_center),
            &mut ans
        ));
    }
}
