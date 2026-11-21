// Copyright Epic Games, Inc. All Rights Reserved.

#include "Item/FortItemCountTextBlock.h"

UFortItemCountTextBlock::UFortItemCountTextBlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortItemCountTextBlock::HandleItemCountChanged(UFortItemDefinition* Definition, int32 Delta)
{
}

void UFortItemCountTextBlock::InterpolateOverrideToValue(const int32 TargetValue, float MaximumInterpolationDuration, float MinimumChangeRate, float OutroOffset)
{
}

void UFortItemCountTextBlock::SetCountStyle(EFortItemCountStyle InCountStyle)
{
}

void UFortItemCountTextBlock::SetItemDefinition(UFortItemDefinition* InItemDefinition)
{
}

void UFortItemCountTextBlock::SetOverrideValue(int32 InOverrideValue)
{
}
