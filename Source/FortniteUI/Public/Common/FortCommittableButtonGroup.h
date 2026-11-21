// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Groups/CommonButtonGroupLegacy.h"
#include "FortCommittableButtonGroup.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortCommittableButtonGroup : public UCommonButtonGroupLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FSimpleButtonGroupDelegate OnButtonCommitted;

};

