#include <aws/dynamodb/DynamoDBClient.h>
#include <aws/dynamodb/model/PutItemRequest.h>
#include <aws/dynamodb/model/GetItemRequest.h>
#include <aws/core/utils/Outcome.h>
#include "AWSDynamoDB.h"

namespace mudbase {

    AWSDynamoDB::AWSDynamoDB(std::string &table) :
            table_(table) {

        config_.scheme = Aws::Http::Scheme::HTTPS;
        config_.region = "us-west-2";
        config_.connectTimeoutMs = 30000;
        config_.requestTimeoutMs = 30000;

        client_ = Aws::DynamoDB::DynamoDBClient(config_);
    }

    bool AWSDynamoDB::putItem(ItemMap &item) {
        Aws::DynamoDB::Model::PutItemRequest putItemRequest;
        putItemRequest.WithTableName(table_.c_str());
        for (auto it = item.begin(); it != item.end(); ++it) {
            putItemRequest.AddItem(it->first.c_str(), it->second);
        }
        auto outcome = client_.PutItem(putItemRequest);

        if (outcome.IsSuccess()) {
            std::cout << "PutItem Success using IOPS " << outcome.GetResult().GetConsumedCapacity().GetCapacityUnits() << std::endl;
            return true;
        } else {
            std::cout << "PutItem failed with error " << outcome.GetError().GetMessage() << std::endl;
            return false;
        }
    }

    ItemMap AWSDynamoDB::getItem(ItemMap &item) {
        Aws::DynamoDB::Model::GetItemRequest getItemRequest;
        getItemRequest.WithTableName(table_.c_str());

        for (auto it = item.begin(); it != item.end(); ++it) {
            getItemRequest.AddKey(it->first.c_str(), it->second);
        }
        auto outcome = client_.GetItem(getItemRequest);

        if (!outcome.IsSuccess()) {
            std::cout << "GetItem failed with error " << outcome.GetError().GetMessage() << std::endl;
            return ItemMap();
        }

        std::cout << "GetItem Success using IOPS " << outcome.GetResult().GetConsumedCapacity().GetCapacityUnits() << std::endl;

        ItemMap outMap;
        auto inMap = outcome.GetResult().GetItem();
        for (auto it = inMap.begin(); it != inMap.end(); ++it) {
            outMap.insert(ItemPair(std::string(it->first.c_str()), it->second));
        }
        return outMap;
    }

} // namespace mudbase

// vim:ts=4:sw=4:ai:et:si:sts=4
