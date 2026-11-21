// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortServerBrowser.h"
#include "FortServerBrowserCreative.generated.h"

class UFortServerBrowserActionData;

UCLASS(Abstract)
class UFortServerBrowserCreative : public UFortServerBrowser
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Listview Navigation")
	TSoftObjectPtr<UFortServerBrowserActionData> DefaultActionIfDiscoveryDisabled;

};

