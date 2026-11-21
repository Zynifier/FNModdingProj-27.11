// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPersistentTabObject.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPersistentTabObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTabDestroyed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabEntered();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabExited();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabInitialized();

};

