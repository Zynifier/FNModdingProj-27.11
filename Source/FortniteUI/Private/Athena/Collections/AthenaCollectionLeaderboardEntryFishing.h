// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionLeaderboardEntry.h"
#include "AthenaCollectionLeaderboardEntryFishing.generated.h"

class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionLeaderboardEntryFishing : public UAthenaCollectionLeaderboardEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Star Rating Set"))
	void BP_OnStarRatingSet(int32 StarRating);

private:
	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Has 2 Stars"))
	FName ParamName_Has2Stars;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Has 3 Stars"))
	FName ParamName_Has3Stars;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Stars;

};

