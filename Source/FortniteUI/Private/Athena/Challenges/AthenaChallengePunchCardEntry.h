// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ChallengeBundles/FortChallengeSetStyle.h"
#include "AthenaChallengePunchCardEntry.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortLazyImage;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengePunchCardEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnFinishedPlacingEntry();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlacedEntry();

	UFUNCTION(BlueprintImplementableEvent)
	void SetIsFirstSlot();

	UFUNCTION(BlueprintImplementableEvent)
	void SetIsLastSlot();

	UFUNCTION(BlueprintImplementableEvent)
	void SetIsNonsequentialSlot();

	UFUNCTION(BlueprintImplementableEvent)
	void SetStyle(const FFortChallengePunchCardStyles& PunchStyle);

	UFUNCTION(BlueprintImplementableEvent)
	void SetToDefaultSlot();

protected:
	UPROPERTY(EditAnywhere, Category="AthenaChallengePunchCardEntry")
	FName IconParamName;

	UPROPERTY(EditAnywhere, Category="AthenaChallengePunchCardEntry")
	int32 SlotIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaChallengePunchCardEntry")
	bool bIsBeingPlaced;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardQuantity;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_UnlockDate;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengePunchCardEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_Stamp;

};

