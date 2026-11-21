// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "FortButtonInternalWidget.generated.h"

UCLASS()
class UFortButtonInternalWidget : public UButton
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interaction")
	bool IsClickable;

};

