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

 duration���������ֵ���䵥λ���Ϳ��Բ�ͬ���乹�캯��Ҳ���ܲ�ͬ��λ���͵Ĳ�����Ϊ��ʼֵ
 .count() ����tickֵ
 duration::period() ���ص�λ����ratio(second)
 duration_cast<D>(d) ��d��ʽת��Ϊ��ͬ��duration

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
 epoch: ��ʱ�ӵ�ʱ���ȱʡ���캯������ std::chrono::system_clock::time_point tp;

 timepoint t
 timepoint t(tp2)
 timepoint t(d)
 time_point_cast<C, D> (tp)	��tpת��Ϊһ����clock C��duration D���ֵ�tp
 tp op tp
 tp op duration
 .time_since_epoch() ����һ��duration��ʾepoch��tp֮���ʱ����

 typedef chrono::duration<int, ratio<3600*24>> Days;
 chrono::time_point<chrono::system_clock> tp; // epoch of system clock
 tp += Days(1) + chrono::hours(23) + chrono::minutes(55);

 auto diff = tp - chrono::system_clock::time_point();
 chrono::duration_cast<chrono::minutes>(diff).count();
 */
