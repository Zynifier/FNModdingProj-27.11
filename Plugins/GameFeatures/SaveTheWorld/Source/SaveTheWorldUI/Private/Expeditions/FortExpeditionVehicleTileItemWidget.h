// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortExpeditionVehicleTileItemWidget.generated.h"

class UObject;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortExpeditionVehicleTileItemWidget : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Item Management|Tile")
	TWeakObjectPtr<UObject> SquadId;

};

