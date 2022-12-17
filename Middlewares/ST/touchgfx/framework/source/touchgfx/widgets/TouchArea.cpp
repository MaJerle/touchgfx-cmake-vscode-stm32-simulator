/******************************************************************************
* Copyright (c) 2018(-2022) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.20.0 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

#include <touchgfx/widgets/TouchArea.hpp>

namespace touchgfx
{
class ClickEvent;

void TouchArea::handleClickEvent(const ClickEvent& event)
{
    AbstractButton::handleClickEvent(event);
    if (pressedAction && pressedAction->isValid() && pressed)
    {
        pressedAction->execute(*this);
    }
}
} // namespace touchgfx
