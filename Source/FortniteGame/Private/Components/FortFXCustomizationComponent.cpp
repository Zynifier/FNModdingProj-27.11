// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortFXCustomizationComponent.h"

UFortFXCustomizationComponent::UFortFXCustomizationComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortFXCustomizationComponent::ApplyFXCustomizationInternal(UFXSystemComponent* TargetFXComp)
{
	return false;
}

bool UFortFXCustomizationComponent::ApplyFXCustomizationToActor(const AActor* SourceActor, const AActor* TargetActor, const bool bApplyToChildActors)
{
	return false;
}

bool UFortFXCustomizationComponent::ApplyFXCustomizationToComponent(const AActor* SourceActor, UFXSystemComponent* TargetFXComp)
{
	return false;
}
