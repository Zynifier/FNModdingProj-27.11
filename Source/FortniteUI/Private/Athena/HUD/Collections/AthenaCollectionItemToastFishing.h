// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/Collections/AthenaCollectionItemToast.h"
#include "AthenaCollectionItemToastFishing.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionItemToastFishing : public UAthenaCollectionItemToast
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Normalized Length Set"))
	void BP_OnNormalizedLengthSet(float NormalizedLength, float NormalizedMinLength, float NormalizedMaxLength);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Rank Set"))
	void BP_OnRankSet(int32 Rank, int32 NumEntries);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Star Rating Set"))
	void BP_OnStarRatingSet(int32 StarRating);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Unlocked New Clue"))
	void BP_OnUnlockedNewClue();

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMin="0.010000", DisplayName="Length"))
	float DesignTime_Length;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayName="Normalized Length"))
	float DesignTime_NormalizedLength;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayName="Normalized Min Length"))
	float DesignTime_NormalizedMinLength;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayName="Normalized Max Length"))
	float DesignTime_NormalizedMaxLength;
#endif

	UPROPERTY(EditAnywhere, Category="AthenaCollectionItemToastFishing")
	FText LengthFormat;

	UPROPERTY(EditAnywhere, Category="AthenaCollectionItemToastFishing")
	FText LeaderLengthFormat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Length;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LeaderName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_LeaderLength;

};

