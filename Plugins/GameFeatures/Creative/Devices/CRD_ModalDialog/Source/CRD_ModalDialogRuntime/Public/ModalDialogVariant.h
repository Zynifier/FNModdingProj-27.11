// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ModalDialogVariant.generated.h"

class UWidgetAnimation;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UModalDialogVariant : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResponseAnimationFinished);

public:
	UFUNCTION(BlueprintCallable)
	void AttemptToPlayOpenAnimation();

	UFUNCTION(BlueprintCallable)
	void AttemptToPlayResponseAnimation();

	UFUNCTION(BlueprintPure)
	bool HasResponseAnimation() const;

private:
	UFUNCTION()
	void HandleResponseAnimationFinished();

	UPROPERTY(BlueprintReadOnly, Transient, Category="ModalDialogVariant", meta=(AllowPrivateAccess="TRUE", BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> BoundAnim_Open;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ModalDialogVariant", meta=(AllowPrivateAccess="TRUE", BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> BoundAnim_Response;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(AllowPrivateAccess="TRUE", DisplayName="On Response Animation Finished"))
	FOnResponseAnimationFinished OnResponseAnimationFinished;

};

