// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_Visibility.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortMobileButtonBehaviorComponent_RegistryFlagVisibility.generated.h"

UCLASS()
class UFortMobileButtonBehaviorComponent_RegistryFlagVisibility : public UFortMobileButtonBehaviorComponent_Visibility, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="HUD Visibility")
	float LevelToTest;

	UPROPERTY(EditDefaultsOnly, Category="HUD Visibility")
	FScalableFloat RegistryToTest;

};

