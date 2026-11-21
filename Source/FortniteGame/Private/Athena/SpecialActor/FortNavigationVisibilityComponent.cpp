// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/SpecialActor/FortNavigationVisibilityComponent.h"

TArray<FName> UFortNavigationVisibilityComponent::Editor_GetValidObjectives() const
{
	return TArray<FName>();
}

TArray<FString> UFortNavigationVisibilityComponent::Editor_GetValidProfileStats() const
{
	return TArray<FString>();
}

void UFortNavigationVisibilityComponent::HandleActiveCameraChanged(FGameplayTag CameraTag)
{
}

void UFortNavigationVisibilityComponent::HandlePlayerChanged(AFortPlayerController* NewRoomOwner)
{
}

void UFortNavigationVisibilityComponent::MakeActorHidden()
{
}

void UFortNavigationVisibilityComponent::MakeActorVisable()
{
}
