// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortServerBrowserActionData.h"
#include "FortServerBrowserActionDataPopup.generated.h"

class UCommonActivatableWidget;

UCLASS(BlueprintType)
class UFortServerBrowserActionDataPopup : public UFortServerBrowserActionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortServerBrowserActionDataPopup")
	TSoftClassPtr<UCommonActivatableWidget> PopupClass;

};

