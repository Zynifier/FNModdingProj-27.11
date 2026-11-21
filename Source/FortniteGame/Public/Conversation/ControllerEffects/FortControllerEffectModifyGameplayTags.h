// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/ControllerEffects/FortControllerEffect.h"
#include "FortControllerEffectModifyGameplayTags.generated.h"

USTRUCT(BlueprintType)
struct FTagModificationRequest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FGameplayTagContainer TagsToModify;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	bool bAddTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float Delay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(EditCondition="bAddTag"))
	float FiniteLifetime;

};

UCLASS(meta=(DisplayName="Effect: Modify Actor Gameplay Tags"))
class UFortControllerEffect_ModifyGameplayTags : public UFortControllerEffect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FTagModificationRequest TagModificationRequest;

};

