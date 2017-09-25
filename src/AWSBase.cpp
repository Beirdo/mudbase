#include <aws/core/Aws.h>
#include "AWSBase.h"

namespace mudbase {

    bool AWSBase::initialized_ = false;

    AWSBase::AWSBase() :
            options_() {
        options_.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Info;
        initialize();
    }

    void AWSBase::initialize() {
        if (!initialized_) {
            Aws::InitAPI(options_);
            initialized_ = true;
        }
    }

    void AWSBase::shutdown() {
        if (initialized_) {
            Aws::ShutdownAPI(options_);
            initialized_ = false;
        }
    }

} // namespace mudbase

// vim:ts=4:sw=4:ai:et:si:sts=4
