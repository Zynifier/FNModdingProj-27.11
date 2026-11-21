// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortAthenaTutorialBaseInteraction.generated.h"

UCLASS(meta=(DisableNativeTick))
class UFortAthenaTutorialBaseInteraction : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaTutorialBaseInteraction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

