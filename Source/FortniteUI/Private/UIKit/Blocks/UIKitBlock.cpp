// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIKit/Blocks/UIKitBlock.h"

UUIKitBlock::UUIKitBlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

float UUIKitBlock::GetTransitionTime(EUIKitBlockVisualState State)
{
	return float();
}

void UUIKitBlock::PlayTransition(UWidgetAnimation* Animation, const bool bPlayForward)
{
}

void UUIKitBlock::RequestInstantTransition(EUIKitBlockInstantTransitionState State)
{
}

void UUIKitBlock::RequestTransition(EUIKitBlockVisualState State)
{
}

void UUIKitBlock::SetBlockTiming(const FUIKitBlockTiming& Timing)
{
}
