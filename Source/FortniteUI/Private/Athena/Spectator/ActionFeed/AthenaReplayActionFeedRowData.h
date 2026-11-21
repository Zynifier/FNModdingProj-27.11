// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Replay/FortReplayTypes.h"
#include "AthenaReplayActionFeedRowData.generated.h"

UCLASS()
class UAthenaReplayActionFeedRowProxyInstance : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaReplayActionFeedRowProxyInstance")
	FReplayEliminationEventInfo RowData;

};

