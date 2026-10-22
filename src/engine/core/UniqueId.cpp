#include "UniqueId.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

std::string Umbrella::UniqueId::GetId()
{
    std::string str;

    boost::uuids::random_generator generator;
    boost::uuids::uuid uuid = generator();

    str = boost::uuids::to_string(uuid);

    return str;
}
