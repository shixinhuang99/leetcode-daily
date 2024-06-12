#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn num_rook_captures(board: Vec<Vec<char>>) -> i32 {
        let mut rook = (0, 0);
        let directions = [(0, -1), (1, 0), (0, 1), (-1, 0)];
        let mut ret = 0;

        for (y, row) in board.iter().enumerate() {
            for (x, ch) in row.iter().enumerate() {
                if *ch == 'R' {
                    rook = (x as i32, y as i32);
                    break;
                }
            }
        }

        for dir in directions {
            let mut v_rook = rook;

            loop {
                v_rook.0 += dir.0;
                v_rook.1 += dir.1;

                if v_rook.0 < 0 || v_rook.0 > 7 || v_rook.1 < 0 || v_rook.1 > 7
                {
                    break;
                }

                match board[v_rook.1 as usize][v_rook.0 as usize] {
                    'p' => {
                        ret += 1;
                        break;
                    }
                    'B' => {
                        break;
                    }
                    _ => (),
                }
            }
        }

        ret
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    fn test_solution() {
        //
    }
}
