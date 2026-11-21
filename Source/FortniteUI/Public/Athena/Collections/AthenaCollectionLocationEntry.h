// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionOverlayEntry.h"
#include "AthenaCollectionLocationEntry.generated.h"

enum class ELocationEntryState : uint8;

UENUM(BlueprintType)
enum class ELocationEntryState : uint8
{
	Found = 0,
	NotFound = 1,
	Unused = 2,
};

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaCollectionLocationEntry : public UAthenaCollectionOverlayEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Location Set"))
	void BP_OnLocationsFoundSet(ELocationEntryState EntryState);

};

