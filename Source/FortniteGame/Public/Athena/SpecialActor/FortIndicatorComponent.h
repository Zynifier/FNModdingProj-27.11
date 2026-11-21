// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "FortIndicatorComponent.generated.h"

class IFortActorIndicatorInterface;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Mobility", "VirtualTexture", "Trigger"))
class UFortIndicatorComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnIndicatorRegistered(const TScriptInterface<IFortActorIndicatorInterface>& NewIndicator);

};

