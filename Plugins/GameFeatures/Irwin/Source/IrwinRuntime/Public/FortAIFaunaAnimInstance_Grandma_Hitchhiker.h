// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance_Grandma.h"
#include "FortAIFaunaAnimInstance_Grandma_Hitchhiker.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Grandma_Hitchhiker : public UFortAIFaunaAnimInstance_Grandma
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma Hitchhiker Conditions")
	bool bIsHitchhiked;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grandma Hitchhiker Conditions")
	bool bIsGrandmaSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grandma Magic Numbers")
	float SprintCheckSpeed;

};

