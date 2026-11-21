// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance_Burt.h"
#include "FortAIFaunaAnimInstance_Burt_Hitchhiker.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Burt_Hitchhiker : public UFortAIFaunaAnimInstance_Burt
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Floating Conditions")
	bool IsFloating;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Floating Conditions")
	bool IsInTractorBeam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Burt Hitchhiker Conditions")
	bool IsHitchhiked;

};

