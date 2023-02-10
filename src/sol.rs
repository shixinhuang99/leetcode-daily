use serde::Deserialize;
use crate::utils::SolutionTrait;

#[derive(Deserialize, Debug)]
pub struct Args;

pub type Answer = ();

impl SolutionTrait for Args {
    type Output = Answer;

    fn get_output(self) -> Self::Output {
        unimplemented!();
    }
}

struct Solution;
