// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTabInterface.generated.h"

class UObject;

UINTERFACE(MinimalAPI)
class UFortTabInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IFortTabInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	bool OnShouldCreateTab(bool& bOutShouldCreateTab, const UObject* WorldContextObject) const;

};

