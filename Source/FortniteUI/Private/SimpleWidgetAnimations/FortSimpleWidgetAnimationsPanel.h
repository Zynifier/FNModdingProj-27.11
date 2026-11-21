// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "SimpleWidgetAnimations/FortSimpleWidgetAnimations.h"
#include "FortSimpleWidgetAnimationsPanel.generated.h"

UCLASS(BlueprintType, meta=(DisableNativeTick))
class UFortSimpleWidgetAnimationsPanel : public UContentWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnimationsFinished, FName, Name);

public:
	UFUNCTION(BlueprintCallable)
	bool PlayAnimationByName(const FName& Name, const float Speed = 1.000000f);

	UFUNCTION(BlueprintCallable)
	void ResetAllAnimations();

	UFUNCTION(BlueprintCallable)
	bool ResetAnimationByName(const FName& Name);

	UFUNCTION(BlueprintCallable)
	void StopAllAnimations();

	UFUNCTION(BlueprintCallable)
	bool StopAnimationByName(const FName& Name);

	UPROPERTY(BlueprintAssignable)
	FOnAnimationsFinished OnAnimationsFinished;

private:
	UFUNCTION()
	void ForwardOnAnimationsFinished(FName Name);

	UPROPERTY(EditAnywhere, Category="Anmimations")
	TArray<FFortSimpleWidgetAnimations> Animations;

};

