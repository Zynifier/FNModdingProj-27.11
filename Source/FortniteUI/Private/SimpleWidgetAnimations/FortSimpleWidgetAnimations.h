// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSimpleWidgetAnimations.generated.h"

class UCurveFloat;
class UCurveVector;
class UWorld;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSimpleWidgetAnimationsFinished, FName, Name);

USTRUCT(BlueprintType)
struct FFortSimpleWidgetAnimation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimation")
	FName TargetName;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimation", meta=(EditCondition="bShouldAnimateTranslation", ShowOnlyInnerProperties))
	TObjectPtr<UCurveVector> Translation;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimation", meta=(EditCondition="bShouldAnimateScale", ShowOnlyInnerProperties))
	TObjectPtr<UCurveVector> Scale;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimation", meta=(EditCondition="bShouldAnimateAlpha", ShowOnlyInnerProperties))
	TObjectPtr<UCurveFloat> Alpha;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimation")
	bool bResetOnFinish;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimation", meta=(InlineEditConditionToggle))
	bool bShouldAnimateTranslation;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimation", meta=(InlineEditConditionToggle))
	bool bShouldAnimateScale;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimation", meta=(InlineEditConditionToggle))
	bool bShouldAnimateAlpha;

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<UWorld> WeakWorld;

};

USTRUCT(BlueprintType)
struct FFortSimpleWidgetAnimations
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimations")
	FName Name;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimations")
	bool bIsEnabled;

	UPROPERTY(EditAnywhere, Category="FortSimpleWidgetAnimations", meta=(TitleProperty="TargetName"))
	TArray<FFortSimpleWidgetAnimation> Targets;

	UPROPERTY(BlueprintAssignable)
	FOnSimpleWidgetAnimationsFinished OnAnimationsFinished;

};

