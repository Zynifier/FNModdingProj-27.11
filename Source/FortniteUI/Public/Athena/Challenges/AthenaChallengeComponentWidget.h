// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaChallengeComponentWidget.generated.h"

UCLASS(Abstract, BlueprintType)
class UAthenaChallengeComponentWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeComponentWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

