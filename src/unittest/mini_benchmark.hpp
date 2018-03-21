#pragma once
#include <thread>
#include <iostream>
#include <functional>
#include <chrono>
#include <boost/progress.hpp>

#define BEGIN_MINI_BENTCHMARK(name, total) size_t all_##name = size_t(total); \
                                           std::cout<<"\n\nmini benchmark begin to run " << #name << " ..."<<std::endl; \
                                           boost::progress_display run_progress_##name(all_##name); \
                                           auto begin_##name = std::chrono::steady_clock::now()

#define POST_SUCCESS_COUNT(name, count) run_progress_##name += (unsigned int)(count)

#define END_MINI_BENTCHMARK(name)   auto end_##name = std::chrono::steady_clock::now();\
                                    auto cost_milliseconds_##name = std::chrono::duration_cast<std::chrono::milliseconds>(end_##name - begin_##name);\
                                    if (cost_milliseconds_##name.count() == 0) {\
                                        ++cost_milliseconds_##name;\
                                    }\
                                    std::cout << "\ntotal iterations " << all_##name\
                                    << " cost time " << cost_milliseconds_##name.count() / 1000 << " seconds\n" << std::endl;\
                                    std::cout << #name << ": " << (1000 * all_##name) / cost_milliseconds_##name.count() << "  iterations/s\n" << std::endl

#define BEGIN_MINI_BENTCHMARK_TIMER(name, total, getDone) BEGIN_MINI_BENTCHMARK(name, total);\
                                                          bool timer_run_##name = true;\
                                                          std::function<int64_t()> get_lambda_##name = (getDone);\
                                                          std::thread timer_thread_##name([&]() mutable {\
                                                              long old_v = 0L;\
                                                              while (timer_run_##name){\
                                                                  long new_v = get_lambda_##name();\
                                                                  long delta = new_v - old_v;\
                                                                  old_v = new_v;\
                                                                  run_progress_##name += delta;\
                                                                  std::chrono::milliseconds dura(100);\
                                                                  std::this_thread::sleep_for(dura);\
                                                              }\
                                                          })
                                                          
#define END_MINI_BENTCHMARK_TIMER(name, all) auto end_##name = std::chrono::steady_clock::now();\
                                             timer_run_##name = false;\
                                             timer_thread_##name.join();\
                                             auto cost_milliseconds_##name = std::chrono::duration_cast<std::chrono::milliseconds>(end_##name - begin_##name);\
                                             if (cost_milliseconds_##name.count() == 0) {\
                                             ++cost_milliseconds_##name;\
                                             }\
                                             std::cout << "\ntotal iterations " << (all)\
                                             << " cost time " << cost_milliseconds_##name.count() / 1000 << " seconds\n" << std::endl;\
                                             std::cout << #name << ": " << (1000 * (all)) / cost_milliseconds_##name.count() << "  iterations/s\n" << std::endl



#define BEGIN_MINI_MEASURE(name) std::cout<<"\n\nmini measure begin to run " << #name << " ..."<<std::endl; \
                                 auto begin_##name = std::chrono::steady_clock::now()

#define END_MINI_MEASURE(name, total) auto end_##name = std::chrono::steady_clock::now();\
                                      auto cost_milliseconds_##name = std::chrono::duration_cast<std::chrono::milliseconds>(end_##name - begin_##name);\
                                      if (cost_milliseconds_##name.count() == 0) {\
                                        ++cost_milliseconds_##name;\
                                      }\
                                      std::cout << "\ntotal iterations " << (total)\
                                      << " cost time " << cost_milliseconds_##name.count() / 1000 << " seconds\n" << std::endl;\
                                      std::cout << #name << ": " << (1000 * (total)) / cost_milliseconds_##name.count() << "  iterations/s\n" << std::endl

