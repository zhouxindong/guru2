#pragma once

/**
 * 
 *1. duration: tick + ratio(second)

 std::chrono::duration<int> sec20(20);
 std::chrono::duration<double, std::ration<60>> halfmin(0.5);

 std::chrono::nanoseconds
 std::chrono::microseconds
 std::chrono::milliseconds;
 std::chrono::seconds;
 std::chrono::minutes;
 std::chrono::hours;

 duration运算的两个值，其单位类型可以不同，其构造函数也接受不同单位类型的参数作为初始值
 .count() 返回tick值
 duration::period() 返回单位类型ratio(second)
 duration_cast<D>(d) 将d显式转换为不同的duration

 std::chrono::milliseconds ms(7255042);
 std::chrono::hours h = duration_cast<hours>(ms);
 std::chrono::minutes m = duration_cast<minutes>(ms % chrono::hours(1));
 std::chrono::seconds s = duration_cast<seconds>(ms % chrono::minutes(1));
 std::chrono::milliseconds ms = duration_cast<milliseconds>(ms % chrono::seconds(1));
 */

/**
 * 2. clock: a epoch
 system_clock -> real-time clock
 steady_clock -> elapse time
 high_resolution_clock -> shortest tick
 */

/**
 *  
 *3. timepoint: duration + epoch(clock)
 epoch: 由时钟的时间点缺省构造函数生成 std::chrono::system_clock::time_point tp;

 timepoint t
 timepoint t(tp2)
 timepoint t(d)
 time_point_cast<C, D> (tp)	将tp转换为一个以clock C和duration D表现的tp
 tp op tp
 tp op duration
 .time_since_epoch() 返回一个duration表示epoch和tp之间的时间跨度

 typedef chrono::duration<int, ratio<3600*24>> Days;
 chrono::time_point<chrono::system_clock> tp; // epoch of system clock
 tp += Days(1) + chrono::hours(23) + chrono::minutes(55);

 auto diff = tp - chrono::system_clock::time_point();
 chrono::duration_cast<chrono::minutes>(diff).count();
 */
