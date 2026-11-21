// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_SocialInspector.generated.h"

class AFortPlayerState;

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_SocialInspector : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerState> CurrentSocialInspectTarget;

};

