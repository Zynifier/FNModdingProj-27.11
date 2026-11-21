// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTileView.h"
#include "FortActivityTileView.generated.h"

UCLASS(meta=(EntryClass="FortActivityTileViewTileBase"))
class UFortActivityTileView : public UCommonTileView
{
	GENERATED_BODY()

public:
	UFortActivityTileView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void NavigateToTop();

	UFUNCTION(BlueprintCallable)
	void RespondToVisibilityChange(bool bIsVisible);

	UFUNCTION(BlueprintCallable)
	void SetListenForMouseWheelInput(bool bListenForInput);

};

