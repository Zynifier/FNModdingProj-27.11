// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortAthenaLivingWorldPointProviderInterface.generated.h"

USTRUCT(BlueprintType)
struct FFortAthenaLivingWorldPointProviderFilterRules
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI, BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UFortAthenaLivingWorldPointProviderInterface : public UInterface
{
	GENERATED_BODY()
};

class LAGERRUNTIME_API IFortAthenaLivingWorldPointProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void DisablePointProvider();

	UFUNCTION(BlueprintCallable)
	virtual void EnablePointProvider();

	UFUNCTION(BlueprintCallable)
	virtual void GetFiltersTags(FGameplayTagContainer& FilterTags) const;

	UFUNCTION(BlueprintCallable)
	virtual FVector GetPointProviderLocation();

	UFUNCTION(BlueprintCallable)
	virtual float GetPointProviderMaxRadius();

};

