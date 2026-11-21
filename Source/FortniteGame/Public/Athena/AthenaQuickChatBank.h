// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Athena/AthenaQuickChatActiveEntry.h"
#include "AthenaQuickChatBank.generated.h"

UCLASS(MinimalAPI)
class UAthenaQuickChatBank : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaChat")
	TArray<FAthenaQuickChatLeafEntry> ChatOptions;

};

