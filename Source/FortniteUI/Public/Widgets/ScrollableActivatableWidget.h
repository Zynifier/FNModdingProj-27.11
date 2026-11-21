// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ScrollableActivatableWidget.generated.h"

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API UScrollableActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsFullscreen() const;

	UFUNCTION(BlueprintCallable)
	void TransitionToFullscreen(const bool bIsFullscreen);

};

