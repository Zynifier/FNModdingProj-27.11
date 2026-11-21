// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "Layout/Margin.h"
#include "FortEventScreenListView.generated.h"

class UCurveFloat;
class UFortEventRewardTracksWidget;
class UFortEventScreenData;
class UFortEventSpacerWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventScreenProgressBarAnimationEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventScreenResourcePreviewOffsetAnimationEvent, const FMargin&, Margin);

UCLASS(meta=(DisableNativeTick, EntryClass="FortEventListViewWidgetBase"))
class UEventScreenListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UEventScreenListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void SetNativeTickAllowed(const bool bAllowed);

	UPROPERTY(BlueprintAssignable, Category="Events")
	FEventScreenProgressBarAnimationEvent OnProgressBarAnimationStartedEvent;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FEventScreenProgressBarAnimationEvent OnProgressBarAnimationCompletedEvent;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FEventScreenProgressBarAnimationEvent OnProgressBarAnimationInterruptedEvent;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FEventScreenResourcePreviewOffsetAnimationEvent OnResourcePreviewOffsetAnimationEvent;

protected:
	UFUNCTION(BlueprintPure)
	const UFortEventScreenData* GetEventScreenData() const;

private:
	UPROPERTY(EditAnywhere, Category="List Entries")
	TSubclassOf<UFortEventRewardTracksWidget> RewardTrackWidgetClass;

	UPROPERTY(EditAnywhere, Category="List Entries")
	TSubclassOf<UFortEventSpacerWidget> SpacerWidgetClass;

	UPROPERTY(EditAnywhere, Category="List Entries")
	float EntrySpacing;

	UPROPERTY(EditAnywhere, Category="List Entries")
	bool bCenterSelection;

	UPROPERTY(EditAnywhere, Category="List Entries", meta=(EditCondition="bCenterSelection"))
	float MaxItemsInView;

	UPROPERTY(EditAnywhere, Category="Mode")
	bool bPreviewMode;

	UPROPERTY(EditAnywhere, Category="Animation")
	TObjectPtr<UCurveFloat> ProgressAnimationCurve;

	UPROPERTY(EditAnywhere, Category="Animation")
	bool bCanAnimateOnceComplete;

};

