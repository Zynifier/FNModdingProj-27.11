// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionListEntry.h"
#include "AthenaCollectionListEntryFishing.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionListEntryFishing : public UAthenaCollectionListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Normalized Length Set"))
	void BP_OnNormalizedLengthSet(float NormalizedLength, float NormalizedMinLength, float NormalizedMaxLength);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Star Rating Set"))
	void BP_OnStarRatingSet(int32 StarRating);

private:
	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Item Icon"))
	FName ParamName_ItemIcon;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Is Discovered"))
	FName ParamName_IsDiscovered;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Item Size"))
	FName ParamName_ItemSize;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Has 2 Stars"))
	FName ParamName_Has2Stars;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Has 3 Stars"))
	FName ParamName_Has3Stars;

};

