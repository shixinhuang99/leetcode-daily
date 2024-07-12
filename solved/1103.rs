#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn distribute_candies(mut candies: i32, num_people: i32) -> Vec<i32> {
        let mut x = 1;
        let mut people = vec![0; num_people as usize];

        while candies > 0 {
            for n in people.iter_mut() {
                if candies <= 0 {
                    break;
                }
                if x > candies {
                    x = candies;
                }
                *n += x;
                candies -= x;
                x += 1;
            }
        }

        people
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(7,4,vec![1,2,3,1])]
    #[test_case(10,3,vec![5,2,3])]
    fn test_solution(candies: i32, num_people: i32, ans: Vec<i32>) {
        assert_eq!(Solution::distribute_candies(candies, num_people), ans);
    }
}
