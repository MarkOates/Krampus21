

#include <Krampus21/DialogBoxes/YouGotAnItem.hpp>
#include <allegro5/allegro.h>


namespace Krampus21
{
namespace DialogBoxes
{


YouGotAnItem::YouGotAnItem(int item_num)
   : Krampus21::DialogBoxes::Base("YouGotAnItem")
   , item_num(item_num)
{
}


YouGotAnItem::~YouGotAnItem()
{
}


float YouGotAnItem::infer_age()
{
   return al_get_time() - get_created_at();
}
} // namespace DialogBoxes
} // namespace Krampus21


