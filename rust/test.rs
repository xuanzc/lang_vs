use std::collections::VecDeque;
use std::time::Instant;
use std::cell::RefCell;
use std::num::Wrapping;

const LOOP_COUNT: usize = 1000000;

// 简单的线性同余生成器
thread_local! {
    static RNG: RefCell<Wrapping<u32>> = RefCell::new(Wrapping(12345));
}

// 生成随机数
fn rand() -> u32 {
    RNG.with(|rng| {
        let mut rng = rng.borrow_mut();
        *rng *= Wrapping(1103515245);
        *rng += Wrapping(12345);
        (*rng >> 16).0
    })
}

// 生成随机字符（A-Z, a-z, 0-9）
fn get_random_char() -> char {
    const CHARSET: &[u8] = b"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    let idx = (rand() as usize) % CHARSET.len();
    CHARSET[idx] as char
}

fn main() {
    let mut deque = VecDeque::new();
    let start = Instant::now();
    
    for _ in 0..LOOP_COUNT {
        // 生成随机字符并入队
        let c = get_random_char();
        deque.push_back(c);
        
        // 如果队列超过999，出队
        if deque.len() > 999 {
            deque.pop_front();
        }
    }
    
    let duration = start.elapsed();
    println!("Rust: {:?} milliseconds", duration.as_secs_f64() * 1000.0);
}