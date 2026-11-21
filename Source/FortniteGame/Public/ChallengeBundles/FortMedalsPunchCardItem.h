// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortMedalsPunchCardItem.generated.h"

class UFortAccoladeItemDefinition;

USTRUCT(BlueprintType)
struct FCardSlotMedalData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAccoladeItemDefinition> AccoladeForSlot;

	UPROPERTY()
	int32 SlotIndex;

	UPROPERTY()
	bool bLoadedFromMcp;

	UPROPERTY()
	bool bPunched;

};

UCLASS(BlueprintType)
class UFortMedalsPunchCardItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FString> medal_punch_list;

	UPROPERTY()
	TArray<FCardSlotMedalData> MedalPunchData;

	UPROPERTY(BlueprintReadOnly, Category="FortMedalsPunchCardItem", meta=(AllowPrivateAccess="TRUE"))
	int32 days_since_season_start_grant;

};

