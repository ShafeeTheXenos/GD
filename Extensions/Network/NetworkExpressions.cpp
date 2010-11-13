/**

Game Develop - Network Extension
Copyright (c) 2008-2010 Florian Rival (Florian.Rival@gmail.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.

*/

#include "GDL/ExpressionInstruction.h"
#include "GDL/RuntimeScene.h"
#include "GDL/ObjectsConcerned.h"
#include "ReceivedDataManager.h"
#include "ErrorManager.h"

string ExpGetReceivedDataString( const RuntimeScene & scene, ObjectsConcerned & objectsConcerned, ObjSPtr obj1, ObjSPtr obj2, const StrExpressionInstruction & exprInstruction )
{
    std::string title = exprInstruction.parameters[0].GetAsTextExpressionResult(scene, objectsConcerned);

    return ReceivedDataManager::getInstance()->strings[title];
}

double ExpGetReceivedDataValue( const RuntimeScene & scene, ObjectsConcerned & objectsConcerned, ObjSPtr obj1, ObjSPtr obj2, const ExpressionInstruction & exprInstruction )
{
    std::string title = exprInstruction.parameters[0].GetAsTextExpressionResult(scene, objectsConcerned);

    return ReceivedDataManager::getInstance()->values[title];
}

string ExpGetLastError( const RuntimeScene & scene, ObjectsConcerned & objectsConcerned, ObjSPtr obj1, ObjSPtr obj2, const StrExpressionInstruction & exprInstruction )
{
    return ErrorManager::getInstance()->GetLastError();
}
