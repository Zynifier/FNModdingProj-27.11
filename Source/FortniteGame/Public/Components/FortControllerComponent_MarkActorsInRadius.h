// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "Components/FortControllerComponent_IndicatedActorManagement.h"
#include "FortControllerComponent_MarkActorsInRadius.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_MarkActorsInRadius : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_MarkActorsInRadius")
	FScalableFloat bClampIndicatorToScreen;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_MarkActorsInRadius")
	FGameplayTagQuery AITagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_MarkActorsInRadius")
	FGameplayTagContainer VendettaAITags;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_MarkActorsInRadius", meta=(ClampMin="0.0"))
	FScalableFloat AIIndicatorRadius;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_MarkActorsInRadius", meta=(ClampMin="0.0"))
	FScalableFloat AIIndicatorHalfHeight;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_MarkActorsInRadius")
	FVector IndicatorOffset;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_MarkActorsInRadius")
	EIndicatorStateImage MarkedAIIndicatorImageType;

};

