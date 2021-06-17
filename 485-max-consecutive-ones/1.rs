impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut cur = 0;
        for i in nums {
            if i == 1 {
                cur += 1;
            } else {
                if res < cur {
                    res = cur;
                }
                cur = 0;
            }
        }
        if res < cur {
            res = cur;
        }
        res
    }
}

struct Solution {}
fn main() {
    let nums = vec![1, 1, 0, 1, 1, 1];
    let res = Solution::find_max_consecutive_ones(nums);
    println!("{:?}", res);
}
