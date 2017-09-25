#ifndef MUDBASE_AWSBASE_H
#define MUDBASE_AWSBASE_H

#include <aws/core/Aws.h>

namespace mudbase {

    class AWSBase {
        public:
            AWSBase();
            void initialize();
            void shutdown();

            static bool initialized_;

        private:
            Aws::SDKOptions options_;
    };

}

#endif //MUDBASE_AWSBASE_H

// vim:ts=4:sw=4:ai:et:si:sts=4
