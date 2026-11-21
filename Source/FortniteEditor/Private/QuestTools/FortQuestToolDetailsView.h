// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PropertyViewBase.h"
#include "FortQuestToolDetailsView.generated.h"

USTRUCT(BlueprintType)
struct FFortQuestToolNameSetContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortQuestToolNameSetContainer")
	TSet<FName> NameList;

};

UCLASS()
class FORTNITEEDITOR_API UFortQuestToolDetailsView : public UPropertyViewBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RebuildDetailsViewPanel();

	UFUNCTION(BlueprintCallable, Category="Fort Quest View")
	void SetObjectiveIndexToShow(const int32 InObjectiveIndexToShow);

	UFUNCTION(BlueprintCallable, Category="Fort Quest View")
	void SetObjectiveStatsIndexToShow(const int32 InObjectiveIndexToShow, const int32 InObjectiveStatsIndexToShow);

	UPROPERTY(EditAnywhere, Category="View")
	bool bAllowFiltering;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="View")
	bool bAllowFavoriteSystem;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="View", meta=(EditCondition="bAllowFiltering"))
	bool bShowModifiedPropertiesOption;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="View", meta=(EditCondition="bAllowFiltering"))
	bool bShowKeyablePropertiesOption;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="View", meta=(EditCondition="bAllowFiltering"))
	bool bShowAnimatedPropertiesOption;

	UPROPERTY(EditAnywhere, Category="View")
	float ColumnWidth;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="View")
	bool bShowScrollBar;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="View")
	bool bForceHiddenPropertyVisibility;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="View")
	FName ViewIdentifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="View")
	TArray<FName> CategoriesToShow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="View")
	TArray<FName> PropertiesToShow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="View")
	TArray<FName> PropertiesToExclude;

	UPROPERTY(EditAnywhere, Category="Fort Quest View")
	TMap<FName, FFortQuestToolNameSetContainer> ExcludeNamesInStruct;

	UPROPERTY(EditAnywhere, Category="Fort Quest View")
	TMap<FName, FFortQuestToolNameSetContainer> IncludedNamesInStruct;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort Quest View")
	TArray<FName> ObjectivePropertiesToShow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fort Quest View")
	TArray<FName> ObjectiveStatPropertiesToShow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Fort Quest View")
	int32 ObjectiveIndexToShow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Fort Quest View")
	int32 ObjectiveStatIndexToShow;

	UPROPERTY(EditAnywhere, Category="Fort Quest View")
	bool bShowObjectivesPropertyButtons;

	UPROPERTY(EditAnywhere, Category="Fort Quest View")
	bool bForceHideObjectivesResetToDefaultButton;

	UPROPERTY(EditAnywhere, Category="Fort Quest View")
	bool bShowInlineObjectiveStatsPropertyButtons;

	UPROPERTY(EditAnywhere, Category="Fort Quest View")
	bool bForceHideInlineObjectiveStatsResetToDefaultButton;

private:
	UPROPERTY()
	bool bShowOnlyAllowed;

};

