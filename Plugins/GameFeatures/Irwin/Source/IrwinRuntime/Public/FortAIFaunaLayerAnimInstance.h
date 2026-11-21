// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortAIFaunaLayerAnimInstance.generated.h"

class UAnimInstance;

UCLASS(NonTransient, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaLayerAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAIFaunaLayerAnimInstance")
	TObjectPtr<UAnimInstance> MainAnimBP;

};

