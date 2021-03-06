//  -------------------------------------------------------------------------
//  Copyright (C) 2014 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#include <assert.h>

#include "PlatformAbstraction/PlatformTypes.h"

#include "TestScenes/Triangle.h"

#include "ramses-client-api/RamsesClient.h"
#include "ramses-client-api/Scene.h"
#include "ramses-client-api/Vector3fArray.h"
#include "ramses-client-api/Appearance.h"
#include "ramses-client-api/GeometryBinding.h"
#include "ramses-client-api/AttributeInput.h"
#include "ramses-client-api/Effect.h"
#include "ramses-client-api/DataVector4f.h"

namespace ramses
{
    Triangle::Triangle(RamsesClient& client, Scene& scene, const Effect& effect, enum TriangleAppearance::EColor color, float alpha, TriangleGeometry::EVerticesOrder vertOrder)
        : m_appearance(scene, effect, color, alpha)
        , m_geometry(client, scene, effect, vertOrder)
    {
    }

    void Triangle::setColor(enum TriangleAppearance::EColor color, float alpha)
    {
        m_appearance.setColor(color, alpha);
    }

    void Triangle::bindColor(const DataVector4f& colorDataObject)
    {
        m_appearance.bindColor(colorDataObject);
    }

    void Triangle::unbindColor()
    {
        m_appearance.unbindColor();
    }
}
