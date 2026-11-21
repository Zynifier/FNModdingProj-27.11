// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "AthenaSpectatorPlayerListEntryWidget.generated.h"

class UAthenaSpectatorPlayerListRowData;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpectatorPlayerListEntryWidget : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Player List")
	void OnEntryDataSet();

	UPROPERTY(BlueprintReadWrite, Category="Player List")
	TObjectPtr<UAthenaSpectatorPlayerListRowData> PlayerListRowData;

};

