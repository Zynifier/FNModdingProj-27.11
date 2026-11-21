// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/Interface/FortAttributeFuelInterface.h"
#include "FortGliderPackSet.generated.h"

UCLASS(BlueprintType)
class UFortGliderPackSet : public UFortAttributeSet, public IFortAttributeFuelInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="IntelPack")
	FFortGameplayAttributeData MaxCharges;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="IntelPack")
	FFortGameplayAttributeData CurrentCharges;

};

