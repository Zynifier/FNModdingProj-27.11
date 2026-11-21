// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortChoiceData.h"
#include "FortUserWidget.h"
#include "FortUserChoiceWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortUserChoiceWidget : public UFortUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetChoices(const FChoiceData& ChoiceItems);

};

