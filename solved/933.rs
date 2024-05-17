#[cfg(test)]
mod utils;

pub struct Solution;

// start
use std::collections::VecDeque;

struct RecentCounter {
    queue: VecDeque<i32>,
}

impl RecentCounter {
    fn new() -> Self {
        Self {
            queue: VecDeque::new(),
        }
    }

    fn ping(&mut self, t: i32) -> i32 {
        self.queue.push_back(t);

        while self.queue.front().is_some_and(|v| *v < t - 3000) {
            self.queue.pop_front();
        }

        self.queue.len() as i32
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(&[642,1849,4921,5936,5957], &[1,2,1,2,3])]
    fn test_solution(pings: &[i32], ans: &[i32]) {
        let mut rc = RecentCounter::new();
        let mut ret = vec![];
        for n in pings {
            ret.push(rc.ping(*n));
        }
        assert_eq!(ret, ans);
    }
}
