// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaTeamAliveCountBase.generated.h"

USTRUCT(BlueprintType)
struct FAthenaTeamCountSlotData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaTeamCountSlotData")
	FText TeamNameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaTeamCountSlotData")
	FText TeamCountText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaTeamCountSlotData")
	bool bIsMyTeam;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaTeamAliveCountBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetTeamSlotData(int32 TeamIdx, const FAthenaTeamCountSlotData& TeamSlotData);

};

