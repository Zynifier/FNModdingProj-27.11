// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/FortMultiPropertyView.h"
#include "FortQuestToolPropertyView.generated.h"

UCLASS()
class UFortQuestToolPropertyView : public UFortMultiPropertyView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Quest View")
	void SetObjectiveFiltersIndexToShow(const int32 InObjectiveIndexToShow, const int32 InObjectiveFiltersIndexToShow);

	UFUNCTION(BlueprintCallable, Category="Fort Quest View")
	void SetObjectiveIndexToShow(const int32 InObjectiveIndexToShow);

	UFUNCTION(BlueprintCallable, Category="Fort Quest View")
	void SetObjectiveStatsIndexToShow(const int32 InObjectiveIndexToShow, const int32 InObjectiveStatsIndexToShow);

protected:
	UPROPERTY(EditAnywhere, Category="Fort Quest View")
	TArray<FName> ObjectivePropertiesToShow;

	UPROPERTY(EditAnywhere, Category="Fort Quest View")
	TArray<FName> ObjectiveStatPropertiesToShow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Fort Quest View")
	int32 ObjectiveIndexToShow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Fort Quest View")
	int32 ObjectiveStatIndexToShow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Fort Quest View")
	int32 ObjectiveFilterIndexToShow;

};

