// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortEventItemDefinitionBase.h"
#include "LobbyBackgroundTakeoverEvent.generated.h"

class UWorld;

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level"))
class ULobbyBackgroundTakeoverEvent : public UFortEventItemDefinitionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LobbyBackgroundTakeoverEvent")
	TSoftObjectPtr<UWorld> StwLobbyBackgroundLevelName;

	UPROPERTY(EditAnywhere, Category="LobbyBackgroundTakeoverEvent")
	TSoftObjectPtr<UWorld> AthenaLobbyBackgroundLevelName;

};

