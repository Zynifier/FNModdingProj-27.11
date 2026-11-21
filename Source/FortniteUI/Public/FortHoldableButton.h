// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortHoldableButton.generated.h"

class UCommonTextStyle;

UCLASS(Abstract)
class FORTNITEUI_API UFortHoldableButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Common ButtonStyle|Getters")
	UCommonTextStyle* GetHoldPromptTextStyle() const;

	UFUNCTION(BlueprintPure)
	bool GetIsHoldRequired() const;

	UFUNCTION(BlueprintCallable)
	void SetEnableButtonHold(const bool bInEnableButtonHold);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnActionProgressDecreased(const float HoldPercentage);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnActionProgressIncreased(const float HoldPercentage);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHoldCompleted();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHoldDecreased(const float HoldPercentage);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHoldEnded(const float HoldPercentage, const bool bInUseSecondaryHoldAnimation);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHoldIncreased(const float HoldPercentage);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHoldReset();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHoldStarted(const float HoldPercentage, const bool bInUseSecondaryHoldAnimation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHoldRequiredChanged(bool bHoldRequired);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoldableButton")
	bool bIsHoldableButton;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoldableButton")
	bool bBindHoldToAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoldableButton", meta=(EditCondition="bIsHoldableButton"))
	bool bIgnoreLongPress;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoldableButton", meta=(EditCondition="bIsHoldableButton && bBindHoldToAction && QualifyingHoldTime == 0.0 && StartingHoldPercentage == 0.0"))
	bool bKeybindingTriggersHoldEvents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoldableButton", meta=(ClampMin="0.0", EditCondition="bIsHoldableButton", UIMin="0.0"))
	float HoldTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoldableButton", meta=(ClampMax="1.0", ClampMin="0.0", EditCondition="bIsHoldableButton", UIMax="1.0", UIMin="0.0"))
	float StartingHoldPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoldableButton", meta=(ClampMin="0.0", EditCondition="bIsHoldableButton", UIMin="0.0"))
	float QualifyingHoldTime;

	UPROPERTY(BlueprintReadOnly, Category="FortHoldableButton")
	bool bHoldCancelledFromMovement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	TSubclassOf<UCommonTextStyle> HoldPromptTextStyle;

};

