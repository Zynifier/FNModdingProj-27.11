// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIStateRelay.generated.h"

class UUIStateComponent;
class UUIStateComponentConfiguration;

USTRUCT()
struct UICHART_API FUIStateRelayBaton
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UUIStateComponent> OfferingComponent;

	UPROPERTY()
	TSubclassOf<UUIStateComponent> OfferingComponentType;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateComponentConfiguration> OfferingComponentConfiguration;

};

USTRUCT()
struct UICHART_API FUIStateRelay
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FUIStateRelayBaton> AvailableBatons;

	UPROPERTY()
	TArray<FUIStateRelayBaton> ClaimedBatons;

};

