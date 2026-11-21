// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/FortTabButton.h"
#include "FortActivityBrowserTabButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortActivityBrowserTabButton : public UFortTabButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFavoriteChanged(bool bIsFavorite);

};

