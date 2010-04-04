/**

Game Develop - Primitive Drawing Extension
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

#include "GDL/Access.h"
#include "GDL/Instruction.h"
#include "GDL/ObjectsConcerned.h"
#include "GDL/RuntimeScene.h"
#include "DrawerObject.h"

bool DrawerObject::CondOutlineSize( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & condition, const Evaluateur & eval )
{
    //optimisation : le test de signe en premier
    if (( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Equal && GetOutlineSize() == eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Inferior && GetOutlineSize() < eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Superior && GetOutlineSize() > eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::InferiorOrEqual && GetOutlineSize() <= eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::SuperiorOrEqual && GetOutlineSize() >= eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Different && GetOutlineSize() != eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) )
       )
    {
       return true;
    }

    return false;
}


/**
 * Test the fill color opacity
 */
bool DrawerObject::CondFillOpacity( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & condition, const Evaluateur & eval )
{
    //optimisation : le test de signe en premier
    if (( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Equal && GetFillOpacity() == eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Inferior && GetFillOpacity() < eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Superior && GetFillOpacity() > eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::InferiorOrEqual && GetFillOpacity() <= eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::SuperiorOrEqual && GetFillOpacity() >= eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Different && GetFillOpacity() != eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) )
       )
    {
       return true;
    }

    return false;
}

/**
 * Test the opacity
 */
bool DrawerObject::CondOutlineOpacity( RuntimeScene * scene, ObjectsConcerned & objectsConcerned, const Instruction & condition, const Evaluateur & eval )
{
    //optimisation : le test de signe en premier
    if (( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Equal && GetOutlineOpacity() == eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Inferior && GetOutlineOpacity() < eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Superior && GetOutlineOpacity() > eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::InferiorOrEqual && GetOutlineOpacity() <= eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::SuperiorOrEqual && GetOutlineOpacity() >= eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) ) ||
            ( condition.GetParameter( 2 ).GetAsCompOperator() == GDExpression::Different && GetOutlineOpacity() != eval.EvalExp( condition.GetParameter( 1 ), shared_from_this() ) )
       )
    {
       return true;
    }

    return false;
}