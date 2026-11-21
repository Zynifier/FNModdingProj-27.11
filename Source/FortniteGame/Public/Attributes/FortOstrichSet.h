// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortOstrichSet.generated.h"

UCLASS(BlueprintType)
class UFortOstrichSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="Ostrich", meta=(HideFromModifiers))
	FFortGameplayAttributeData WalkSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Ostrich", meta=(HideFromModifiers))
	FFortGameplayAttributeData SprintSpeed;

};

