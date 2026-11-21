// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaMatchReadyDesktopPopup.generated.h"

UCLASS()
class UAthenaMatchReadyDesktopPopup : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaMatchReadyDesktopPopup(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Game")
	void UserDismissedDialog(bool bBringToFront);

};

