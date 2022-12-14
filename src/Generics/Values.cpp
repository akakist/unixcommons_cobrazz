#include <Generics/Values.hpp>


namespace Generics
{
  namespace ValuesHelper
  {
    const Values::StoredType StoredMember<Values::SignedInt>::TYPE;
    Values::SignedInt
    Values::StoredValue::* const StoredMember<Values::SignedInt>::MEMBER =
      &Values::StoredValue::signed_int;

    const Values::StoredType StoredMember<Values::UnsignedInt>::TYPE;
    Values::UnsignedInt
    Values::StoredValue::* const StoredMember<Values::UnsignedInt>::MEMBER =
      &Values::StoredValue::unsigned_int;

    const Values::StoredType StoredMember<Values::Floating>::TYPE;
    Values::Floating
    Values::StoredValue::* const StoredMember<Values::Floating>::MEMBER =
      &Values::StoredValue::floating;

    const Values::StoredType StoredMember<Values::String>::TYPE;
    Values::String
    Values::StoredValue::* const StoredMember<Values::String>::MEMBER =
      &Values::StoredValue::string;

    const Values::StoredType StoredMember<char*>::TYPE;
    Values::String
    Values::StoredValue::* const StoredMember<char*>::MEMBER =
      &Values::StoredValue::string;

    const Values::StoredType StoredMember<const char*>::TYPE;
    Values::String
    Values::StoredValue::* const StoredMember<const char*>::MEMBER =
      &Values::StoredValue::string;
  }

  //
  // Values class
  //

  const char* const Values::STORED_TYPES_[] =
  {
    "Signed Int",
    "Unsigned Int",
    "Floating",
    "String",
  };

  Values::Values(size_t table_size) /*throw (eh::Exception)*/
    : data_(table_size)
  {
  }

  void
  Values::swap(Values& values) /*throw (eh::Exception)*/
  {
    Sync::PosixGuard guard(mutex_);
    data_.swap(values.data_);
  }

  void
  Values::swap_(Values& values) /*throw (eh::Exception)*/
  {
    data_.swap(values.data_);
  }
}
