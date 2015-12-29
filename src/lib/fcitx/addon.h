/*
 * Copyright (C) 2015~2015 by CSSlayer
 * wengxt@gmail.com
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; see the file COPYING. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#ifndef _FCITX_ADDON_H_
#define _FCITX_ADDON_H_

#include <memory>
#include <fcitx-utils/macros.h>
#include <fcitx-config/enum.h>
#include "fcitxcore_export.h"

namespace fcitx
{

FCITX_CONFIG_ENUM(AddonType, SharedLibrary)

class AddonInfoPrivate;

class FCITXCORE_EXPORT AddonInfo {
public:
    AddonInfo();
    virtual ~AddonInfo();

    bool isValid() const;
    const std::string &name() const;
    AddonType type() const;

    void loadInfo(RawConfig &config);

private:
    std::unique_ptr<AddonInfoPrivate> d_ptr;
    FCITX_DECLARE_PRIVATE(AddonInfo);
};

}

#endif // _FCITX_ADDON_H_
