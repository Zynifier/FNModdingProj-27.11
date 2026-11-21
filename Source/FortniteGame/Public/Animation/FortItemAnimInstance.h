// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortBaseAnimInstance.h"
#include "FortGender.h"
#include "FortItemAnimInstance.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortItemAnimInstance : public UFortBaseAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Item")
	TEnumAsByte<EFortCustomGender::Type> Gender;

};

