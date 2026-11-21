// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subscriptions/FortSubscriptionPlatformModal.h"
#include "FortSubscriptionCancellationModal.generated.h"

class UCommonButtonLegacy;
enum class ESubscriptionCancellability : uint8;

UENUM(BlueprintType)
enum class ESubscriptionCancellability : uint8
{
	/** No direct way to cancel. we just have to show instructions how to do it manually with the platform. */
	NotCancellable = 0,
	/** If the user is on the platform they subscribed on, we can directly cancel; otherwise we will show the info to "get back to the original platform */
	CancellabeOnPlatform = 1,
	/** The user can cancel regardless of which platform they are currently on */
	CancellableAnywhere = 2,
};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortSubscriptionCancellationModal : public UFortSubscriptionPlatformModal
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	ESubscriptionCancellability GetSubscriptionCancellabillity() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void AddDynamicBulletPoints(const TArray<FText>& BulletPointTexts);

	UFUNCTION(BlueprintImplementableEvent)
	void ClearDynamicBulletPoints();

	UFUNCTION(BlueprintImplementableEvent)
	void ClearErrorStateBulletPoints();

	UFUNCTION(BlueprintImplementableEvent)
	void HideSpinner();

	UFUNCTION(BlueprintImplementableEvent)
	void OnModalCancellationBackout();

	UFUNCTION(BlueprintImplementableEvent)
	void SetErrorStateBulletPoints(const TArray<FText>& BulletPointTexts);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowSpinner();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCancelDisplay(bool bCanCancelDirectly);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSubscriptionCancellationModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CancelSubscription;

};

