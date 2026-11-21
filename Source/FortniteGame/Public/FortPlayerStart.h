// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "GameplayTagContainer.h"
#include "FortPlayerStart.generated.h"

class AController;
class UParticleSystemComponent;

UCLASS(MinimalAPI, HideCategories=("Collision", "Collision", "Lighting", "LightColor", "Force"), ClassGroup=("Common"))
class AFortPlayerStart : public APlayerStart
{
	GENERATED_BODY()

public:
	AFortPlayerStart(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Transient)
	TObjectPtr<AController> ClaimingController;

	UPROPERTY(EditDefaultsOnly, Category="Player Start Claiming")
	float ExpirationCheckInterval;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> StartParticleComponent;

	UPROPERTY(EditAnywhere, Category="FortPlayerStart")
	FGameplayTagContainer StartPointTags;

};

