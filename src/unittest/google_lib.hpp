#pragma once
#include <gflags/gflags.h>
#include <gtest/gtest.h>
#include <glog/logging.h>

inline void InitGLogDefault() {
    //日志路径
    FLAGS_log_dir = "./logs";
    //最近一次日志打印的软连接路径
    FLAGS_log_link = "./";

    //日志最低级别
    FLAGS_minloglevel = google::INFO;

    FLAGS_logtostderr = false;
    FLAGS_alsologtostderr = false;
    FLAGS_colorlogtostderr = true;

    //WARNING以及以上的信息打印到stderr
    FLAGS_stderrthreshold = google::WARNING;

    FLAGS_logbuflevel = google::WARNING;
    FLAGS_logbufsecs = 10;
    FLAGS_max_log_size = 20; //MB
    FLAGS_stop_logging_if_full_disk = true;
}

inline void InitGTestDefault() {
    using namespace testing;
    FLAGS_gtest_filter= "*";
    FLAGS_gtest_list_tests = false;
    FLAGS_gtest_repeat = 1;
    FLAGS_gtest_color = "yes";
    FLAGS_gtest_print_time = true;
    //测试失败退出
    FLAGS_gtest_throw_on_failure = false;

    FLAGS_gtest_shuffle = false;

    //失败后进入调试器
    FLAGS_gtest_break_on_failure = false;

    //FLAGS_gtest_output = "xml:";

    //测试结果推送目的地址
    //FLAGS_gtest_stream_result_to = "127.0.0.1:8080";
}

inline void InitGoogle(int argc, char **argv) {
    InitGLogDefault();
    InitGTestDefault();
    google::AllowCommandLineReparsing();
    google::ParseCommandLineFlags(&argc, &argv, false);

    //初始化并设置日志前缀
    google::InitGoogleLogging(argv[0]);
    //WARNING以上的消息复制打印到BADINFO中
    google::SetLogDestination(google::WARNING, "./logs/TEST-BADINFO-");

    testing::InitGoogleTest(&argc, argv);
}

inline void UninitGoogle() {
    google::ShutdownGoogleLogging();
    google::ShutDownCommandLineFlags();
}
