#ifndef MUDBASE_AWSDYNAMODB_H
#define MUDBASE_AWSDYNAMODB_H

#include <aws/dynamodb/DynamoDBClient.h>
#include <map>
#include "AWSBase.h"

typedef std::pair<std::string, Aws::DynamoDB::Model::AttributeValue> ItemPair;
typedef std::map<std::string, Aws::DynamoDB::Model::AttributeValue> ItemMap;

namespace mudbase {

    class AWSDynamoDB : public AWSBase {
        public:
            AWSDynamoDB(std::string &table);
            bool putItem(ItemMap &item);
            ItemMap getItem(ItemMap &searchItem);

        private:
            Aws::Client::ClientConfiguration config_;

        protected:
            Aws::DynamoDB::DynamoDBClient client_;
            const std::string &table_;
    };

}

#endif //MUDBASE_AWSDYNAMODB_H

// vim:ts=4:sw=4:ai:et:si:sts=4
