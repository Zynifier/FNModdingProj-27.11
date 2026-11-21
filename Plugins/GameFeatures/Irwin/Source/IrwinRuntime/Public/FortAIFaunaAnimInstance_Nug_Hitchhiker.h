// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance_Nug.h"
#include "FortAIFaunaAnimInstance_Nug_Hitchhiker.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Nug_Hitchhiker : public UFortAIFaunaAnimInstance_Nug
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Movement Conditions")
	bool bIsSwimming;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Nug Hitchhiked Conditions")
	bool bIsHitchhiked;

};

